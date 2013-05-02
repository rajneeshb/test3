
Drupal.behaviors.AVTranz_general = function ($context) {
  if ( jQuery.colorbox ) {
    $('.colorbox-load', $context)
      .colorbox( {
        iframe : true,
        width : '65%',
        height : '50%'
      } );
  }

  $('a[rel="external"]')
   .click( function (e) {
     window.open( $(this).attr('href') );
     
     e.preventDefault();
     return false;
   });
};


Drupal.behaviors.AVTranz_check_status = function ($context) {
  /* Order listing related */
  if ( $('div.view-check-status.check-status .views-widget-filter-field_orderstatus_value').length > 0 ) {

    var label_text = $('div.view-check-status.check-status .views-widget-filter-field_orderstatus_value label').text();
    var element_name = $('div.view-check-status.check-status .views-widget-filter-field_orderstatus_value select').attr('name');
    var element_id = $('div.view-check-status.check-status .views-widget-filter-field_orderstatus_value select').attr('id');
    var element_id_hijack = element_id + '_hijack';

    var $new_element = $('<div />').append('<input type="checkbox" />').append('<label />');

    $new_element
      .attr('id', 'view_filter_hijack')
      .children('input')
      .attr('id', element_id_hijack)
      .attr('value', 1)
      .attr('checked', $('#' + element_id + ' option[value=1]').is(':selected') )
      .bind('change', function () {
        $('#' + element_id).removeAttr('selected');

        if ( $(this).is(':checked') ) {
          $('#' + element_id + ' option[value=1]').attr('selected', 'selected');
        }
        else {
          $('#' + element_id + ' option[value=0]').attr('selected', 'selected');
        }

        $('#' + element_id).trigger('change');
      })
      .siblings('label')
      .attr('for', element_id_hijack)
      .text(label_text);

    $('div.view-check-status.check-status .views-widget-filter-field_orderstatus_value')
      .children()
      .hide()
      .parent()
      .append($new_element);

    $('#edit-field-orderstatus-value-many-to-one')
      .bind('change', function () {
        if ( $(this).find('option[value="completed"]').is(':selected') ) {
          $('#' + element_id_hijack)
            .removeAttr('checked')
            .trigger('change');
        }
      });
  }
};