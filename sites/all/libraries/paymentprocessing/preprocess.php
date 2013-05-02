<?php
  $path = realpath( basename( $_SERVER['SCRIPT_NAME'] ) );
  $path = substr( $path, 0, strpos( $path, $_SERVER['SCRIPT_NAME'] ) );
  chdir($path);

  require_once 'includes/bootstrap.inc';
  drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);  // ಠ_ಠ really requires a full bootstrap for watchdog?

  defined('PREPROCESS_LOG_FILE') or define('PREPROCESS_LOG_FILE', $path . '/sites/all/libraries/paymentprocessing/logs/' . date('Y-m-d') . 'preprocess.log');

  if ( !file_exists(PREPROCESS_LOG_FILE) ) {
    if ( !touch(PREPROCESS_LOG_FILE) ) {
      $msg = PREPROCESS_LOG_FILE . ' does not exist and was not able to be created!';

      watchdog('payment', $msg, NULL, WATCHDOG_ALERT);
      die($msg);
    }
  }

  if ( !is_writeable(PREPROCESS_LOG_FILE) ) {
    $msg = PREPROCESS_LOG_FILE . ' is not writeable!';

    watchdog('payment', $msg, NULL, WATCHDOG_ALERT);
    die($msg);
  }

  $vals = array();
  $vals['Order ID'] = intval( $_REQUEST['merchantDefinedData1'] );
  $vals['Price'] = floatval( $_REQUEST['amount'] );
  $vals['User ID'] = intval( $_REQUEST['uid'] );
  $vals['IP'] = $_SERVER['REMOTE_ADDR'];
  $vals['Timestamp'] = time();
  $vals['Time/Date'] = date('r', $vals['Timestamp']);
  $vals['Order Page Timestamp'] = intval( $_REQUEST['orderPage_timestamp'] );
  $vals['Order Page Time/Date'] = date('r', $vals['Order Page Timestamp']);
  $vals['User Agent'] = $_SERVER['HTTP_USER_AGENT'];

  $output = print_r($vals, TRUE);

  if ( file_put_contents(PREPROCESS_LOG_FILE, $output, FILE_APPEND) === FALSE ) {
    $msg = 'Unable to write information to log :' . PHP_EOL . var_dump($output, TRUE);
  
    watchdog('payment', $msg, NULL, WATCHDOG_ALERT);
    die($msg);
  }
  else {
    watchdog('payment', 'Preprocess from user @uid at address @ip for order @oid', array('@uid' => $vals['User ID'], '@ip' => $vals['IP'], '@oid' => $vals['Order ID']), WATCHDOG_INFO);
  }