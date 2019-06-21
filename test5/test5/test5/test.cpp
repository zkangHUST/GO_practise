#include "DataTable.h"
#include "IndexTable.h"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    DataTable mail;
    mail.attachDB();
    IndexTable index;
    index.attachDB();
    MailRec a;
    vector<MailRec> vec;
    int size;
    cin >> size;
    for (int i = 0; i < size; i++) {
        a.mailId = i;
        vec.push_back(a);
    }
    mail.addMail(vec);
    //while(1) {
    //    cin >> a.mailId;
    //    if (a.mailId == "null") {
    //        break;
    //    }     
    //    mail.addMail(a);
    //}
    return 0;
}