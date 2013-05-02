<?php
// $Id$

/**
 * @file
 * Contains theme override functions and preprocess functions for the theme.
 *
 * ABOUT THE TEMPLATE.PHP FILE
 *
 *   The template.php file is one of the most useful files when creating or
 *   modifying Drupal themes. You can add new regions for block content, modify
 *   or override Drupal's theme functions, intercept or make additional
 *   variables available to your theme, and create custom PHP logic. For more
 *   information, please visit the Theme Developer's Guide on Drupal.org:
 *   http://drupal.org/theme-guide
 *
 * OVERRIDING THEME FUNCTIONS
 *
 *   The Drupal theme system uses special theme functions to generate HTML
 *   output automatically. Often we wish to customize this HTML output. To do
 *   this, we have to override the theme function. You have to first find the
 *   theme function that generates the output, and then "catch" it and modify it
 *   here. The easiest way to do it is to copy the original function in its
 *   entirety and paste it here, changing the prefix from theme_ to avtstore_.
 *   For example:
 *
 *     original: theme_breadcrumb()
 *     theme override: avtstore_breadcrumb()
 *
 *   where avtstore is the name of your sub-theme. For example, the
 *   zen_classic theme would define a zen_classic_breadcrumb() function.
 *
 *   If you would like to override any of the theme functions used in Zen core,
 *   you should first look at how Zen core implements those functions:
 *     theme_breadcrumbs()      in zen/template.php
 *     theme_menu_item_link()   in zen/template.php
 *     theme_menu_local_tasks() in zen/template.php
 *
 *   For more information, please visit the Theme Developer's Guide on
 *   Drupal.org: http://drupal.org/node/173880
 *
 * CREATE OR MODIFY VARIABLES FOR YOUR THEME
 *
 *   Each tpl.php template file has several variables which hold various pieces
 *   of content. You can modify those variables (or add new ones) before they
 *   are used in the template files by using preprocess functions.
 *
 *   This makes THEME_preprocess_HOOK() functions the most powerful functions
 *   available to themers.
 *
 *   It works by having one preprocess function for each template file or its
 *   derivatives (called template suggestions). For example:
 *     THEME_preprocess_page    alters the variables for page.tpl.php
 *     THEME_preprocess_node    alters the variables for node.tpl.php or
 *                              for node-forum.tpl.php
 *     THEME_preprocess_comment alters the variables for comment.tpl.php
 *     THEME_preprocess_block   alters the variables for block.tpl.php
 *
 *   For more information on preprocess functions and template suggestions,
 *   please visit the Theme Developer's Guide on Drupal.org:
 *   http://drupal.org/node/223440
 *   and http://drupal.org/node/190815#template-suggestions
 */


  drupal_add_css(drupal_get_path('theme','avtstore').'/images/rotate/rotate.php', 'theme', 'all', FALSE);

function avtstore_preprocess_page(&$vars) {
  if ( arg(0) == 'user' ) {
    if ( !is_numeric( arg(1) ) ) {
      unset($vars['tabs']);
    }
    else {
      $vars['tabs'] = preg_replace('/\<li.*?\>\<a href\="\/user\/[\d]+\/edit"\>Edit\<\/a\>\<\/li\>/', '', $vars['tabs']);
      $vars['tabs'] = preg_replace('/\>Profile\<\/a\>/', '>Edit Profile</a>', $vars['tabs']);
    }

    if ( arg(1) == 'password' ) {
      $vars['title'] = t('Change password');
    }
    elseif ( arg(1) == 'login' ) {
      $vars['title'] = t('Sign in');
    }
  }

  if ( user_is_anonymous() && TRUE == $vars['is_front'] ) {
    $vars['template_files'][] = 'page-front-anonymous';
    $vars['title'] = '';
  }

  if ( !empty($vars['node'] ) ) {
    $vars['template_files'][] = 'page-'. str_replace('_', '-', $vars['node']->type);
    if ( 'order' == $vars['node']->type ) {
      unset($vars['tabs']);

      if ( empty($vars['node']->field_order_number[0]['value']) ) {
        $vars['title'] = t('Confirmation number: @order-number', array('@order-number' => $vars['node']->nid) );
      }
      else {
        $vars['title'] = t('Sales order number: @order-number', array('@order-number' => $vars['node']->field_order_number[0]['value']) );
      }
    }
  }
}

function avtstore_preprocess_node(&$vars) {
    $vars['template_files'][] = 'node-' . $vars['nid'];
}

function phptemplate_textarea($element) {
  $class = array('form-textarea');

  $cols = $element['#cols'] ? ' cols="'. $element['#cols'] .'"' : '';
  _form_set_class($element, $class);
  return theme('form_element', $element, '<textarea'. $cols .' rows="'. $element['#rows'] .'" name="'. $element['#name'] .'" id="'. $element['#id'] .'" '. drupal_attributes($element['#attributes']) .'>'. check_plain($element['#value']) .'</textarea>');
}



function avtstore_theme(&$existing, $type, $theme, $path) {
  $hooks = zen_theme($existing, $type, $theme, $path);

  $hooks = array_merge($hooks, array(
      'order_node_form' => array(
          'arguments' => array('form' => NULL, 'form_state' => NULL),
          'template' => 'node-edit-order',
          'path' => drupal_get_path('theme', 'avtstore') . '/templates/',
          ),
      )
  );

  return $hooks;
}


function avtstore_menu_item_link($link) {
  $out = theme_menu_item_link($link);

  if ('menu-left-nav' == $link['menu_name'] || 'menu-home-nav' == $link['menu_name']) {
    if (!empty($link['options']['attributes']['title'])) {
      $link_end_pos = stripos( $out, '</a>' );
      if ($link_end_pos !== FALSE) {
        /*
         * A space is necessary here to prevent "administration tasks" being
         * shortened to "istration tasks" when the menu item title is "admin"
         */
        if ( stripos( trim($link['options']['attributes']['title']), trim($link['link_title']) . ' ') === 0 ) {
          $link['options']['attributes']['title'] = substr( $link['options']['attributes']['title'], strlen( $link['link_title'] ) );
        }

        $out = substr_replace( $out, '<span class="description">' . check_plain($link['options']['attributes']['title']) . '</span>', $link_end_pos, 0 );
      }
    }
  }

  return $out;
}
