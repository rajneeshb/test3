<?php if ( !empty($element['#description']) ) : ?>
<div class="description"><?php echo $element['#description']; ?></div>
<?php endif; ?>
<?php
  unset($element['#description']);

  include 'form-element-order.tpl.php';