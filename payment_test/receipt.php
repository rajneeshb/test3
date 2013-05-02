<?php include("HOP.php");?>

<h3>Sample PHP Receipt Page</h3>

<table border="1">
<tr><td><b>Field Name</b></td><td><b>Field Value</b></td></tr>

<?php

while(list($key, $val) = each($_POST))
{
   echo '<tr><td>' . $key . '</td><td>' . $val . "</td></tr>";
}

echo '<tr><td>VerifyTransactionSignature()</td><td>' . VerifyTransactionSignature($_POST) . '</td></tr>';

?>

</table>