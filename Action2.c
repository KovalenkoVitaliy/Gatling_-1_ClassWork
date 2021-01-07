Action2()
{
		lr_start_transaction("start");
	
		web_reg_save_param_ex(
		"ParamName=CompId",
		"LB=<td><a href=\"/computers/",
		"RB=\">",
		"Ordinal=1",
		SEARCH_FILTERS,
		LAST);
	
	
	web_submit_data("computers_3", 
		"Action=http://computer-database.gatling.io/computers", 
		"Method=GET", 
		"EncType=", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://computer-database.gatling.io/computers", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=f", "Value={NameComp}", ENDITEM, 
		LAST);

	lr_think_time(6);
	
	lr_output_message("COMP ID IS PIDRILO DYRIVYI %s", lr_eval_string("{CompId}"));

	web_url("NameVitKov", 
		"URL=http://computer-database.gatling.io/computers/{CompId}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://computer-database.gatling.io/computers?f={NameComp}", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	web_submit_data("delete", 
		"Action=http://computer-database.gatling.io/computers/{CompId}/delete", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://computer-database.gatling.io/computers/{CompId}", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		LAST);
	
	lr_end_transaction("start", LR_AUTO);

	
	return 0;
}
