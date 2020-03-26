betta()
{

	web_url("SAD", 
		"URL=http://localhost:8081/SAD/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=../favicon.ico", "Referer=", ENDITEM, 
		LAST);

	/* first confirm */

	lr_think_time(10);
	
	lr_start_transaction("операция3:_classical_report");

	web_custom_request("ServletReportMode",
		"URL=http://localhost:8081/SAD/ServletReportMode", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:8081/SAD/", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		"Body=date_one=02.03.2020&date_two=10.03.2020&type_of_report=classical report", 
		LAST);
	
	lr_end_transaction("операция3:_classical_report", LR_AUTO);
	
	lr_start_transaction("операция4:_standart_report");

	web_submit_data("ServletClassicalReport", 
		"Action=http://localhost:8081/SAD/ServletClassicalReport", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://localhost:8081/SAD/", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=data_s", "Value=StandartChiefReport", ENDITEM, 
		LAST);
	
	lr_end_transaction("операция4:_standart_report", LR_AUTO);

	/* на операцию confirm затрачивается два метода: web_custom_request and web_submit_data */

	lr_think_time(54);

	web_custom_request("ServletReportMode_2",	//..Allows you to create a custom HTTP request with any method supported by HTTP. 
		"URL=http://localhost:8081/SAD/ServletReportMode", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:8081/SAD/", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		"Body=date_one=03.03.2020&date_two=05.03.2020&type_of_report=classical report", 
		LAST);

	web_submit_data("ServletClassicalReport_2",	//..Performs an "unconditional" or "contextless" form submission. 
		"Action=http://localhost:8081/SAD/ServletClassicalReport", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://localhost:8081/SAD/", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=data_s", "Value=StandartChiefReport", ENDITEM, 
		LAST);

	return 0;
}