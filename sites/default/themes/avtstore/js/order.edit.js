var AVTranz = AVTranz || {};
AVTranz.order = AVTranz.order || {};

AVTranz.order.update_details_response = function (data, textStatus, jqXHR) {
  $('#edit-field-estimated-cost-0-value').val( data.costs.total.toFixed(2) );
  $('#edit-field-estimated-pages-0-value').val( data.info.pages );
};

Drupal.behaviors.AVTranz_orders_edit = function ($context) {
  /*
   * Triggers update on:
   *  Additional formats options changed
   *  Number of copies changed
   *  When you need it dropdown changed
   *  Hearing dates modified
   *    This does not exclude the actual hearing date input from the change event,
   *    because if the user does not add, adds time, and then adds the date the
   *    estimated cost wont update until the user changes another bound field.
   */
  $('#multistep-group_formats input, #edit-field-turnaroundtime-value, #edit-field-turnaroundtime-value, #group_hearingdates_values input.form-text', $context)
    .change( function () {
      jQuery.get(
        '/ajax/order/estimate',
        $('form.order-form').serialize(),
        AVTranz.order.update_details_response,
        'json'
      );
    })

    $('#edit-field-copy-order-value')
      .change( function () {

        if( $('#edit-field-copy-order-value').val() ) { 
          $('#edit-field-copy-page-desc-0-value')
            .removeAttr('disabled');
        }
        else {
          $('#edit-field-copy-page-desc-0-value')
            .attr('disabled', 'disabled');
        }


      });
};

