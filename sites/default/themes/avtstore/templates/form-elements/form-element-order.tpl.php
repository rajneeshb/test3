<div class="form-item" id="<?php echo $element['#id']; ?>-wrapper"><?php
  if (!empty($element['#title'])) {
    ?><label for="<?php echo $element['#id']; ?>"><?php echo $element['#title']; ?>:<?php
      if (!empty($element['#required'])) {
        ?><span class="form-required" title="<?php echo t('This field is required.'); ?>">*</span><?php
      }

      if (!empty($element['#field']['help_node'])) {
        echo l( theme('image', 'sites/default/themes/avtstore/images/ico-info.gif', 'Help icon', 'What\'s this?'), $element['#field']['help_node']->path, array('html'=>TRUE , 'attributes'=>array('class' => 'colorbox-load help-icon') ) );
      }
      ?></label><?php
  }

  echo $value;

  if (!empty($element['#description'])) {
    ?><div class="description"><?php echo $element['#description']; ?></div><?php
  }
?></div>