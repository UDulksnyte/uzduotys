//
// Created by 37067 on 6/1/2022.
//

#ifndef DATABASESSQLITESTARTER_DATABASE_H
#define DATABASESSQLITESTARTER_DATABASE_H
#include "sqlite3.h"
#include "Product.h"
#include <iostream>
#include <vector>
using namespace std;
void message(string messageText);

class Database {
public:
    static sqlite3 *Connect(const string &path);
    static void CreateTable(sqlite3 *db,string sql);
    static void Insert(sqlite3 *db,const Product &product);
    static void Display(sqlite3 *db);
    static int Callback(void* context,  // user-provided object (4th param to sqlite3_exec)
                        int columnCount,      // number of columns
                        char** columnValues,  // array of column values as C-style strings
                        char** columnName);    // array of column names as C-style strings);
    static string selectData(sqlite3 *db,string tableNm);
    static void executeSql(sqlite3 *db,string SQL);
    string tableData(string TABLE);
    string tblName(string tableName);
};

const string dbName="products.db";
#endif //DATABASESSQLITESTARTER_DATABASE_H
