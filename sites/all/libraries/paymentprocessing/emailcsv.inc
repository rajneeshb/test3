<?php
  /*
    Used for generating a csv list of users assigned to the court node on an
    order that has had its status changed to Pending Audio Upload
  */

  $users = array();
  foreach (views_get_view_result('erick_test_view', NULL, $nid) as $user) {
    $users[] = $user->users_mail;
  }
  echo implode(',', $users);
//echo 'steven.wichers@mcmurry.com';
?>
