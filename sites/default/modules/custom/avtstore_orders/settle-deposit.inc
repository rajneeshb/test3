<?php
//dpm('REMOVE THE ASSOCIATION WITH THIS FILE : ' . __FILE__);
  include("./sites/all/libraries/paymentprocessing/HOP.inc") ;
  drupal_add_js(drupal_get_path('theme', 'avtstore') .'/js/settle_deposit.js', 'theme');

  $order_id = !empty($_GET['order']) ? $_GET['order'] : $_SESSION['orders']['order_id'];

  if ( !empty($order_id) ) {
    $order = node_load($order_id);

    global $user;
    if ( !user_access('edit any order content') &&  $user->uid != $order->uid) {
      watchdog('order', '@uid tried to access an order ( @oid ) they did not create!', array('@uid' => $user->uid, '@oid' => $order_id), WATCHDOG_ALERT);
      $order_id = FALSE;
    }
    else {
      if ( 'court_pay' == $order->field_how_to_pay[0]['value'] ) {
        $difference = 0;
      } else {
        $amount_owed = max( floatval( $order->field_estimated_cost[0]['value'] ), floatval( $order->field_actual_cost[0]['value'] ) );
        $difference = round( $amount_owed - floatval( $order->field_amount_paid[0]['value'] ), 2);
      }
    }
  }
?>
<?php if ( !empty($order_id) ) : ?>
<div class="btn-back">
  <a href="<?php echo url( drupal_get_path_alias('node/' . $order_id) ); ?>" title="View your order" class="summary fancy-button fancy-button-right fancy-button-small"><span class="fancy-button-start"></span><span class="fancy-button-text-wrap">View your order</span><span class="fancy-button-end"></span></a>
</div>
<?php endif; ?>
<div id="item-wrapper">
  <div class="credit-card item item-1 first">
    <div id="caption">
      <img src="/sites/default/themes/avtstore/images/credit-card.jpg" alt="" />
      <h3>Credit Card</h3>
      <p>I'll pay my deposit by CC.</p>
    </div>
    <?php if ( !empty($order_id) && ($difference > 0) ) : ?>
    <div class="pay-now">
      <form id="cspaymentform" name="cspaymentform" action="https://orderpage.ic3.com/hop/orderform.jsp" method="post"> 
        <?php //InsertSignature3($amount_owed,"usd", "authorization"); ?>
        <?php InsertSignature3($difference,"usd", "authorization"); ?>
        <input type="hidden" name="order_path"
            value="<?php echo htmlspecialchars( url( drupal_get_path_alias('node/' . $order_id) ) ); ?>" />
        <input type="hidden" name="billTo_firstName" value="" />
        <input type="hidden" name="billTo_lastName" value="" />
        <input type="hidden" name="merchantDefinedData1" value="<?php echo $order_id; ?>" />
        <input type="hidden" name="uid" value="<?php global $user; echo $user->uid; ?>" />
          <button type="submit" class="deposit-button fancy-button fancy-button-right fancy-button-small" id="settle-deposit-pay-now" title="<?php echo t('$@cost is still owed.', array('@cost' => number_format($difference, 2)) ); ?>"><span class="fancy-button-start"></span><span class="fancy-button-text-wrap">Pay Now ($<?php echo number_format($difference, 2); ?>)</span><span class="fancy-button-end"></span></button>
      </form>
    </div>
    <?php elseif ( 'court_pay' == $order->field_how_to_pay[0]['value'] )  : ?>
    <?php else : ?>
    <p>You do not owe a balance for this order.</p>
    <?php endif; ?>
  </div>
  <div class="on-account item item-2">
    <div id="caption">
      <img src="/sites/default/themes/avtstore/images/on-account.jpg" alt="" width="205" height="141" />
      <h3 class="info">On Account <a href="<?php echo url( drupal_get_path_alias('node/2586') ); ?>" class="colorbox-load info-tip"><img src="/sites/default/themes/avtstore/images/ico-info.gif" /></a></h3>
      <p>I'm On Account with AVTranz</p>
    </div>
  </div>
  <div class="contact-av item item-3 last">
    <div id="caption">
      <img src="/sites/default/themes/avtstore/images/contact.jpg" alt="" />
      <h3>Contact AVTranz</h3>
      <p>I'll contact AVTranz to make arrangements to pay.</p>
    </div>
    <a href="/node/2587" class="deposit-button fancy-button fancy-button-right fancy-button-small"><span class="fancy-button-start"></span><span class="fancy-button-text-wrap">Contact AVTranz</span><span class="fancy-button-end"></span></a>
  </div>
</div>
