Drupal.behaviors.pluploadBuild = function ($context) {
  // Setup uploader pulling some info out Drupal.settings
  $('#uploader', $context)
   .pluploadQueue( {
     // General settings
     runtimes : 'html5,silverlight,browserplus,flash,html4',
     url : Drupal.settings.plupload.url,
     max_file_size :  Drupal.settings.plupload.max_file_size,
     chunk_size : '10mb',
     unique_names : false,
     flash_swf_url : Drupal.settings.plupload.swfurl,
     silverlight_xap_url : Drupal.settings.plupload.xapurl,

     // Specify what files to browse for
     filters : [
       { title : 'All files', extensions : '*' },
       { title : 'Court files', extensions: Drupal.settings.plupload.extensions }
     ]
    } );

  var totalUploadFiles = 0;
  var upload = $('#uploader').pluploadQueue();
  upload.bind('FileUploaded', function(up, file, res) {
    totalUploadFiles--;
    if(totalUploadFiles == 0) {

      var count = $('#uploader').pluploadQueue().total.uploaded;

      var successText = Drupal.formatPlural(count, 'Success! 1 file uploaded.', 'Success! @count files uploaded.');


      $('div.plupload_header').slideUp('slow', function() {
        $('div.plupload_header').html('<h3>'+ successText +'</h3>').slideDown('slow');
      });

      $('a.edit-order .fancy-button-text-wrap').text('View Order');

      setTimeout(function () {
        // Breaks javascript for bulk operations
        //$('form#views-exposed-form-uploaded-order-files-block-1').submit();  // Refresh file list
        window.location.href = window.location.href;
      }, 750);

    }
  });

  upload.bind('QueueChanged', function(up, files) {
    totalUploadFiles = upload.files.length;
  });

  upload.bind('UploadComplete', function(up, files) {
    up.splice();  // Remove old files in the list
    $('.plupload_upload_status')
      .show()
      .css('display', 'inline');
    $('.plupload_buttons')
      .show()
      .css('display', 'inline');

    $(window).unbind('beforeunload');
  });

  upload.bind('UploadFile', function (up, files) {
    $(window).bind('beforeunload', function (e) {
      e.stopImmediatePropagation();
      e.preventDefault();

      return 'Your download will be lost if you continue.';
    });

    $('a.edit-order .fancy-button-text-wrap')
      .text('Stop Upload')
      .click( function (e) {
        upload.stop();

        window.location.href = window.location.href;

        e.preventDefault();
        return false;
      });
  });
};