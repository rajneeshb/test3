<?php include("HOP.php") ?>
<script type="text/javascript" src="/sites/all/modules/contrib/jquery_update/replace/jquery.min.js?E"></script>

<h1>sample_product_name</h1>
<p>Here, you enter the description of your product.</p>
<script>
$(document).ready(function() { 
    $("#cspaymentform").submit(function(e) { //alert('hi');
				
			//$.get('preprocess.php', function(data) {
			//var test = data;
			//return true;
			//});
			
			 $.ajax( {
     type: "POST",
     url: "preprocess.php",
     success: function() {
			return true;
       }  
    });
		//alert('test');
			return true;
    });

    
});
function preprocess() {
//alert('begin');
//$.get('preprocess.php');
//setTimeout("alert('hello1')",1250);
//$.get('preprocess.php', function(data) {
  //we know it's being called when alert shows
 // alert('data: '+data);
 //var test = data;
//});
//setTimeout("alert('hello')",1250);
//return true;
}
</script>
<form id="cspaymentform" name="cspaymentform" action="https://orderpagetest.ic3.com/hop/orderform.jsp" method="post">
   <?php InsertSignature3("15","usd", "authorization")?> <!-- the 15 is the monetary value we want them to charge -->

   <input type="hidden" name="billTo_firstName" value="John">
   <input type="hidden" name="billTo_lastName" value="Doe">
   <input type="hidden" name="merchantDefinedData1" value="12345"> <!--this is the node id of the order -->

   <input type="submit" value="Buy Now">
</form>