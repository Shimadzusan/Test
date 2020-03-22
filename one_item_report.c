one_item_report()
{
	web_url("SAD", 
		"URL=http://localhost:8081/SAD/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=../favicon.ico", "Referer=", ENDITEM, 
		LAST);

	/* begin report */
	/* first transaction: тестируем операцию "вывод отчетности по одной позиции" (only one item) */
//begin transaction

	lr_think_time(21);

	web_custom_request("ServletReportMode", 
		"URL=http://localhost:8081/SAD/ServletReportMode", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:8081/SAD/", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		"Body=date_one=02.03.2020&date_two=10.03.2020&type_of_report=only one item", 
		LAST);

	/* press engage, это часть операции only one item */

	lr_think_time(23);	//..тупим, думаем, что-то вводим и т.д.

	web_custom_request("ServletOneItem", 
		"URL=http://localhost:8081/SAD/ServletOneItem", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:8081/SAD/", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		"Body=date_x={\"itm\":\"ником сервис\",\"con\":\"days\",\"cas\":true,\"onl\":true,\"exp\":true,\"tot\":true}", 
		LAST);
	
//end transaction!!!
	/* new item первая операция (only one item) закончилась, началась вторая такая же...*/
	return 0;
}
