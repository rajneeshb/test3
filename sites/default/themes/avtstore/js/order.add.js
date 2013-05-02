var AVTranz = AVTranz || {};

AVTranz.initialized = false;

AVTranz.number_to_text = function ( number ) {
  var replacements = Array( 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine', 'ten' );

  if ( replacements[number-1] ) {
    return replacements[number-1];
  }

  return number;
};

AVTranz.order = AVTranz.order || {};
AVTranz.order.settings = AVTranz.order.settings || {};

AVTranz.order.steps = {
    current: 1,
    last: -1,
    initalized: false
  };

AVTranz.order.steps.get_from_hash = function (hash) {
  var step = parseInt( hash.split('#')[1].split('-')[2] );

  if ( (step > AVTranz.order.steps.last) && (AVTranz.order.steps.last > 0) ) {
    step = AVTranz.order.steps.last;
  }
  else if (step < 1) {
    step = 1;
  }

  return step;
};

AVTranz.order.build_fancy_button = function (text, classname) {
  return $('<a></a>')
    .addClass('fancy-button fancy-button-' + classname)
    .attr('href', '#form-steps')
    .append(
      $('<span></span>')
        .addClass('fancy-button-start'),
      $('<span></span>')
        .addClass('fancy-button-text-wrap')
        .text(text),
      $('<span></span>')
        .addClass('fancy-button-end')
    );
};

AVTranz.order.build_fancy_buttons = function (selector) {
  $(selector)
    .after(
      $('<ul></ul>')
        .addClass('fancy-button-wrapper')
        .append(
          $('<li></li>')
            .addClass('prev fancy-button')
            .attr('id', 'order-step-prev')
            .append( AVTranz.order.build_fancy_button('Previous', 'left') ),
          $('<li></li>')
            .addClass('next fancy-button')
            .attr('id', 'order-step-next')
            .append( AVTranz.order.build_fancy_button('Next', 'right') ),
          $('<li></li>')
            .addClass('edit fancy-button')
            .attr('id', 'order-step-edit')
            .append( AVTranz.order.build_fancy_button('Edit Order', 'left') ),
          $('<li></li>')
            .addClass('continue fancy-button')
            .attr('id', 'order-step-continue')
            .append( AVTranz.order.build_fancy_button('Continue', 'right') )
        )
    );

  $('#order-step-prev a')
    .bind('click', function (event) {
      if (AVTranz.order.steps.current > 1) {
        $('ul#form-steps a.order-step-' + (AVTranz.order.steps.current - 1)).trigger('click');
      }

      event.preventDefault();
      return false;
    });

  $('#order-step-next a')
    .bind('click', function (event) {
      if (AVTranz.order.steps.current < AVTranz.order.steps.last) {
        $('ul#form-steps a.order-step-' + (AVTranz.order.steps.current + 1)).trigger('click');
      }

      event.preventDefault();
      return false;
    });

  $('#order-step-edit a.fancy-button')
    .bind('click', function (event) { event.preventDefault(); $('ul#form-steps a.order-step-1').click(); return false; } );

  $('#order-step-continue a.fancy-button')
    .bind('click', function (event) {
  event.preventDefault();
  if($('#order-step-continue a.fancy-button').hasClass('disabled')){
    return false;
  }
  else{
    $('form#node-form input#edit-submit').click();
    $('#order-step-continue a.fancy-button').addClass('disabled');
    return false;
  }
  });
};

AVTranz.order.step_click_handler = function(event) {
  event.preventDefault();

  var next_step = AVTranz.order.steps.get_from_hash( $(this).attr('href') );

  if ( !AVTranz.order.steps.initialized ) {
    AVTranz.order.steps.initialized = true;
  }
  else {
    if (next_step == AVTranz.order.steps.current) {
      return false;
    }
  }

  AVTranz.order.steps.current = next_step;

  $('ul#form-steps li a.active')
    .removeClass('active');

  $(this)
    .blur()
    .addClass('active');

  $('div[id^="order-step-"]')
    .hide()
    .filter('div#order-step-' + AVTranz.order.steps.current)
    .fadeIn();

  $('.fancy-button.next a .fancy-button-text-wrap').text( 'Step ' + AVTranz.number_to_text( AVTranz.order.steps.current + 1 ) );
  $('.fancy-button.prev a .fancy-button-text-wrap').text( 'Step ' + AVTranz.number_to_text( AVTranz.order.steps.current - 1 ) );

  if( AVTranz.order.steps.current == AVTranz.order.steps.last) {
    $('.fancy-button.next, .fancy-button.prev').hide();
    $('.fancy-button.continue, .fancy-button.edit').show();
  }
  else {
    $('.fancy-button.continue, .fancy-button.edit').hide();
    $('.fancy-button.next').show();

    if (AVTranz.order.steps.current == 1) {
      $('.fancy-button.prev').hide();
    }
    else {
      $('.fancy-button.prev').show();
    }
  }


  return false;
};

AVTranz.order.update_details = function(event) {

  $('div.form-col-status_case_name span.status-value').html( $('#edit-field-casename-0-value').val() );
  $('div.form-col-status_case_numbers span.status-value').html( $('#edit-field-case-number-0-value').val() );
  $('div.form-col-status_hearing_location span.status-value').html( $('#edit-field-locationref-nid-hierarchical-select-selects-1 option:selected').text() );
  $('div.form-col-status_appeal_number span.status-value').html( $('#edit-field-appeal-number-0-value').val() );
  $('div.form-col-status_requested_turnaround span.status-value').html( $('#edit-field-turnaroundtime-value option:selected').text() );
  $('div.form-col-status_transcribe span.status-value').html('');
  $('div.form-col-status_additional span.status-value').html('');
  $('div.form-col-status_hearing_dates span.status-value').html('');

  if ( 0 >= $('#edit-field-locationref-nid-hierarchical-select-selects-0').attr('selectedIndex') ) {
	  $('div.form-col-status_court_type span.status-value').html('')
  }
  else {
	  $('div.form-col-status_court_type span.status-value').text( $('#edit-field-locationref-nid-hierarchical-select-selects-0 option:selected').text() );
  }


  if ( $('.form-col-field_transcribeextra input:checked').length > 0 ) {
    var transcribe_extras = [];

    $('.form-col-field_transcribeextra input:checked')
      .each(function() {
        switch ( $(this).val() ) {
          case 'entire':
            transcribe_extras.push('Entire Proceedings');
            break;
          case 'juryselection':
            transcribe_extras.push('Jury selection');
            break;
          case 'opening':
            transcribe_extras.push('Opening');
            break;
          case 'closing':
            transcribe_extras.push('Closing');
            break;
          case 'witness':
            transcribe_extras.push('Witness Testimony');
            break;
        }
      } );

    if ( transcribe_extras.length > 0 ) {
      $('div.form-col-status_transcribe span.status-value')
        .html('<div class="extras">' + transcribe_extras.join(', ') + '</div>');
    }
  }

  jQuery.get(
    '/ajax/order/estimate',
    $('form.order-form').serialize(),
    AVTranz.order.update_details_response,
    'json'
  );

  event.preventDefault();
  return false;
};

AVTranz.order.update_details_response = function (data, textStatus, jqXHR) {
  $('div.form-col-status_estimated_cost span.status-value').text( '$' + data.costs.total.toFixed(2) );
  $('#edit-field-est-transcript-cost-element-wrapper span.value').text( '$' + data.costs.estimated.toFixed(2) );
  $('#edit-field-est-additional-cost-element-wrapper span.value').text( '$' + data.costs.associated.toFixed(2) );

  if ( 0 >= data.info.pages ) {
	  $('div.form-col-status_estimated_pages span.status-value').html('');
  }
  else {
	  $('div.form-col-status_estimated_pages span.status-value').text( Drupal.formatPlural(data.info.pages, '1 page', '@count pages') );
  }

  $('#edit-field-estimated-cost-0-value').val( data.costs.total.toFixed(2) );

  if ( data.info.hearings.length > 0 ) {
    $('div.form-col-status_hearing_dates span.status-value').html('');

    jQuery.each( data.info.hearings, function ( index, hearing_date ) {
      var output = [];
      output.push(hearing_date.date);

      if ( ( hearing_date.hours > 0 ) || ( hearing_date.minutes > 0 ) ) {
    	var time = [];
        if ( hearing_date.hours > 0 ) {
          time.push( Drupal.formatPlural(hearing_date.hours, '1 hour', '@count hours') );
        }

        if ( hearing_date.minutes > 0 ) {
          time.push( Drupal.formatPlural(hearing_date.minutes, '1 minute', '@count minutes') );
        }

        output.push( time.join(' ') );
      }

      if ( hearing_date.pages > 0 ) {
    	  output.push( Drupal.formatPlural(hearing_date.pages, '1 page', '@count pages') );
      }

      $('div.form-col-status_hearing_dates span.status-value').append('<div class="hearing-date">' + output.join(' | ') + '</div>');
    } );
  }

  var firstFormatItem = true;
  jQuery.each(data.info.formats, function (format, cost) {
    if ( firstFormatItem) {
      /*
       * We need to clear out the current status text. This is a cheap way to
       * avoid extending the object to include an isEmpty method. The version of
       * jQuery being used does not have it.
       */
      firstFormatItem = false;
      if ( $('div.form-col-status_additional span.status-value').text().length > 0 ) {
        $('div.form-col-status_additional span.status-value').html('');
      }
    }

    if ( 0 >= data.costs.formats[format] ) {
      return;
    }

    var output = '$' + data.costs.formats[format] + ' - ';
    switch (format) {
      case 'ascii':
        output += 'ASCII (.txt) $25/date';
        break;
      case 'cd':
        output += 'Transcript on a CD $25';
        break;
      case 'etranscript':
        output += 'E-transcript (PTX) $35/date';
        break;
      case 'condensed':
        output += 'Condensed (4/page) $25/date';
        break;
      case 'wordindex':
        output += 'Word Index $25/date';
        break;
      case 'paper':
        output += 'Printed copies $25/date per copy';
        break;
    }

    $('div.form-col-status_additional span.status-value').append( '<div>' + output + '</div>' );
  } );

  $('#multistep-group_orderdetails .form-col-status span.status-value:not(:empty)').parent('.form-col-status').show();
  $('#multistep-group_orderdetails .form-col-status span.status-value:empty').parent('.form-col-status').hide();
};

Drupal.behaviors.AVTranz_orders_page = function ($context) {
  if (AVTranz.initialized) {
    return;
  }
  else {
    AVTranz.initialized = true;
  }

  if ( $('.form-col-field_create_or_login', $context).length > 0 ) {
   $('#edit-field-create-or-login-value-create', $context)
    .change( function () {
      if ( $(this).is(':checked') ) {
        $('label[for="order-username"]', $context)
        .html('E-mail address: <span title="This field is required." class="form-required">*</span>');
      }
    });

   $('#edit-field-create-or-login-value-login', $context)
     .change( function () {
       if ( $(this).is(':checked') ) {
         $('label[for="order-username"]', $context)
           .html('Username: <span title="This field is required." class="form-required">*</span>');
       }
     });
  }

  if ($('fieldset.group-orderdetails:hidden')) {
    $('fieldset.group-orderdetails').show();
  }

  if ($('body').hasClass('page-node-add-order')) {
    if (window.location.hash !== '') {
      var matches = window.location.hash.match(/step-(\d+)/);
      if ( (matches != null) && (matches.length >= 1) ) {
        AVTranz.order.steps.current = parseInt( matches[1], 10 );
      }
    }

    AVTranz.order.steps.last = AVTranz.order.steps.get_from_hash( $('ul#form-steps li.last a').attr('href') );
    AVTranz.order.build_fancy_buttons('div#order-step-' + AVTranz.order.steps.last);

    $('a.order-step-' + AVTranz.order.steps.last + ', a.order-step-2')
      .bind('click', AVTranz.order.update_details);

    $('#edit-field-turnaroundtime-value, #multistep-group_formats input:checkbox')
      .bind('change', AVTranz.order.update_details);

    $('input#edit-field-numcopies-0-value')
      .bind('change', AVTranz.order.update_details);

    $('ul#form-steps li a')
      .each( function (index, value) { $(this).text( index + 1 ).addClass('numbered'); })
      .removeClass('active')
      .bind('click', AVTranz.order.step_click_handler)
      .filter('a.order-step-' + AVTranz.order.steps.current)
      .click();
  }
};
