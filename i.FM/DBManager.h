////////////////////////////////////////////////////////////////////////////////
// Database Management
////////////////////////////////////////////////////////////////////////////////
#ifndef _DBManager_H_
#define _DBManager_H_

#include "DBWrapper\CppSQLite3.h"
#include <cstdio>
#include <cstring>

#define CPPSQLITE_ERROR 1000

class DBManager
{
public:

    DBManager();

    virtual ~DBManager();

	void InsertStock();
private:

    CppSQLite3DB myDB;
};

#endif
