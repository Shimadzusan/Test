allpha()
{
	/* загрузка страницы */
	
	web_url("SAD", 
		"URL=http://localhost:8081/SAD/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=../favicon.ico", "Referer=", ENDITEM, 
		LAST);

	/* уже ввели текст, секунд 30 и нажали "пуск" */

	lr_think_time(28);

	web_custom_request("ServletStandartMode", 
		"URL=http://localhost:8081/SAD/ServletStandartMode", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:8081/SAD/", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		"Body=facture=26.03.2020\nкасса утро 5000\nфнд 250\nкопия 100 сбер", 
		LAST);

	/* новый ввод, сервер это никак не видит, окл 70 секунд что-то вводили */

	/* второй пуск */

	lr_think_time(72);

	web_custom_request("ServletStandartMode_2", 
		"URL=http://localhost:8081/SAD/ServletStandartMode", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:8081/SAD/", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		"Body=facture=26.03.2020\nкасса утро 5000\nфнд 250\nкопия 100 сбер\nпечать 200\nрамка 150", 
		LAST);
	
	/* третий пуск, генерирую сам в LR */
	
	lr_think_time(120);	//..что вводим 120 секунд
	
	web_custom_request("ServletStandartMode_2", 
		"URL=http://localhost:8081/SAD/ServletStandartMode", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:8081/SAD/", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		"Body=facture=28.03.2020\nкасса утро 5000\nфнд 250\nкопия 100 сбер\nпечать 200\nрамка 150\nфнд 250\nбагет 1900 сбер\nпечать 200\nрамка 150",	//..параметризация 
		LAST);

	return 0;
}