<?php

/**
 * Implementation of views_handler_filter_boolean_operator
 *
 * @see views_handler_filter_boolean_operator
 */
class avtstore_orders_filter_by_not_completed extends views_handler_filter_boolean_operator {
  /**
   * Modifies the View query to filter Views by order completed status
   */
  function query() {
    if (empty($this->value))    // Option set to No
      return;

    $ta = $this->ensure_my_table();

    $join = new views_join();
    $join->construct('content_type_order', $ta, 'vid', 'vid', array(), 'LEFT');
    $cck_order_table = $this->query->ensure_table('content_type_order', $ta, $join);
    $query_group = time(); // Set up a random group to join the where clauses together

    $this->query->add_where($query_group, '%s.field_orderstatus_value <> \'completed\'', $cck_order_table);
    $this->query->add_where($query_group, '%s.field_orderstatus_value <> \'complete_amended\'', $cck_order_table);
    $this->query->add_where($query_group, '%s.field_orderstatus_value <> \'cancelled\'', $cck_order_table);
  }
}