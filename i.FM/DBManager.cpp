////////////////////////////////////////////////////////////////////////////////
// Database Management
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "DBManager.h"
#include <cstdlib>

////////////////////////////////////////////////////////////////////////////////

DBManager::DBManager()
{
	const char* gszFile = "C:\\FireworksManager.db";
	remove(gszFile);
    myDB.open(gszFile);
	myDB.execDML("Create table Stock(Product_Code int primary key, Product_Category char(50), Product_Name char(300), Total_Quantity Bigint, Quantity_sold Bigint, Price float, Barcode Bigint);");
	myDB.execDML("Create table Billing(Date Datetime, Product_Code int, Product_Category char(50), Product_Name char(300), Barcode Bigint primary key, Price double, Quantity Bigint, Discount float, Additional_Discount float, Total_Cost double);");
}


DBManager::~DBManager()
{
	try
	{
		myDB.close();
	}
	catch (...)
	{
	}
}

void DBManager::InsertStock()
{
	myDB.execDML("insert into Stock values (005, 'SPARKLERS', 'Jimmi Gold Sparklers','10000', '0', '150','1020170001');");
	myDB.execDML("insert into Stock values (007, 'SPARKLERS', 'Gold Sparklers','10000', '0', '250','1020170002');");
	myDB.execDML("insert into Stock values (008, 'SPARKLERS', 'Gold Sparklers','10000', '0', '250','1020170003');");
	myDB.execDML("insert into Stock values (009, 'SPARKLERS', 'Standard Gold Sparklers','10000', '0', '250','1020170004');");
	myDB.execDML("insert into Stock values (010, 'SPARKLERS', 'Export Gold Sparklers','10000', '0', '250','1020170005');");
	myDB.execDML("insert into Stock values (029, 'SPARKLERS', 'Jimmy Crackling Sparklers','10000', '0', '250','1020170006');");
	myDB.execDML("insert into Stock values (030, 'SPARKLERS', 'Crackling Sparklers','10000', '0', '250','1020170007');");
	myDB.execDML("insert into Stock values (031, 'SPARKLERS', 'Crackling Sparklers','10000', '0', '250','1020170008');");
	myDB.execDML("insert into Stock values (032, 'SPARKLERS', 'Crackling Sparklers','10000', '0', '250','1020170009');");
	myDB.execDML("insert into Stock values (033, 'SPARKLERS', 'Export Crackling Sparklers','10000', '0', '250','1020170010');");
}