<?php

/**
 * randomly select an image from the current directory and return
 * a CSS style to reference it.
 *
 * @todo - consider accepting a local path as $_GET['img'] for overrides
 * to remain compatible with Marinelli's rotate.php
 * 
 */

$file_types = array( 'gif', 'jpg', 'jpeg', 'png') ;

$regex = '/\.(' . implode('|',$file_types) . ')$/i' ;
$files = array() ;

$directory = opendir(".");
while ( FALSE !== ($file = readdir( $directory )) ) {
  if ( preg_match( $regex, $file ) ) {
    $files[] = $file ;
  }
}

if ( !empty( $files ) ) {

  $which   = rand(0,sizeof($files)-1) ;
    
  header( "Content-type: text/css" ) ;
  header( "Expires: Wed, 29 Jan 1975 04:15:00 GMT" );
  header( "Last-Modified: " . gmdate("D, d M Y H:i:s") . " GMT" );
  header( "Cache-Control: no-cache, must-revalidate" );
  header( "Pragma: no-cache" );

  print "#block-block-9 {background: url(" . $files[$which] . ") no-repeat 0px 0px;}";

}
