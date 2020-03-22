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

	/* report from 3 to 7 */

	lr_think_time(54);

	web_custom_request("ServletReportMode_2", 
		"URL=http://localhost:8081/SAD/ServletReportMode", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:8081/SAD/", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		"Body=date_one=03.03.2020&date_two=07.03.2020&type_of_report=classical report", 
		LAST);

	web_submit_data("ServletClassicalReport_2", 
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