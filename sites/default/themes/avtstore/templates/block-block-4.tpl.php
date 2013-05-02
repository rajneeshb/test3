<?php

/**
 * @file block.tpl.php
 *
 * Theme implementation to display a block.
 *
 * Available variables:
 * - $block->subject: Block title.
 * - $block->content: Block content.
 * - $block->module: Module that generated the block.
 * - $block->delta: This is a numeric id connected to each module.
 * - $block->region: The block region embedding the current block.
 *
 * Helper variables:
 * - $block_zebra: Outputs 'odd' and 'even' dependent on each block region.
 * - $zebra: Same output as $block_zebra but independent of any block region.
 * - $block_id: Counter dependent on each block region.
 * - $id: Same output as $block_id but independent of any block region.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * @see template_preprocess()
 * @see template_preprocess_block()
 */

  setlocale(LC_MONETARY, 'en_US');

  $order = _avtstore_orders_get_current_order();

  $order_statuses = content_allowed_values( content_fields('field_orderstatus', 'order') );
  $block_vars['order-status'] =
      !empty( $order_statuses[$order->field_orderstatus[0]['value']] ) ?
        check_plain( $order_statuses[$order->field_orderstatus[0]['value']] ) :
        check_plain( $order->field_orderstatus[0]['value'] );


  if ( module_exists('avtstore_orders') ) {
    $block_vars['balance-due'] = _avtstore_orders_calculate_balance_due($order->nid, FALSE);
  }
  else {
    $block_vars['balance-due'] = 0;
  }

  $block_vars['court-pay'] = ('court_pay' === $order->field_how_to_pay[0]['value']);

  $block_vars['completion-date'] = empty($order->field_completiondate[0]['view']) ? t('In progress') : $order->field_completiondate[0]['view'];
  $block_vars['due-date'] = empty($order->field_due_date[0]['value']) ? t('Not set') : format_date(strtotime($order->field_due_date[0]['value']), 'custom', 'm/d/Y');

  $block_vars['buttons'] = array();


  /* Upload audio files to the order */
  if ( ('node' === arg(0)) && user_access('bulk upload files with plupload') ) {
    $block_vars['buttons'][] =
    l(
    	'<span class="fancy-button-start"></span><span class="fancy-button-text-wrap">'
      . t('Audio &amp; notes')
      . '</span><span class="fancy-button-end"></span>',
      'file-plupload/' . $order->nid,
      array(
      	'html' => TRUE,
    		'alias' => TRUE,
        'attributes' => array(
        	'title' => t('Upload files to this order'),
          'class' => 'audio-notes fancy-button fancy-button-right fancy-button-small'
        )
      )
    )
    .
    l(
        theme('image', drupal_get_path('theme', 'avtstore') . '/images/ico-info.gif', t('Help icon'), t('What\'s this?') ),
        drupal_get_path_alias('node/' . 4377),
        array(
            'html' => TRUE,
            'attributes' => array(
                'class' => 'colorbox-load help-icon'
            )
        )
    )
    ;
  }

  /* Pay a balance on the order */
  if ( ('node' === arg(0)) && 0 < $block_vars['balance-due'] && !$block_vars['court-pay'] ) {
    ob_start();
    include 'payment-button.inc';
    $block_vars['buttons'][] = ob_get_contents();
    ob_end_clean();
  }

  /* Edit the order*/
  if ( ('node' === arg(0)) && user_access('edit any order content') ) {

    /* Add a revision history option */
    if ( user_access('view revisions') ) {
      $block_vars['buttons'][] = l(
          '<span class="fancy-button-start"></span><span class="fancy-button-text-wrap">' . t('History') . '</span><span class="fancy-button-end"></span>',
          drupal_get_path_alias('node/' . $order->nid . '/revisions'),
          array(
              'html' => TRUE,
              'alias' => TRUE,
              'attributes' => array(
                  'title' => t('Edit this history of this order'),
                  'class' => 'revision-history fancy-button fancy-button-right fancy-button-small'
              )
          )
      );
    }

    $block_vars['buttons'][] = l(
      '<span class="fancy-button-start"></span><span class="fancy-button-text-wrap">' . t('Edit Order') . '</span><span class="fancy-button-end"></span>',
      drupal_get_path_alias('node/' . $order->nid . '/edit'),
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
      $order->path,
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


  if ( in_array($order->field_orderstatus[0]['value'], array('completed','complete_amended')) ) {
    if ( !empty($order->field_completed_transcript[0]) ) {
      //$block_vars['transcript-path'] =  file_directory_path() . '/orders/' . $order->nid . '/' . $order->field_completed_transcript[0]['filename'];
      $block_vars['transcript-path'] =  file_directory_path() . '/' . $order->field_completed_transcript[0]['filename'];
    }
  }

  if ( empty($block_vars['customer-title']) ) {
    $profile = NULL;

    if ( empty($profile) ) {
      $profile = content_profile_load('profile', $order->uid );
      $block_vars['username'] = implode(' ', array($profile->field_first_name[0]['value'], $profile->field_last_name[0]['value']));
      $block_vars['username'] = l( $block_vars['username'], drupal_get_path_alias('user/' . $profile->uid) );
    }

    if ( !empty($profile) ) {
      $name_parts = array();
      if ( !empty($profile->field_first_name[0]['value']) ) {
        $name_parts[] = $profile->field_first_name[0]['value'];
      }
      if ( !empty($profile->field_last_name[0]['value']) ) {
        $name_parts[] = $profile->field_last_name[0]['value'];
      }

      $block_vars['customer-title'] = check_plain( implode(' ', $name_parts) );
    }

    if ( empty($block_vars['customer-title']) ) {
      $block_vars['customer-title'] = check_plain( $order->name );
    }
  }
  $confidential = '';
  $confidential_class = 'class="confidential_button"';
  if($order->field_confidential[0]['value']) {
    $confidential = '<span class="confidential">Confidential</span>';
  }

  ob_start();  // We want to catch the output to overwrite $block->content
?>
<?php if ( !empty($order->title ) ) : ?>
  <h2 class="case-name"><?php print $order->title; ?></h2> <?php echo $confidential; ?>
<?php endif; ?>
<?php if ( arg(0) == 'node' ) : ?>
<div id="top-block">
  <div id="customer">
    <div class="customer-title">Customer:</div>
    <span><?php echo $block_vars['username']; ?></span>
  </div>
  <div id="due-date">
    <div class="due-date-title">Due Date:</div>
    <span><?php echo $block_vars['due-date']; ?></span>
  </div>
  <div id="status">
    <div class="status-title">Status:</div>
      <?php echo $block_vars['order-status']; ?>
  </div>
  <?php if ( !empty($block_vars['transcript-path']) ) : ?>
    <?php if ( $order->field_confidential[0]['value'] ) : ?>
      <div id="magic-button" class="confidential_button">
    <?php else : ?>
      <div id="magic-button">
    <?php endif; ?>
      <?php
      echo l(
        t('Download transcript'),
        url( $block_vars['transcript-path'] , array('absolute' => TRUE)),
        array(
      		'attributes' => array(
      			'title' => t('Download the transcript'),
          )
        )
      ); ?></div>
  <?php else : ?>
    <div id="magic-button" class="disabled"></div>
  <?php endif; ?>
</div>
<div class="questions">Questions? <a href="http://avtranz.com/contact.php" rel="external" title="Get information on how to contact AVTranz.">Click here</a> to contact AVTranz.
</div>
<?php if ( 0 < $block_vars['balance-due'] && !$block_vars['court-pay'] ) : ?>
  <div class="balance_amount">Balance due: <? echo money_format('%n', $block_vars['balance-due']); ?></div>
<?php endif; ?>
<?php endif; ?>
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
