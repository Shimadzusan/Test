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
	/* first transaction: тестируем операцию "вывод отчетности по одной позиции" (only one item) */
//begin transaction
	lr_start_transaction("операция1:_only_one_item");

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
		LAST);	//..отправили запрос на сервер, но в http-response ничего нет, т.к. наблюдаемые в browser вычисления производятся на стороне клиента(java_script) толстый клиент

	/* press engage, это часть операции only one item */

	lr_think_time(23);	//..тупим, думаем, что-то вводим и т.д.

	web_reg_save_param_ex(	//..всегда только над запросом!
		"ParamName=newParam", 
	    "LB/IC=02",
	    "RB/IC=2020",
//	    "Ordinal=all",
//	    "SaveLen=-1",
//	    "DFEs=UrlEncoding",
	    SEARCH_FILTERS,
	        "Scope=body",
		LAST);
	
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

	lr_output_message("here we displays some value from response:");
	lr_output_message(lr_eval_string("{newParam}"));

//end transaction!!!
	lr_end_transaction("операция1:_only_one_item", LR_AUTO);

	/* new item первая операция (only one item) закончилась, началась вторая почти такая же, но чуть другая*/

	lr_start_transaction("операция2:_only_one_item");
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
	lr_end_transaction("операция2:_only_one_item", LR_AUTO);

	return 0;
}