#include "IndexTable.h"
#include <iostream>
#include <sstream>
using std::cout;
using std::endl;
using std::string;

#define ERRCHECK {if (err!=NULL) {printf("%s\n",err); sqlite3_free(err);  return 0;}}

IndexTable::IndexTable()
{
    mTableName = "IndexTable";
    mDb = NULL;
}


void IndexTable::attachDB()
{
    int rc = sqlite3_open("test.db", &mDb);
    if (rc != SQLITE_OK) {
        cout << "open test.db error " << endl;
        return ;
    }
    createTable();
}
void IndexTable::createTable()
{
    string  sql = "create virtual table if not exists ";
    sql += mTableName;
    sql += 
        " using fts4("
        "content='MailData', mailId, mailFrom, mailTo, subject,"
         "notindexed=mailId, notindexed=mailFrom, notindexed=mailTo, notindexed=subject"
         ");";

    int rc = sqlite3_exec(mDb, sql.c_str(), NULL, NULL, NULL);
    
    if (rc != SQLITE_OK) {
        cout << "create index table error!" << endl;
    }

    // create trigger
    sql =
        "CREATE TRIGGER IF NOT EXISTS ai AFTER INSERT "
        "ON mailData "
        "BEGIN "
        "INSERT INTO IndexTable(docid, mailId, mailFrom,"
        "mailTo, subject) VALUES(new.rowid, new.mailId, new.mailFrom, "
        "new.mailTo, new.subject);"
        " END;";
    
     rc = sqlite3_exec(mDb, sql.c_str(), NULL, NULL, NULL);

    if (rc != SQLITE_OK) {
        cout << "create index table trigger error!" << endl;
    }
}


IndexTable::~IndexTable()
{

}




