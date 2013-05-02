<?php
  /*
    Copied directly from theme_hierarchical_select but modified to include the
    #field from our preprocess function
  */

  // Update $element['#attributes']['class'].
  if (!isset($element['#attributes']['class'])) {
    $element['#attributes']['class'] = '';
  }
  $hsid = $element['hsid']['#value'];
  $level_labels_style = variable_get('hierarchical_select_level_labels_style', 'none');
  $classes = array(
   'hierarchical-select-wrapper',
   "hierarchical-select-level-labels-style-$level_labels_style",
   // Classes that make it possible to override the styling of specific
   // instances of Hierarchical Select, based on either the ID of the form
   // element or the config that it uses.
   'hierarchical-select-wrapper-for-name-' . $element['#id'],
   (isset($element['#config']['config_id'])) ? 'hierarchical-select-wrapper-for-config-' . $element['#config']['config_id'] : NULL,
  );
  $element['#attributes']['class'] .= ' '. implode(' ', $classes);
  $element['#attributes']['id'] = "hierarchical-select-$hsid-wrapper";
  $element['#id'] = "hierarchical-select-$hsid-wrapper"; // This ensures the label's for attribute is correct.

  echo theme(
    'hierarchical_select_form_element',
    array(
      '#title' => $element['#title'],
      '#description' => $element['#description'],
      '#id' => $element['#id'],
      '#required' => $element['#required'],
      '#error' => isset($element['#error']) ? $element['#error'] : '',
      '#field' => $element['#field'], // Added line
    ),
    '<div '. drupal_attributes($element['#attributes']) .'>'. $element['#children'] .'</div>'
  );