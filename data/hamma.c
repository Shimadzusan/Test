hamma()
{

	web_url("SAD", 
		"URL=http://localhost:8081/SAD/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=../favicon.ico", "Referer=", ENDITEM, 
		LAST);

	/* begin report */

	lr_think_time(21);

	web_custom_request("ServletReportMode", 
		"URL=http://localhost:8081/SAD/ServletReportMode", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:8081/SAD/", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		"Body=date_one=02.03.2020&date_two=10.03.2020&type_of_report=only one item", 
		LAST);

	/* press engage */

	lr_think_time(23);

	web_custom_request("ServletOneItem", 
		"URL=http://localhost:8081/SAD/ServletOneItem", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:8081/SAD/", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		"Body=date_x={\"itm\":\"ником сервис\",\"con\":\"days\",\"cas\":true,\"onl\":true,\"exp\":true,\"tot\":true}", 
		LAST);

	/* new item */

	lr_think_time(30);

	web_custom_request("ServletOneItem_2", 
		"URL=http://localhost:8081/SAD/ServletOneItem", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:8081/SAD/", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		"Body=date_x={\"itm\":\"пульты\",\"con\":\"days\",\"cas\":true,\"onl\":true,\"exp\":true,\"tot\":true}", 
		LAST);

	/* new report */

	lr_think_time(16);

	web_custom_request("ServletReportMode_2", 
		"URL=http://localhost:8081/SAD/ServletReportMode", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:8081/SAD/", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		"Body=date_one=02.03.2020&date_two=10.03.2020&type_of_report=online payment report", 
		LAST);

	lr_think_time(6);

	web_custom_request("ServletOnlineIncome", 
		"URL=http://localhost:8081/SAD/ServletOnlineIncome", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:8081/SAD/", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		"Body=data_s={\"con\":\"days\",\"sber\":true,\"tinkoff\":true,\"pochta_bank\":true,\"total\":true}", 
		LAST);

	return 0;
}