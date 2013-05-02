<?php

  $matches = array();
  if (preg_match('/\/>(.+)<\/label>/', $value, $matches) > 0) {
    $original_title = $matches[1];
    $element['#title'] = t('Yes');

    $checkbox = '<input ';
    $checkbox .= 'type="checkbox" ';
    $checkbox .= 'name="' . $element['#name'] . '" ';
    $checkbox .= 'id="' . $element['#id'] . '" ';
    $checkbox .= 'value="' . $element['#return_value'] . '" ';
    $checkbox .= $element['#value'] ? ' checked="checked" ' : ' ';
    $checkbox .= drupal_attributes($element['#attributes']) . ' />';

    if (!empty($element['#title'])) {
      $checkbox = '<label class="option" for="' . $element['#id'] . '">' . $checkbox . ' ' . $element['#title'] . '</label>';
    }
  }
  else {
    $checkbox = $value;
  }

?><div class="form-item" id="<?php echo $element['#id']; ?>-wrapper"><?php
  if (!empty($original_title)) {
    echo '<div>', $original_title, ':';
    if (!empty($element['#field']['help_node'])) {
      echo l( theme('image', 'sites/default/themes/avtstore/images/ico-info.gif', 'Help icon', 'What\'s this?'), $element['#field']['help_node']->path, array('html'=>TRUE , 'attributes'=>array('class' => 'colorbox-load help-icon') ) );
    }
    echo '</div>';
  }

  echo $checkbox;

  if (!empty($element['#description'])) {
    ?><div class="description"><?php echo $element['description']; ?></div><?php
  }
?></div>