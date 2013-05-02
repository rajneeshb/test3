/**/


$(document).ready(function() {	

$('#pid-allavailableplans .main-content-inner  h1.title').append('<a class="apply-now" href="https://www.bcidaho.com/bci_v2/plans/os_IdahoIndividualApplication/IndApp_Step0b_Terms.aspx" target="_new"><span>Apply Now</span></a>')

	$('#content-tabs').prepend ('<div class="more-link">Looking for <a class="group" href="https://www.bcidaho.com/plans/employer_sponsored/index.asp" target="_blank">group</a> or <a class="short-term" href="https://www.bcidaho.com/plans/individual/STB.asp" target="_blank">short-term</a> coverage?</div>');
	
	$('.quicktabs_tabpage').prepend('<img src="/sites/bcidaho.ddev.mcmurryis.com/themes/fusion/fusion_starter/images/tab-content-top.gif" width="945" height="5" />');
	$('.quicktabs_tabpage').append('<img src="/sites/bcidaho.ddev.mcmurryis.com/themes/fusion/fusion_starter/images/tab-content-bottom.gif" width="945" height="5" />');
	
	$('#planpicker-nameform div:nth-child(1)').addClass('list-wrapper');
	$('#planpicker-nameform div div').removeClass('list-wrapper');
	
	$('#planpicker-nameform div.list-wrapper div').addClass('list-item');
	
	$('#planpicker-nameform div.list-wrapper div div').removeClass('list-item');
	
	$('.center-wrapper .panel-col-first .min-max').wrapAll('<div class="min-max-wrapper">');
	$('.center-wrapper .panel-col .min-max').wrapAll('<div class="min-max-wrapper">');
	$('.center-wrapper .panel-col-last .min-max').wrapAll('<div class="min-max-wrapper">');
	
	$('.center-wrapper .panel-panel .inside .field-type-number-decimal:even .field-item').append("&mdash;&nbsp;");
	$('.center-wrapper .panel-panel .inside .field-type-number-decimal:odd .field-item').append("<span>per month</span>");
	
	
	$('.form-submit').hover(
  function () {
    $(this).addClass("hover");
  },
  function () {
    $(this).removeClass("hover");
  }
);
	/*iterate through list items*/
			
    $( "#pid-planpicker-single .list-item, #pid-planpicker-family .list-item" ).each(function( intIndex ){
     

    $(this).prepend ("<span class=\"numbered\">" + [intIndex+1] +".</span>");
    
	});
	
	
	$( ".page-brokersearch #content-region .form-item" ).each(function( intIndex ){
     

    $(this).addClass ("form-el-" + [intIndex+1]);
    
	});
	
	$( ".page-brokersearch #content-region label" ).each(function( intIndex ){
     

    $(this).addClass ("label-el-" + [intIndex+1]);
    
	});
	
	
     
	$('#content-tabs-inner .field-content a').addClass('lightbox-processed').attr('rel, "lightframe[|width=450px;height=300px;scrolling=auto;]"');
	
	
	
	//replace value of form.
	
	$('#brokersearch-nameform .form-el-4 input.form-text').val('Enter the first few letters of the broker\'s last name.');
	
	$('#brokersearch-nameform .form-el-4 input.form-text').focus(function(){
	var newValue = $(this).val();
		if($(this).val() == 'Enter the first few letters of the broker\'s last name.'){
				$(this).attr('value','');
			} else {
				$(this).val(newValue);
		}
	});

	$('#brokersearch-nameform .form-el-4 input.form-text').blur(function(){
		var newValue = $(this).val();
			if($(this).val() == ''){
				$(this).attr('value','Enter the first few letters of the broker\'s last name.');
			} else {
				$(this).val(newValue);
		}
	});
	
	$('.page-brokersearch #content-region #brokersearch-nameform input.form-submit').val('');
	
	$('.page-brokersearch #content-region .brokerrequest .modifysearch a').wrapInner('<span>');
	
});







