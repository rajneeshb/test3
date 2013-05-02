<?php

/**
 * Implements hook_views_handlers
 */
function avtstore_orders_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'avtstore_orders') . '/views', ),
      'handlers' => array(
        'avtstore_orders_filter_by_not_completed' => array( 'parent' => 'views_handler_filter_boolean_operator', ),
      ),
  );
}

/**
 * Implements hook_views_data
 */
function avtstore_orders_views_data() {
  $data = array();

  $data['node']['field_orderstatus_value'] = array(
		'group' => t('Content'),
		'title' => t('Status is not completed'),
    'help' => t('Allows filtering based on order complete status'),
    'filter' => array(
			'handler' => 'avtstore_orders_filter_by_not_completed',  // Name of filtering class
			'label' => t('Status is not completed'),
      'type' => 'yes-no',
      ),
  );

  return $data;
}