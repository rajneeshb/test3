<?php
  if ( module_exists('avtstore_orders') ) {
    module_load_include('module', 'avtstore_orders');

    if ( empty($order->nid) ) {
      $order = _avtstore_orders_get_current_order();
      if ( empty($order->nid) ) {
        return;
      }
    }
    $balance_due_formatted = _avtstore_orders_calculate_balance_due($order, TRUE);
    $balance_due = _avtstore_orders_calculate_balance_due($order, FALSE);
  }
  else {
    return;
  }


  require './sites/all/libraries/paymentprocessing/HOP.inc';

  drupal_add_js(drupal_get_path('theme', 'avtstore') .'/js/settle_deposit.js', 'theme');

  global $user;
  $user_profile = content_profile_load('profile', $user->uid);

?>
  <form id="cspaymentform" name="cspaymentform" action="<?php echo variable_get('cybersource_url', 'https://orderpage.ic3.com/hop/orderform.jsp'); ?>" method="post">
    <?php echo InsertSignature3( $balance_due, 'usd', 'sale'); ?>
    <?php if ( !empty($_SERVER['MCMplatform']) ) :?>
    <input type="hidden" name="platform"             value="<?php echo check_plain($_SERVER['MCMplatform']); ?>" />
    <?php endif; ?>
    <input type="hidden" name="billTo_customerID"    value="<?php echo $user->uid; ?>" />
    <input type="hidden" name="billTo_firstName"     value="<?php echo check_plain( $user_profile->field_first_name[0]['value'] ); ?>" />
    <input type="hidden" name="billTo_lastName"      value="<?php echo check_plain( $user_profile->field_last_name[0]['value'] ); ?>" />
    <input type="hidden" name="billTo_phoneNumber"   value="<?php echo check_plain( $user_profile->field_daytime_phone[0]['value'] ); ?>" />
    <input type="hidden" name="billTo_company"       value="<?php echo check_plain( $user_profile->field_company_firm[0]['value'] ); ?>" />
    <input type="hidden" name="billTo_email"         value="<?php echo check_plain( $user->mail ); ?>" />
    <input type="hidden" name="billTo_street1"       value="<?php echo check_plain(''); ?>" />
    <input type="hidden" name="billTo_street2"       value="<?php echo check_plain(''); ?>" />
    <input type="hidden" name="billTo_city"          value="<?php echo check_plain(''); ?>" />
    <input type="hidden" name="billTo_state"         value="<?php echo check_plain(''); ?>" />
    <input type="hidden" name="billTo_postalCode"    value="<?php echo check_plain(''); ?>" />
    <input type="hidden" name="billTo_country"       value="us" />
    <input type="hidden" name="uid"                  value="<?php echo $user->uid; ?>" />
    <input type="hidden" name="order_id"             value="<?php echo $order->nid; ?>" />
    <input type="hidden" name="source_domain"        value="<?php echo check_plain($_SERVER['SERVER_NAME']); ?>" />
    <input type="hidden" name="merchantDefinedData1" value="Request ID: <?php echo $order->nid; ?>" />
    <button type="submit" class="deposit-button fancy-button fancy-button-right fancy-button-small"
          id="settle-deposit-pay-now" title="<?php echo t('@cost is still owed.', array('@cost' => $balance_due_formatted) ) ?>"
          ><span class="fancy-button-start"></span
          ><span class="fancy-button-text-wrap">Pay Now (<?php echo $balance_due_formatted; ?>)</span
          ><span class="fancy-button-end"></span
    ></button>
  </form>