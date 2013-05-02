<?php
  unset($_SESSION['orders']);
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>">
<head>
  <title><?php print $head_title; ?></title>
  <meta http-equiv="X-UA-Compatible" content="IE=edge" />
  <?php print $head; ?>
  <?php print $styles; ?>
  <?php print $scripts; ?>
  <script type="text/javascript">
  Drupal.behaviors.PaymentReceived = function ($context) {
    $('.close-confirmation', $context)
    .show()
    .click( function (e) {
      parent.jQuery.fn.colorbox.close();

      e.preventDefault();
      return false;
    } );

    if ( parent.AVTranz ) {
      parent.AVTranz.successful_payment = $('body', $context).hasClass('payment-accept');
    }
  };
  </script>
</head>
<body class="<?php print $classes . " nid-" . $node->nid; ?> payment-<?php echo strtolower($_REQUEST['decision']); ?>">
  <?php if ('ACCEPT' == strtoupper($_REQUEST['decision']) ) : ?>
    <h1>Payment processed successfully!</h1>
  <?php elseif ('REJECT' == strtoupper($_REQUEST['decision']) ) : ?>
    <h1>Payment failed to process!</h1>
  <?php else : ?>
    <h1>Payment response: <?php echo check_plain($_REQUEST['decision']); ?></h1>
  <?php endif; ?>

  <div class="response-inner">
    <?php if ('ACCEPT' == strtoupper($_REQUEST['decision']) ) : ?>
      <p>Your payment has been processed successfully.</p>
    <?php elseif ('REJECT' == strtoupper($_REQUEST['decision']) ) : ?>
      <p>There was an error processing your payment. Please contact AVTranz for
      details.</p>
    <?php else : ?>
      <p>There was an unknown response from the payment processer. Please
      contact AVTranz for details.</p>
    <?php endif; ?>

    <?php echo $content; ?>
  </div>

  <?php if ( !empty($_REQUEST['order_id']) ) : ?>
  <?php echo l( t('Click here to view your submitted Order'),
                drupal_get_path_alias('node/' . $_REQUEST['order_id']),
                array( 'attributes' => array('class' => 'hide close-confirmation') )
              ); ?>
  <?php endif; ?>
</body>
</html>
