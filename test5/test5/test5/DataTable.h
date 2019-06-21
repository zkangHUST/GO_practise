#pragma once
#include "sqlite3.h"
#include <string>
#include <vector>

struct MailRec {
    int mailId;
    std::string from;
    std::string to;
    std::string subject;
    int date;
    MailRec() {
        mailId = -1;
        from = "vicent";
        to = "kang";
        subject = "NULL";
        date = 20190621;
    }
};
class DataTable {
public:
    DataTable();
    ~DataTable();
    void createTable();
    void attachDB();
    bool addMail(const MailRec& item);
    bool addMail(const std::vector<MailRec>& items);

private:
    std::string getInsertSingleRecSql(const MailRec& item);
    
private:
    std::string  mTableName;
    sqlite3		*mDb;
};
