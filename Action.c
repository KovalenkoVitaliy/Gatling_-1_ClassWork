Action()
{

	lr_start_transaction("start");
	
	web_add_auto_header("X-GW-Host", "127.0.0.1:9080");
	web_add_auto_header("X-Forwarded-For","10.116.224.196");
	
	web_url("computers", 
		"URL=http://computer-database.gatling.io/computers", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("start", LR_AUTO);

	return 0;
}