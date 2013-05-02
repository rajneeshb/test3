<?php
  /* Edit the order*/
  if ( ('node' === arg(0)) && user_access('edit any order content') ) {
    $block_vars['buttons'][] = l(
      '<span class="fancy-button-start"></span><span class="fancy-button-text-wrap">' . t('Edit Order') . '</span><span class="fancy-button-end"></span>',
      drupal_get_path_alias('node/' . arg(1) . '/edit'),
        array(
          'html' => TRUE,
          'alias' => TRUE,
          'attributes' => array(
            'title' => t('Edit this order'),
            'class' => 'edit-order fancy-button fancy-button-right fancy-button-small'
          )
        )
    );
  }
  else if ('node' !== arg(0)) {
    $block_vars['buttons'][] = l(
    	'<span class="fancy-button-start"></span><span class="fancy-button-text-wrap">' . t('View Order') . '</span><span class="fancy-button-end"></span>',
      drupal_get_path_alias('node/' . arg(1)),
      array(
        'html' => TRUE,
        'alias' => TRUE,
        'attributes' => array(
          'title' => t('View this order'),
          'class' => 'edit-order fancy-button fancy-button-right fancy-button-small'
		    )
      )
    );
  }

  ob_start();
?>
<?php if ( !empty($block_vars['buttons']) ) : ?>
  <div class="btn-wrapper clearfix">
    <?php foreach ($block_vars['buttons'] as $button) : ?>
      <?php echo $button; ?>
    <?php endforeach; ?>
  </div>
<?php endif; ?>
<?php
  $block->content = ob_get_contents();
  ob_end_clean();

  include 'block.tpl.php';