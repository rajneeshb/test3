<?php
/**
 * @file views-views-xml-style-raw.tpl.php
 * Default template for the Views XML style plugin using the raw schema
 *
 * Variables
 * - $view: The View object.
 * - $rows: Array of row objects as rendered by _views_xml_render_fields
 *
 * @ingroup views_templates
 * @see views_views_xml_style.theme.inc
 */
  $raw_fields = array(
      // We want the key values, not the display values -- Views doesn't have an option for this
      'field_transcribeextra_value',
      'field_otherformats_value',
      'field_appealtranscript_value',

      // Gets a styled display value, not the correctly formatted one
      'field_hearingdate_value',
      'field_due_date_value',
      );

  foreach ($rows as $index => $row) {
    if ( empty($row) ) {
      continue;
    }

    foreach ($row as $field => $info) {
      if ( in_array($field, $raw_fields) ) {
        $rows[$index][$field]->content = $rows[$index][$field]->raw;
      }
    }
  }

  if ( !class_exists('SimpleXMLExtended') ) {
    class SimpleXMLExtended extends SimpleXMLElement // http://coffeerings.posterous.com/php-simplexml-and-cdata
    {
      public function addCData($cdata_text)
      {
        $node= dom_import_simplexml($this);
        $no = $node->ownerDocument;
        $node->appendChild($no->createCDATASection($cdata_text));
      }
    }
  }

  $sxe = new SimpleXMLExtended('<' . $options['root_element'] . '/>');

  foreach ($rows as $row) {
    $order = $sxe->addChild($options['top_child_object']);
    foreach ($row as $element => $info) {
      $tag = empty($info->label) ? $info->id : $info->label;
      if($tag == 'jurisdiction') {
        $name = $info->content;
        $e = $order->addChild('jurisdiction_id');
        $term = taxonomy_get_term_by_name($name);
        $e->addCData($term[0]->tid);
      }

      if ( !$info->is_multiple && !is_array($info->content) ) {
        if ( $options['escape_as_CDATA'] ) {
          $e = $order->addChild($tag);
          $e->addCData($info->content);
        }
        else {
          $order->addChild($tag, $info->content);
        }
      }
      else {
        if ( !is_array($info->content) ) {
          $info->content = array($info->content);
        }

        $xml_element = $order->addChild($tag);

        foreach ($info->content as $val) {
          if ( $options['escape_as_CDATA'] ) {
            $e = $xml_element->addChild($tag);
            $e->addCData($val);
          }
          else {
            $xml_element->addChild($tag, $val);
          }
        }
      }
    }
  }

  $xml = $sxe->asXML();


	if ($view->override_path) {       // inside live preview
    print htmlspecialchars($xml);
  }
  else if ($options['using_views_api_mode']) {     // We're in Views API mode.
    print $xml;
  }
  else {
  	drupal_set_header("Content-Type: $content_type; charset=utf-8");
    print $xml;
    exit;
  }
