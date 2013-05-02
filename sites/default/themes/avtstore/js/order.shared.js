var AVTranz = AVTranz || {};

AVTranz.field_toggle = function ($queryObj, disableElement) {

  if ( disableElement ) {
    $queryObj
      .removeAttr('checked')
      .removeClass('required')
      .attr('disabled', 'disabled')
      .attr('readonly', 'readonly')
      .trigger('change');
  }
  else {
    $queryObj
      .removeAttr('disabled')
      .removeAttr('readonly')
      .trigger('removedisable'); // triggering change will cause infinite recursion
  }

  return $queryObj;
};

Drupal.behaviors.AVTranz_order_checkbox_handlers = function ($context) {

  // make checkboxes in IE behave as intended. --sph
  if (jQuery.browser.msie) {
    $('input:checkbox, input:radio', $context).click(function () {
      this.blur();
      this.focus();
    });
  }


  var $transcribe_boxes = $('.form-col-field_transcribeextra', $context);

  $('#edit-field-transcribeextra-value-entire:checkbox', $transcribe_boxes)
    .change( function (e) {
      if ( $(this).is(':checked') ) {
        AVTranz.field_toggle( $('input[type="checkbox"]:not(#edit-field-transcribeextra-value-entire,#edit-field-transcribeextra-value-juryselection)', $transcribe_boxes), true );
        AVTranz.field_toggle( $('#edit-field-transcribeextra-value-juryselection', $transcribe_boxes), false );
      }
      else {
        AVTranz.field_toggle( $('input:checkbox:not(#edit-field-transcribeextra-value-entire)', $transcribe_boxes), false );
      }
    })
    .trigger('change');

  $('input:checkbox:not(#edit-field-transcribeextra-value-entire,#edit-field-transcribeextra-value-juryselection)', $transcribe_boxes)
   .change( function (e) {
     if ( $(this).is(':checked') ) {
       AVTranz.field_toggle( $('#edit-field-transcribeextra-value-entire:checkbox', $transcribe_boxes), true);
     }
     else {
       if ( $('input:checked:not(#edit-field-transcribeextra-value-entire,#edit-field-transcribeextra-value-juryselection)', $transcribe_boxes).length == 0 ) {
         AVTranz.field_toggle( $('#edit-field-transcribeextra-value-entire:checkbox'), false );
       }
     }
   });

  $('#edit-field-transcribeextra-value-witness:checkbox', $transcribe_boxes)
   .change( function (e) {
     if ( $(this).is(':checked') ) {
       AVTranz.field_toggle( $('#edit-field-witnesses-0-value', $context), false )
         .addClass('required');
     }
     else {
       AVTranz.field_toggle( $('#edit-field-witnesses-0-value', $context), true );
     }
   })
   .trigger('change');

  $transcribe_boxes
    .find('input')
    .bind('change removedisable', function () {
      if ( $(this).is(':disabled') ) {
        $(this)
          .parent('label:not(.disabled)')
          .addClass('disabled');
      }
      else {
        $(this)
          .parent('label.disabled')
          .removeClass('disabled');
      }
    });

  $('#edit-field-appealtranscript-value', $context)
   .change( function (e) {
     AVTranz.field_toggle( $('#edit-field-appeal-number-0-value', $context), !$(this).is(':checked') );

     if ( $(this).is(':checked') ) {
       $('#edit-field-appeal-number-0-value', $context)
         .addClass('required');
     }
   } )
   .trigger('change');

  $('#edit-field-otherformats-value-paper', $context)
   .change( function () {
     AVTranz.field_toggle( $('#edit-field-numcopies-0-value', $context), !$(this).is(':checked') );
   } )
   .trigger('change');
};

Drupal.behaviors.AVTranz_order_other = function ($context) {
  $('#group_hearingdates_values div.description:first', $context)
    .prependTo('fieldset#multistep-group_hearingdates div.content-add-more');

  $('a.content-multiple-remove-button', $context).bind('click', function () {
    $('tr.content-multiple-removed-row').remove();
  });

  var $hierarchy_court_type = $('select#edit-field-locationref-nid-hierarchical-select-selects-0', $context);
  if ( ( $hierarchy_court_type.length > 0 ) && !$hierarchy_court_type.is('avt-processed') ) {
    $hierarchy_court_type
      .find('option:first')
      .attr('disabled', 'disabled')
      .siblings(':first')
      .remove();
  }

  var $hierarchy_child_select = $('select#edit-field-locationref-nid-hierarchical-select-selects-1', $context);
  if ( ( $hierarchy_child_select.length > 0 ) && !$hierarchy_child_select.is('avt-processed') ) {

    $hierarchy_child_select.addClass('avt-processed');

    $hierarchy_child_select
      .prepend(
          $('<option />')
            .text( Drupal.t('Please select') )
            .attr('value', 'none')
            .addClass('has-no-children')
            .addClass('level-label')
      );

    if ( $('form.order-form').hasClass('finished-first-run') ) {
      $hierarchy_child_select
        .find('option:selected')
        .removeAttr('selected')
        .siblings()
        .find('option.level-label')
        .attr('selected', 'selected');

      if ( jQuery.browser.msie ) {
        $hierarchy_child_select[0].selectedIndex = 0;
      }
    }

    if ( $('label#hierarchical_select_court_type_child', $context).length == 0 ) {
      $('.form-col-field_locationref label:first', $context)
        .after(
            $('<label />')
              .html(
                    Drupal.t('Court location:') +
                    '<span title="This field is required." class="form-required">*</span> '+
                    '<a class="colorbox-load help-icon" href="/help/hearing-location">' +
                    '<img width="14" height="14" title="What\'s this?" alt="Help icon" src="/sites/default/themes/avtstore/images/ico-info.gif" /></a>'
                   )
              .attr('for', 'edit-field-locationref-nid-hierarchical-select-selects-1')
              .attr('id', 'hierarchical_select_court_type_child')
        );

      $('.form-col-field_locationref .colorbox-load', $context)
        .colorbox( {
          iframe : true,
          width : '65%',
          height : '50%'
        } );
    }
  }

  $('#group_hearingdates_values div.container-inline-date div.form-item input.form-text', $context)
    .keydown( function (e) {
      $('#ui-datepicker-div').hide();
    })
    .click( function (e) {
      if ( $(this).is('[value=""]') ) {
        $(this).val( $('#group_hearingdates_values div.container-inline-date div.form-item input.form-text[value!=""]:last').val() );
      }
    });

  if ( !$('form.order-form', $context).hasClass('finished-first-run') ) {
    $('form.order-form')
      .addClass('finished-first-run');
  }
};