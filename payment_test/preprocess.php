<? 
$path = getcwd();
$file_name= $path . "/payment_test/payment_preprocess_log.txt";
if(file_exists($file_name))
{
	//open file for writng and place pointer at the end
	$handle = fopen($file_name, 'a+');

	if(!$handle)
	{
		die("couldn't open file <i>$file_name</i>");
		
	}
	
	fwrite($handle, "begin"."\r\n");
	
	fwrite($handle, "nodeID"."\r\n");
	fwrite($handle, "IP"."\r\n");
	fwrite($handle, "Time/Date"."\r\n");
	fwrite($handle, "UserID"."\r\n");
	fwrite($handle, "Price"."\r\n");
	fwrite($handle, "Useragent"."\r\n");
	
	fwrite($handle, "end\r\n");
	echo "success writing to file";
}
else
{
	echo "file <i>$file_name</i> doesn't exists";
	
}
fclose($handle);
?>
false