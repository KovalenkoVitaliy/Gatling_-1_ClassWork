Action()
{

	web_url("computers", 
		"URL=http://computer-database.gatling.io/computers", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_url("Add a new computer", 
		"URL=http://computer-database.gatling.io/computers/new", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://computer-database.gatling.io/computers", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=https://c.urs.microsoft.com/l1.dat?cw=637194112741176080&v=3&cv=9.11.18362.0&os=10.0.18363.0.0&pg=4A72F430-B40C-4D36-A068-CE33ADA5ADF9", "Referer=", ENDITEM, 
		LAST);

	web_set_sockets_option("SSL_VERSION", "TLS1.2");

	web_add_header("UA-CPU", 
		"AMD64");

	web_url("iecompatviewlist.xml", 
		"URL=https://iecvlist.microsoft.com/IE11/1478281996/iecompatviewlist.xml?cvlp=5168446610543477570", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t3.inf", 
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
		"Name=name", "Value=NameVitKov", ENDITEM, 
		"Name=introduced", "Value=2012-12-12", ENDITEM, 
		"Name=discontinued", "Value=2020-12-12", ENDITEM, 
		"Name=company", "Value=1", ENDITEM, 
		LAST);

	lr_think_time(26);

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
		"Name=f", "Value=NameVitKov", ENDITEM, 
		LAST);

	lr_think_time(6);

	web_url("NameVitKov", 
		"URL=http://computer-database.gatling.io/computers/2744", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://computer-database.gatling.io/computers?f=NameVitKov", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	web_submit_data("delete", 
		"Action=http://computer-database.gatling.io/computers/2744/delete", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://computer-database.gatling.io/computers/2744", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		LAST);

	return 0;
}