<div class="form-item" id="<?php echo $element['#id']; ?>-wrapper"><?php
  echo $value;

  if (!empty($element['#description'])) {
    ?><div class="description"><?php echo $element['#description']; ?></div><?php
  }
?></div>