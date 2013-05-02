<?php
/**
 * @file
 *  Admin settings page and checked nodes summary table
 */

function disable_breadcrumbs_settings_page() {

  $output = drupal_get_form('disable_breadcrumbs_settings_form');
  $output .= theme('disable_breadcrumbs_checked_nodes');

  return $output;
}

/**
 * Implementation of hook_form().
 * Settings/configuration form.
 */
function disable_breadcrumbs_settings_form() {

  $disable_breadcrumbs_all = variable_get('disable_breadcrumbs_all', NULL);

  if ($disable_breadcrumbs_all) {
    drupal_set_message(t("All breadcrumbs are currently disabled"), 'warning');
  }
  

  $content_types = array_map('check_plain', node_get_types('names'));

  $form['node_types'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content type settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['node_types']['disable_breadcrumbs_node_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Content types that Disable breadcrumbs can be used on'),
    '#options' => $content_types,
    '#default_value' => variable_get('disable_breadcrumbs_node_types', array()),
    '#multiple' => TRUE,
  );
  $form['node_types']['disable_breadcrumbs_node_types_all'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Content types that you want to disable all breadcrumbs for'),
    '#options' => $content_types,
    '#default_value' => variable_get('disable_breadcrumbs_node_types_all', array()),
    '#multiple' => TRUE,
  );
  $form['disable_all'] = array(
    '#type' => 'fieldset',
    '#title' => t('ALL Breadcrumbs'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['disable_all']['disable_breadcrumbs_all'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable') . ' <b>' . t('ALL') . '</b> ' . t('breadcrumbs'),
    '#description' => t('This will disable all breadcrumbs on your site, regardless of entity type or page callback.'),
    '#default_value' => variable_get('disable_breadcrumbs_all', NULL),
  );
  $form['reset_breadcrumbs'] = array(
    '#type' => 'fieldset',
  );
  $form['reset_breadcrumbs']['button'] = array(
    '#type' => 'submit',
    '#value' => t("Reset breadcrumbs"),
    '#prefix' => '<div id="reset-breadcrumbs">',
    '#suffix' => '</div>',
    '#submit' => array('disable_breadcrumbs_settings_form_delete_all_submit'),
    '#attributes' => array(
      'id' => 'reset-breadcrumbs',
      'onclick' => 'return confirm("Are you sure you want to clear the disable_breadcrumbs database table?")',
    ),
  );
  $form['reset_breadcrumbs']['markup'] = array(
    '#value' => '(<em>'. t('reset disable_breadcrumbs database table - all disabled breadcrumbs on nodes will be removed.') .'</em>)',
  );

  $form['#redirect'] = FALSE;

  return system_settings_form($form);
}

/**
 * Removes all entries in disable_breadcrumbs table.
 */
function disable_breadcrumbs_settings_form_delete_all_submit($form, &$form_state) {
  db_query("DELETE FROM {disable_breadcrumbs}");
  drupal_set_message(t("disable_breadcrumbs table has been cleared."));
}

/**
 * Implementation of hook_theme().
 */
function disable_breadcrumbs_theme() {
    return array(
    'disable_breadcrumbs_checked_nodes' => array(
      'arguments' => NULL,
    ),
  );
}

/**
 * Produce sortable table of currently checked nodes
 */
function theme_disable_breadcrumbs_checked_nodes() {
  $headers = array(
    array(
      'data' => 'Node (nid)',
      'field' => 'nid',
      'sort' => 'desc',
      ), 
    array(
      'data' => 'Type',
      'field' => 'type',
      ),
    array(
      'data' => 'Title',
      'field' => 'title',
      ), 
  "");
  $query = "SELECT n.nid, n.type, n.title from {node} n 
  INNER JOIN {disable_breadcrumbs} db ON n.nid = db.nid";
  $query .= tablesort_sql($headers);
  $result = db_query($query);
  $rows = array();
  while ($row = db_fetch_array($result)) {
    $rows[$row['nid']] = $row;
    //Replace title in $row array with below linked version.
    $rows[$row['nid']]['title'] = l($rows[$row['nid']]['title'], 'node/'. $rows[$row['nid']]['nid']);
    //Append edit link to array of table cells.
    $rows[$row['nid']]['edit'] = '<a href="'. base_path() . 'node/'. $row['nid'] .'/edit'.'">Edit</a>';
  }

  $output = '<h2>'. t("Nodes currently checked") .'</h2>';
  $output .= theme('table', $headers, $rows);

  return $output;
}
