var AVTranz = AVTranz || {};

AVTranz.successful_payment = false;

 Drupal.behaviors.SettleDeposit = function ($context) {
   $('form#cspaymentform', $context).submit( function (e) {
     var querystring = $(this).serialize();

     $.colorbox( {
       iframe: true,
       href: $(this).attr('action') + '?' + querystring,
       width: 575,
       height: 500,
       onCleanup: function () {
         if (AVTranz.successful_payment) {
           $('form#cspaymentform').hide();
           $('.balance_amount').hide();
           
           var redirect_location = '/order/' + $('form#cspaymentform input[name="order_id"]').val();
           if ( window.location.pathname != redirect_location ) {
             window.location = redirect_location;
           }
         }
       }
     } );

     $.post('/sites/all/libraries/paymentprocessing/preprocess.php', querystring);

     e.preventDefault();
     return false;
   } );
 };
