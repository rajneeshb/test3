<?php

  drupal_add_js( drupal_get_path('theme', 'avtstore') . '/js/order.shared.js', 'theme');

  // We already did a lot of work in a module to style the add form, fall back to it
  if ( empty($form['#node']->nid) ) {
    drupal_add_js( drupal_get_path('theme', 'avtstore') . '/js/order.add.js', 'theme');
    echo drupal_render($form);
    return;
  }

  function _my_module_fix_disabled(&$elements) {
    foreach (element_children($elements) as $key) {
      if (isset($elements[$key]) && $elements[$key]) {

        // Recurse through all children elements.
        _my_module_fix_disabled($elements[$key]);
      }
    }

    if (!isset($elements['#attributes'])) {
      $elements['#attributes'] = array();
    }
    $elements['#attributes']['disabled'] = 'disabled';
  }

  setlocale(LC_MONETARY, 'en_US.UTF-8');

  drupal_add_js( drupal_get_path('theme', 'avtstore') . '/js/order.edit.js', 'theme');
  drupal_add_css( drupal_get_path('theme', 'avtstore') . '/css/order-edit.css', 'theme' );

  $payment_methods = array(
      'client_pay' => t('Client selected self pay'),
      'court_pay' => t('Paid for by the court'),
    );

  $author_name = $form['#node']->mail;
  $author_profile =  empty($form['#node']->field_creator[0]['nid']) ?
                        content_profile_load('profile', $form['#node']->uid) :
                        node_load($form['#node']->field_creator[0]['nid']);
  if ( !empty($author_profile) ) {
    $author_name = implode(' ', array($author_profile->field_first_name[0]['value'], $author_profile->field_last_name[0]['value']));
  }

  if ( empty($author_name) ) {
    $author_name = t('Unknown');
  }

  $customer_name = '';
  $customer_profile = content_profile_load('profile', $form['#node']->uid);
  if ( !empty($customer_profile) ) {
    $customer_name = implode(' ', array($customer_profile->field_first_name[0]['value'], $customer_profile->field_last_name[0]['value']));
  }

  $form['author']['name']['#title'] = t('Customer');

  if(!$form['#node']->field_copy_order[0]['value']) {
    _my_module_fix_disabled( $form['group_administration']['field_copy_page_desc'] );
  }

  $custom_form_elements = array();
  $elements = array(
      'confirmation_number' => array(
          'label' => t('Confirmation number'),
          'value' => $form['#node']->nid,
          ),
      'created_date' => array(
          'label' => t('Order created'),
          'value' => format_date($form['#node']->created, 'custom', 'm/d/Y'),
          ),
      'how_to_pay' => array(
          'label' => t('Payment method'),
          'value' => $payment_methods[ $form['group_payment_information']['field_how_to_pay']['#value']['value'] ],
          ),
      'created_by' => array(
          'label' => t('Created by'),
          'permission' => 'edit field_creator',
          'value' => $author_name,
          'edit' => $form['group_administration']['field_creator'],
          ),
      'customer' => array(
          'label' => $form['author']['name']['#title'],
          'permission' => 'save order for another user',
          'value' => $customer_name,
          'edit' => $form['author']['name'],
          ),
      'field_order_number' => array(
          'label' => t('Order number'),
          'permission' => 'edit field_order_number',
          'value' => $form['#node']->field_order_number[0]['value'],
          'edit' => $form['group_administration']['field_order_number'],
          ),
      'field_confidential' => array(
          'label' => t('Order number'),
          'permission' => 'edit field_confidential',
          'value' => $form['#node']->field_confidential[0]['value'],
          'edit' => $form['group_orderrequirements']['field_confidential'],
          ),
      'field_casename' => array(
          'label' => t('Case name'),
          'permission' => 'edit field_casename',
          'value' => $form['#node']->field_casename[0]['value'],
          'edit' => $form['group_header']['field_casename'][0],
          ),
      'field_orderstatus' => array(
          'label' => t('Order status'),
          'permission' => 'edit field_orderstatus',
          'value' => $form['#node']->field_orderstatus[0]['value'],
          'edit' => $form['group_administration']['field_orderstatus'],
          ),
      'field_actual_pages' => array(
          'label' => t('Actual pages'),
          'permission' => 'edit field_actual_pages',
          'value' => intval($form['#node']->field_actual_pages[0]['value']),
          'edit' => $form['group_administration']['field_actual_pages'],
          ),

      'field_estimated_pages' => array(
          'label' => t('Estimated pages'),
          'permission' => 'edit field_estimated_pages',
          'value' => intval($form['#node']->field_estimated_pages[0]['value']),
          'edit' => $form['group_administration']['field_estimated_pages'],
          ),

      'field_copy_order' => array(
          'label' => t('Copy order'),
          'permission' => 'edit field_copy_order',
          'value' => $form['#node']->field_copy_order[0]['value'],
          'edit' => $form['group_administration']['field_copy_order'],
          ),

      'field_copy_page_desc' => array(
          'label' => t('Copy page desc'),
          'permission' => 'edit field_copy_page_desc',
          'value' => $form['#node']->field_copy_page_desc[0]['value'],
          'edit' => $form['group_administration']['field_copy_page_desc'],
          ),

      'field_estimated_cost' => array(
          'label' => t('Estimated cost'),
          'permission' => 'edit field_estimated_cost',
          'value' => money_format('%n', $form['#node']->field_estimated_cost[0]['value']),
          'edit' => $form['group_payment_information']['field_estimated_cost'],
          ),

      'field_actual_cost' => array(
          'label' => t('Actual cost'),
          'permission' => 'edit field_actual_cost',
          'value' => money_format('%n', $form['#node']->field_actual_cost[0]['value']),
          'edit' => $form['group_payment_information']['field_actual_cost'],
          ),

      'field_deposit_required' => array(
          'label' => t('Deposit required'),
          'permission' => 'edit field_deposit_required',
          'value' => check_plain($form['#node']->field_deposit_required[0]['value']),
          'edit' => $form['group_payment_information']['field_deposit_required'],
          ),

      'field_disable_notification' => array(
          'label' => t('Disable Notifications'),
          'permission' => 'edit field_disable_notification',
          'value' => $form['#node']->field_disable_notification[0]['value'],
          'edit' => $form['group_administration']['field_disable_notification'],
          ),

      'field_deposit_paid' => array(
          'label' => t('Deposit paid'),
          'permission' => 'edit field_deposit_paid',
          'value' => money_format('%n', $form['#node']->field_deposit_paid[0]['value']),
          'edit' => $form['group_payment_information']['field_deposit_paid'],
          ),

      'field_balance_paid' => array(
          'label' => t('Additional paid/Refund amount'),
          'permission' => 'edit field_balance_paid',
          'value' => money_format('%n', $form['#node']->field_balance_paid[0]['value']),
          'edit' => $form['group_payment_information']['field_balance_paid'],
          ),

      'deposit due' => array(
          'label' => t('Deposit due'),
          'value' => money_format( '%n', $form['#node']->field_estimated_cost[0]['value']),
          ),

      'amount owed' => array(
          'label' => t('Amount due/Refund owed'),
          'value' =>  _avtstore_orders_calculate_balance_due($form['#node'], TRUE, TRUE),
          ),

      'field_deposit_paid_date' => array(
          'label' => t('Deposit paid date'),
          'permission' => 'edit field_deposit_paid_date',
          'value' => empty($form['#node']->field_balance_paid[0]['value']) ?
                          t('Not paid') :
                          format_date(strtotime($form['#node']->field_deposit_paid_date[0]['value']), 'custom', 'm/d/Y'),
          'edit' =>  $form['group_payment_information']['field_deposit_paid_date'],
          ),
      'field_balance_paid_date' => array(
          'label' => t('Additional paid/Refund date'),
          'permission' => 'edit field_balance_paid_date',
          'value' => empty($form['#node']->field_balance_paid_date[0]['value']) ?
                          t('Not paid') :
                          format_date(strtotime($form['#node']->field_balance_paid_date[0]['value']), 'custom', 'm/d/Y'),
          'edit' =>  $form['group_payment_information']['field_balance_paid_date'],
          ),

      'field_completiondate' => array(
          'label' => t('Completion date'),
          'permission' => 'edit field_completiondate',
          'value' => empty($form['#node']->field_completiondate[0]['value']) ?
                          t('In progress') :
                          format_date(strtotime($form['#node']->field_completiondate[0]['value']), 'custom', 'm/d/Y'),
          'edit' => $form['group_administration']['field_completiondate'],
          ),

      'field_due_date' => array(
          'label' => t('Due Date'),
          'permission' => 'edit field_due_date',
          'value' => empty($form['#node']->field_due_date[0]['value']) ?
                          t('Not set') :
                          format_date(strtotime($form['#node']->field_due_date[0]['value']), 'custom', 'm/d/Y'),
          'edit' => $form['group_administration']['field_due_date'],
          ),
      'taxonomy' => array(
          'label' => $form['taxonomy'][ variable_get('jurisdiction_vid', 3) ]['#title'],
          'permission' => 'edit any order content',
          'value' => $form['taxonomy'][ variable_get('jurisdiction_vid', 3) ]['#default_value'],
          'edit' => $form['taxonomy'][ variable_get('jurisdiction_vid', 3) ],
          ),
  );

  foreach ($elements as $element => $info) {
    if (!empty($info['edit']) ) {
      if ( !empty($info['permission']) ) {
        if ( user_access($info['permission']) ) {
          $custom_form_elements[$element] = $info['edit'];
          continue;
        }
      }
    }

    $info['value'] = empty($info['value']) ? '&nbsp;' : check_plain($info['value']);

    $classes = array('item-value');
    if ( !empty($info['edit']['#id']) ) {
      $classes[] = $info['edit']['#id'] . '-wrapper';
    }
    else {
      $classes[] = $element . '-wrapper';
    }

    $custom_form_elements[$element] = array(
        '#type' => 'item',
        '#title' => $info['label'],
        '#value' => '<div class="' . implode(' ', $classes) . '">' . $info['value'] . '</div>',
      );
  }


  $cleaned_form_array = array();
  $cleaned_form_array['author'] = $form['author'];
  unset($cleaned_form_array['author']['name']);
  foreach ($form as $key => $val) {
    if ( !preg_match('/^(group_|field_|buttons|taxonomy|author)/', $key) ) {
      $cleaned_form_array[$key] = $val;
    }
  }

  ob_start();

?>
  <div class="btn-wrap">
    <button name="op" value="Save" class="fancy-button fancy-button-right fancy-button-small"><span class="fancy-button-start"></span><span class="fancy-button-text-wrap">Save changes</span><span class="fancy-button-end"></span></button>
  </div>

  <fieldset class="case-info">
    <div class="row inline-blocks">
      <?php echo drupal_render( $custom_form_elements['field_disable_notification'] ); ?>
      <?php echo drupal_render( $custom_form_elements['field_confidential'] ); ?>
    </div>
    <legend>Case information</legend>

    <div class="row inline-blocks">
      <?php echo drupal_render( $custom_form_elements['field_order_number'] ); ?>
      <?php echo drupal_render( $custom_form_elements['field_casename'] ); ?>
      <?php echo drupal_render( $custom_form_elements['field_orderstatus'] ); ?>
    </div>

    <div class="row two-column inline-blocks">
      <div class="left-column"><?php echo drupal_render( $form['group_header']['field_case_number'] ); ?></div>
      <div class="right-column"><?php echo drupal_render( $custom_form_elements['customer'] ); ?></div>
    </div class="row">

    <div class="row form-col-field_locationref">
      <?php echo drupal_render($form['group_header']['field_locationref']); ?>
    </div>

    <div class="row">
      <?php echo drupal_render($form['group_header']['group_hearingdates']); ?>
    </div>

    <div class="row two-column inline-blocks">
      <div class="left-column checkbox"><?php echo drupal_render($form['group_header']['field_appealtranscript']); ?></div>
      <div class="right-column"><?php echo drupal_render($form['group_header']['field_appeal_number']); ?></div>
    </div>

  </fieldset>

  <fieldset>
    <legend>Order information</legend>

    <div class="row two-column inline-blocks">
      <div class="left-column"><?php echo drupal_render( $custom_form_elements['confirmation_number'] ); ?></div>
      <div class="right-column">
        <?php echo drupal_render( $custom_form_elements['created_date'] ); ?>
        <?php echo drupal_render( $custom_form_elements['created_by'] ); ?>
      </div>
    </div>

    <div class="row two-column inline-blocks">
      <div class="left-column form-col-field_transcribeextra"><?php echo drupal_render( $form['group_header']['field_transcribeextra'] ); ?></div>
      <div class="right-column"><?php echo drupal_render( $form['group_orderrequirements']['field_turnaroundtime']); ?></div>
    </div>

    <div class="row two-column inline-blocks">
      <div class="left-column"><?php echo drupal_render( $form['group_header']['field_witnesses']); ?></div>
      <div class="right-column"><?php echo drupal_render( $form['group_orderrequirements']['group_formats']); ?></div>
    </div>

    <div class="row two-column inline-blocks">
      <div class="left-column"><?php echo drupal_render( $custom_form_elements['field_due_date'] ); ?></div>
      <div class="right-column"><?php echo drupal_render( $custom_form_elements['field_completiondate'] ); ?></div>
    </div>

    <div class="row two-column inline-blocks">
      <div class="left-column"><?php echo drupal_render( $custom_form_elements['field_estimated_pages'] ); ?></div>
      <div class="right-column"><?php echo drupal_render( $custom_form_elements['field_actual_pages'] ); ?></div>
    </div>

    <div class="row two-column inline-blocks">
      <div class="left-column"><?php echo drupal_render( $custom_form_elements['field_copy_order'] ); ?></div>
      <div class="right-column inline-blocks two-column">
        <div class="left-column"><?php echo drupal_render( $custom_form_elements['field_estimated_cost'] ); ?></div>
        <div class="right-column"><?php echo drupal_render( $custom_form_elements['field_actual_cost'] ); ?></div>
      </div>
    </div>

    <div class="row">
      <?php echo drupal_render( $custom_form_elements['field_copy_page_desc'] ); ?>
    </div>

    <div class="row">
      <?php echo drupal_render( $form['group_administration']['field_associated_parties'] ); ?>
    </div>

  </fieldset>

  <fieldset>
    <legend>Payment information</legend>

    <div class="row two-column inline-blocks">
      <div class="left-column checkbox"><?php echo drupal_render( $custom_form_elements['field_deposit_required'] ); ?></div>
      <div class="right-column"><?php echo drupal_render( $custom_form_elements['how_to_pay'] ); ?></div>
    </div>

    <div class="row two-column inline-blocks">
      <div class="left-column"><?php echo drupal_render( $custom_form_elements['amount owed'] ); ?></div>
    </div>

    <div class="row two-column inline-blocks">
      <div class="left-column"><?php echo drupal_render( $custom_form_elements['field_deposit_paid'] ); ?></div>
      <div class="right-column"><?php echo drupal_render( $custom_form_elements['field_balance_paid'] ); ?></div>
    </div>

    <div class="row two-column inline-blocks">
      <div class="left-column"><?php echo drupal_render( $custom_form_elements['field_deposit_paid_date'] ); ?></div>
      <div class="right-column"><?php echo drupal_render( $custom_form_elements['field_balance_paid_date'] ); ?></div>
    </div>

  </fieldset>

  <fieldset>
    <legend>Additional information</legend>
    <div class="row">
      <?php echo drupal_render( $form['group_orderrequirements']['field_additional_comments'] ); ?>
    </div>
    <div class="row two-column inline-blocks">
      <div class="left-column"><?php echo drupal_render( $custom_form_elements['taxonomy'] ); ?></div>
      <?php if ( user_access('edit field_completed_transcript') ) : ?>
        <div class="right-column"><?php echo drupal_render( $form['group_administration']['field_completed_transcript'] ); ?></div>
      <?php endif; ?>
    </div>
  </fieldset>

  <div class="btn-wrap">
    <button name="op" value="Save" class="fancy-button fancy-button-right fancy-button-small"><span class="fancy-button-start"></span><span class="fancy-button-text-wrap">Save changes</span><span class="fancy-button-end"></span></button>
  </div>
<?php

  $cleaned_form_array['faked_body'] = array( '#type' => 'markup', '#weight' => -100, '#value' => ob_get_contents() );
  ob_end_clean();

  echo drupal_render($cleaned_form_array);
