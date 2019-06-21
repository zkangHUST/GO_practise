#include "sqlite3.h"
#include <iostream>
#include<string>
#include<vector>
#define	ERROR  -1
#define	DEBUG   1
using namespace std;
int callfunc(void * data, int argc, char ** argv, char **zaColName);
int main(int argc , char *argv[])
{
	sqlite3		*db;
	char		*zErrMsg = 0;
	int			rc;
	const char  *data = "Callback function called", *sqlcommand;

	// create or open a test db.
	rc = sqlite3_open("test.db", &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return ERROR;
	}
#if 0	
	// create a virtual table.
	sqlcommand = "CREATE virtual table namelist using fts4(name, age, job);";
	rc = sqlite3_exec(db, sqlcommand, callfunc, NULL, &zErrMsg);
	if (rc != SQLITE_OK) {
		cout << "create table namelist failed" << endl;
		sqlite3_free(zErrMsg);
	}

	// insert some data.
	vector<string> list;
	// = {string("\"zhengkang\", 26, \"programmer\");"), string("\"erli\", 27, \"designer\");")};// string("\"vincent\", 26, \"doctor\");")};
	list.push_back("\"zhengkang\", 26, \"programmer\");");
	list.push_back("\"erli\", 27, \"designer\");");
	list.push_back("\"vincent\", 26, \"doctor\");");
	list.push_back("'windows', 40, 'operation system');");
	list.push_back("'linux', 40, 'operation system');");

	string prefix = "insert into namelist(name, age, job) values(";
	for(vector<string>::iterator it = list.begin(); it != list.end(); it++) {
		string tmp = prefix + *it;
		sqlcommand = tmp.c_str();
		cout << sqlcommand << endl;
		rc = sqlite3_exec(db, sqlcommand, callfunc, NULL, &zErrMsg);
		if (rc != SQLITE_OK) {
			cout << "insert data failed" << endl;
			sqlite3_free(zErrMsg);
		}
	}
#endif

	// Simple FTS Queries
	sqlcommand = "select * from namelist where name match 'Bob'";
	rc = sqlite3_exec(db, sqlcommand, callfunc, (void*)data, &zErrMsg);
	if (rc != SQLITE_OK) {
		cout << "search error" << endl;
		sqlite3_free(zErrMsg);
	}
	cout << "--------------------------------------" << endl;
	
	// find item who's age is 30.
	sqlcommand = "select * from namelist where age match 30;";
	rc = sqlite3_exec(db, sqlcommand, callfunc, (void*)data, &zErrMsg);
	if (rc != SQLITE_OK) {
		cout << "search error" << endl;
		sqlite3_free(zErrMsg);
	}
	cout << "--------------------------------------" << endl;
	
	// full text search, the text is a prefix with a * append to it.
	sqlcommand = "select * from namelist where name match \"linux*\";";
	rc = sqlite3_exec(db, sqlcommand, callfunc, (void*)data, &zErrMsg);
	if (rc != SQLITE_OK) {
		cout << "search error" << endl;
		sqlite3_free(zErrMsg);
	}
	cout << "--------------------------------------" << endl;

	// find name matchs "linux*" and the term 40 appears in either the name or age or job of the table.
	sqlcommand = "select * from namelist where namelist match 'name:linux* 40';";
	rc = sqlite3_exec(db, sqlcommand, callfunc, (void*)data, &zErrMsg);
	if (rc != SQLITE_OK) {
		cout << "search error" << endl;
		sqlite3_free(zErrMsg);
	}
	cout << "--------------------------------------" << endl;
	
	// search item who's name matchs "linux*" and who's job matchs "operation"
	sqlcommand = "select * from namelist where job match 'name:linux* operation'";
	rc = sqlite3_exec(db, sqlcommand, callfunc, (void*)data, &zErrMsg);
	if (rc != SQLITE_OK) {
		cout << "search error" << endl;
		sqlite3_free(zErrMsg);
	}

	// search item who's name match "^Bob".
	cout << "--------------------------------------" << endl;
	sqlcommand = "select * from namelist where namelist match '^Bob'";
	rc = sqlite3_exec(db, sqlcommand, callfunc, (void*)data, &zErrMsg);
	if (rc != SQLITE_OK) {
		cout << "search error" << endl;
		sqlite3_free(zErrMsg);
	}

	// search item who's name match "^Lin*".
	cout << "--------------------------------------" << endl;
	sqlcommand = "select * from namelist where namelist match '^Lin*';";
	rc = sqlite3_exec(db, sqlcommand, callfunc, (void*)data, &zErrMsg);
	if (rc != SQLITE_OK) {
		cout << "search error" << endl;
		sqlite3_free(zErrMsg);
	}

	// search phrase that contain a nominated set of terms or term prefixes in a specified order with no intervening tokens.
	cout << "--------------------------------------" << endl;
	sqlcommand = "select * from namelist where namelist match \"oper* sys*\";";
	rc = sqlite3_exec(db, sqlcommand, callfunc, (void*)data, &zErrMsg);
	if (rc != SQLITE_OK) {
		cout << "search error" << endl;
		sqlite3_free(zErrMsg);
	}

#if 0
	sqlcommand = "CREATE virtual table docs using fts4();";
	rc = sqlite3_exec(db, sqlcommand, callfunc, (void*)data, &zErrMsg);
	if (rc != SQLITE_OK) {
		cout << "search error" << endl;
		sqlite3_free(zErrMsg);
	}
	sqlcommand = "insert into docs values('FTS3 and FTS4 are SQLite virtual table modules that allows users to perform full-text searches on a set of documents.')";
	rc = sqlite3_exec(db, sqlcommand, callfunc, (void*)data, &zErrMsg);
	if (rc != SQLITE_OK) {
		cout << "search error" << endl;
		sqlite3_free(zErrMsg);
	}
#endif
	// NEAR queries, put the key word NEAR between two or more terms(or phrases). 
	cout << "--------------------------------------" << endl;
	sqlcommand = "select * from docs where docs match 'FTS3 NEAR documents';";
	rc = sqlite3_exec(db, sqlcommand, callfunc, (void*)data, &zErrMsg);
	if (rc != SQLITE_OK) {
		cout << "search error" << endl;
		sqlite3_free(zErrMsg);
	}

	cout << "--------------------------------------" << endl;
	sqlcommand = "select * from docs where docs match ' FTS3 NEAR/20 documents';";
	rc = sqlite3_exec(db, sqlcommand, callfunc, (void*)data, &zErrMsg);
	if (rc != SQLITE_OK) {
		cout << "search error" << endl;
		sqlite3_free(zErrMsg);
	}

	cout << "--------------------------------------" << endl;
	sqlcommand = "select * from docs where docs match ' documents NEAR/20 FTS3';";
	rc = sqlite3_exec(db, sqlcommand, callfunc, (void*)data, &zErrMsg);
	if (rc != SQLITE_OK) {
		cout << "search error" << endl;
		sqlite3_free(zErrMsg);
	}

	cout << "--------------------------------------" << endl;
	sqlcommand = "select * from docs where docs match '\"virtual table\" NEAR/10 \"a set of\"';";
	rc = sqlite3_exec(db, sqlcommand, callfunc, (void*)data, &zErrMsg);
	if (rc != SQLITE_OK) {
		cout << "search error" << endl;
		sqlite3_free(zErrMsg);
	}

	// AND operator 
	cout << "--------------------------------------" << endl;
	sqlcommand = "select * from docs where docs match 'ACID AND database';";
	rc = sqlite3_exec(db, sqlcommand, callfunc, (void*)data, &zErrMsg);
	if (rc != SQLITE_OK) {
		cout << "search error" << endl;
		sqlite3_free(zErrMsg);
	}

	// OR operator 
	cout << "--------------------------------------" << endl;
	sqlcommand = "select * from docs where docs match 'ACID OR system';";
	rc = sqlite3_exec(db, sqlcommand, callfunc, (void*)data, &zErrMsg);
	if (rc != SQLITE_OK) {
		cout << "search error" << endl;
		sqlite3_free(zErrMsg);
	}
	
	// NOT operator 
	cout << "--------------------------------------" << endl;
	sqlcommand = "select * from docs where docs match 'ACID NOT system';";
	rc = sqlite3_exec(db, sqlcommand, callfunc, (void*)data, &zErrMsg);
	if (rc != SQLITE_OK) {
		cout << "search error" << endl;
		sqlite3_free(zErrMsg);
	}
	getchar();
	return 0;
}

int callfunc(void * data, int argc, char ** argv, char **zaColName)
{
	for (int i = 0; i < argc; i++) {
		cout << zaColName[i]  << " "<< argv[i] << endl;
	}
	return 0;
}