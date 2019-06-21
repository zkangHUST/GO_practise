#include "DataTable.h"
#include <iostream>
#include <vector>
#include <sstream>
using std::cout;
using std::vector;
using std::endl;
using std::string;
#define ERRCHECK {if (err!=NULL) {printf("%s\n",err); sqlite3_free(err);  return 0;}}

DataTable::DataTable()
{
    mTableName = "MailData";
    mDb = NULL;
}


void DataTable::attachDB()
{
    int rc = sqlite3_open("test.db", &mDb);
    if (rc != SQLITE_OK) {
        cout << "open test.db error " << endl;
        return ;
    }
    createTable();
}
void DataTable::createTable()
{
    string  sql = "create table if not exists ";
    sql += mTableName;
    sql += 
    "("
    "idx integer primary key, "
    "mailID integer unique,"
    "mailFrom text,"
    "mailTo text,"
    "subject text,"
    "internalDate integer64 default 0"
    ");";
    
    int rc = sqlite3_exec(mDb, sql.c_str(), NULL, NULL, NULL);
    
    if (rc != SQLITE_OK) {
        cout << "create data table error!" << endl;
    }
}

bool DataTable::addMail( const MailRec& item )
{
    char *err = 0;
    string sql = "insert or replace into ";
    sql += mTableName;
    sql += " (mailID, mailFrom, mailTo, subject, internalDate) values(";
    std::ostringstream id;
    id << item.mailId;
    sql += id.str(); 
    sql += ",'";
    sql += item.from;
    sql += "','";
    sql += item.to;
    sql += "','";
    sql += item.subject;
    sql += "',";
    std::ostringstream date;
    date << item.date;
    sql += date.str();
    sql += ");";
    
    int rc = sqlite3_exec(mDb, sql.c_str(), NULL, NULL, &err);
    ERRCHECK
    return true;
}

bool DataTable::addMail( const std::vector<MailRec>& items )
{
    char *err = 0;
    string sql = "insert or replace into ";
    sql += mTableName;
    sql += " (mailID, mailFrom, mailTo, subject, internalDate) values";
    for (int i = 0; i < items.size(); i++) {
        sql += getInsertSingleRecSql(items[i]);
        if (i + 1 < items.size()) {
            sql += ",";
        }
    }
    sql += ";";

    int rc = sqlite3_exec(mDb, sql.c_str(), NULL, NULL, &err);
    ERRCHECK
    return true;

}


DataTable::~DataTable()
{
    
}

string DataTable::getInsertSingleRecSql(const MailRec& item)
{
    string sql = "(";
    std::ostringstream id;
    id << item.mailId;
    sql += id.str(); 
    sql += ",'";
    sql += item.from;
    sql += "','";
    sql += item.to;
    sql += "','";
    sql += item.subject;
    sql += "',";
    std::ostringstream date;
    date << item.date;
    sql += date.str();
    sql += ")";
    return sql;
}




