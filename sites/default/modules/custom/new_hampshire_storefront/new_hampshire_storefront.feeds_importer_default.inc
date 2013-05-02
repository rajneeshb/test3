<?php

/**
 * Implementation of hook_feeds_importer_default().
 */
function new_hampshire_storefront_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'court_importer';
  $feeds_importer->config = array(
    'name' => 'Court Importer',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'content_provider_group',
        'input_format' => '0',
        'update_existing' => '0',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'type',
            'target' => 'field_providertype',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'name',
            'target' => 'field_providergroupname',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'number',
            'target' => 'field_providernumber',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Title',
            'target' => 'field_avtcode',
            'unique' => FALSE,
          ),
        ),
        'author' => '1',
        'authorize' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );
  $export['court_importer'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'tcro_order_updater';
  $feeds_importer->config = array(
    'name' => 'tcro order updater',
    'description' => 'Updates store orders with information from tcro',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'field_store_order_id_value',
          'xpathparser:2' => 'field_order_number_value',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:2' => 0,
        ),
        'context' => '/projects/order',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:2' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'order',
        'input_format' => '0',
        'update_existing' => '2',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'nid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'xpathparser:2',
            'target' => 'field_order_number',
            'unique' => FALSE,
          ),
        ),
        'author' => 0,
        'authorize' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '900',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );
  $export['tcro_order_updater'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'test_location_importer';
  $feeds_importer->config = array(
    'name' => 'Test Location Importer',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'content_provider_group',
        'input_format' => '0',
        'update_existing' => '0',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'typeid',
            'target' => 'field_courttyperef:nid',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'location',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'type',
            'target' => 'field_providertype',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'avtcode',
            'target' => 'field_avtcode',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'location',
            'target' => 'field_providergroupname',
            'unique' => FALSE,
          ),
        ),
        'author' => '1',
        'authorize' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );
  $export['test_location_importer'] = $feeds_importer;

  return $export;
}
