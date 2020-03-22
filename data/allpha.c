allpha()
{

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

	/* пуск */

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

	/* новый ввод */

	/* второй ввод */

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

	return 0;
}