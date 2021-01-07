Action1()
{
		lr_start_transaction("start");
	
		web_url("Add a new computer", 
		"URL=http://computer-database.gatling.io/computers/new", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://computer-database.gatling.io/computers", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);


	web_submit_data("computers_2", 
		"Action=http://computer-database.gatling.io/computers", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://computer-database.gatling.io/computers/new", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=name", "Value={NameComp}", ENDITEM, 
		"Name=introduced", "Value={Date1}", ENDITEM, 
		"Name=discontinued", "Value={DateTask1}", ENDITEM, 
		"Name=company", "Value=1", ENDITEM, 
		LAST);
		
		lr_end_transaction("start", LR_AUTO);

	
	return 0;
}
