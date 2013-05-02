<?php
  /* Court pay confirmation page */

  $order = _avtstore_orders_get_current_order();
  if ( empty($order->nid) ) {
    drupal_not_found();
    exit;
  }

  $buttons[] = l(
      '<span class="fancy-button-start"></span><span class="fancy-button-text-wrap">' . t('View Order') . '</span><span class="fancy-button-end"></span>',
      drupal_get_path_alias('node/' . $order->nid),
      array(
          'html' => TRUE,
          'alias' => TRUE,
          'attributes' => array(
              'title' => t('View this order'),
              'class' => 'edit-order fancy-button fancy-button-right fancy-button-small'
          )
      )
  );

  $content_parts = array();
  $content_parts[] = '<h2 class="confirmation-number">' . t('Confirmation number: <span class="order-number">@order-number</span>', array('@order-number' => $order->nid)) . '</h2>';
  $content_parts[] = $content;
  $content_parts[] = '<div class="btn-wrapper clearfix">';
  $content_parts[] = implode(' ', $buttons);
  $content_parts[] = '</div>';
  $content_parts[] = '<img src="http://ad.retargeter.com/seg?add=391419&t=2" width="1" height="1" />';

  $content = implode('', $content_parts);

  unset($_SESSION['orders']);

  require 'node.tpl.php';
