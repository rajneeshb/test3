<?php
/**
*Used to create the Subject line on the On Hold email alert
*/

$node = '';
if ( arg(0) == 'node' && is_numeric(arg(1)) ) {
  $node = node_load(arg(1));
}

$msg_tail = empty($node->field_order_number[0]['value']) ? "Confirmation No. ". $node->nid : "Order No. " . $node->field_order_number[0]['value'];
echo "AVTranz: New Hampshire certified transcript, ". $msg_tail;

?>
