(function ($) {

  Drupal.behaviors.order_confidential_button = function ($context) {

    $('.confidential_button :not(.confiendtial-processed)', $context)
      .addClass('confiendtial-processed')
      .unbind('click')
      .attr('onclick', '')
      .bind('click', function (e) {
        var confi_url = $(this).attr('href');
        var confirm_message = 'This transcript is confidential.  Only a person who is a party to the case, or who otherwise has been authorized by the court where the proceeding occurred or by the Supreme Court, may receive this transcript.  If you are not a party or you have not been authorized by a court to receive the transcript, you may not download the transcript.  Accessing a confidential transcript without permission may be a criminal offense or be the basis for a civil penalty.  If you are authorized to receive the transcript, you are required to keep the transcript confidential and you are not permitted to provide a copy of the transcript to any other person.  Providing a confidential transcript to another person may be a crime or be the basis for a civil penalty.';
        $.alerts.okButton = "&nbsp;Accept&nbsp;";
        $.alerts.cancelButton = "&nbsp;Deny&nbsp;";
        jConfirm(confirm_message,'Confidential Transcript', function(r) {
          if(r){
            	window.location.href = confi_url;
          }
	});

        e.preventDefault();
        return false;
      });
  }
})(jQuery);
