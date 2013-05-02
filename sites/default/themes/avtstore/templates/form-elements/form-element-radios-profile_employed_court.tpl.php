<?php
  $class = 'form-radios hideaway-court-wrapper';

  if (isset($element['#attributes']['class'])) {
    $class .= ' ' . $element['#attributes']['class'];
  }

  $element['#children'] = '<div class="' . $class . '">' . (!empty($element['#children']) ? $element['#children'] : '') . '</div>';

  if ($element['#title'] || $element['#description']) {
    unset($element['#title']);
    unset($element['#id']);
    echo theme_form_element($element, $element['#children']);
  }
  else {
    echo $element['#children'];
  }