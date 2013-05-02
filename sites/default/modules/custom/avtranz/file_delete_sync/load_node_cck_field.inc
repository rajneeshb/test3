<?php

function _content_node_loads($param = NULL) {
  if (!is_array($param)) {
    return FALSE;
  }
  $arguments = array();
  $cck_tables = array();
  $cck_cond = array();
  $cond = array();
  $i = 1;
  foreach ($param as $key => $value) {
    if (substr($key, 0, 6) != 'field_') {
      $cond[] = 'n.'. db_escape_table($key) ." = '%s'";
      $arguments[] = $value;
    }
    else{
      $db_info = content_database_info(content_fields($key));
      // If the field is from another table, increment sequence
      if(!isset($cck_tables[$db_info['table']])){
        $cck_tables[$db_info['table']] = 'cck'. $i;
      }
      $i++;
      if($db_info['columns']['nid']){
        // For nodereference fields
        $cck_cond[] = $cck_tables[$db_info['table']] .'.'. db_escape_table($db_info['columns']['nid']['column']) ." = '%s'";
      } else if ($db_info['columns']['value']) {
        $cck_cond[] = $cck_tables[$db_info['table']] .'.'. db_escape_table($db_info['columns']['value']['column']) ." = '%s'";
      } else if ($db_info['columns']['uid']) {
        $cck_cond[] = $cck_tables[$db_info['table']] .'.'. db_escape_table($db_info['columns']['uid']['column']) ." = '%s'";
      }else if ($db_info['columns'][$key]['column']) {
        $cck_cond[] = $cck_tables[$db_info['table']] .'.'. db_escape_table($db_info['columns'][$key]['column']) ." = '%s'";
      }
      $arguments[] = $value;
    }
  }
  $cond = (!empty($cond) ? implode(' AND ', $cond) : '' );
  if (!empty($cck_cond)) {
    $cond .= (!empty($cond) ? ' AND ' : ''). implode(' AND ', $cck_cond);
    foreach ($cck_tables as $table => $nick) {
      $cck_join .= ' INNER JOIN {'. $table .'} '. $nick .' ON '. $nick .'.nid = n.nid';
    }
  }
  $sql = "SELECT n.nid FROM {node} n ".$cck_join." WHERE ".$cond;
  $res = db_query(db_rewrite_sql($sql), $param);
  $nids = array();
  while ($nid = db_result($res)) {
    $nids[$nid] = $nid;
  }
  return (empty($nids) ? FALSE : $nids);
}
?>
