<?php
  drupal_add_css($directory .'/css/plupload.css');
  drupal_add_js($directory . '/js/plupload.js');
  if ( strcasecmp( t('delete files'), $_POST['op']) != 0 ) {
  ?>
    <div id="uploader">Your browser does not support HTML5 native or flash upload. Try Firefox 3, Safari 4, or Chrome; or install Flash.</div>
  <?php
 }