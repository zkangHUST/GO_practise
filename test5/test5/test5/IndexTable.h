#pragma once
#include "sqlite3.h"
#include <string>

class IndexTable {
public:
    IndexTable();
    ~IndexTable();
    void createTable();
    void attachDB();

private:
    std::string  mTableName;
    sqlite3		*mDb;
};
