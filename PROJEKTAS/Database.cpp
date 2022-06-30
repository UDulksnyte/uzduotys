//
// Created by 37067 on 6/1/2022.
//
#include "Database.h"
void message(string messageText){
cout<<messageText<<endl;
}
sqlite3 *Database::Connect(const string &path) {
    sqlite3 *db;
    sqlite3_open(path.c_str(), &db);
    if (db == nullptr) {
        cout << "Could not open database." << endl;
        return nullptr;
    } else {
        cout << "Connected to database successfully!!!" << endl;
        return db;
    }
}

int Database::Callback(void *context, int columnCount, char **columnValues, char **columnName) {

    for (int i = 0; i < columnCount; i++) {
        cout << columnValues[i] << " ";
    }
    cout << endl;

    return 0;
}

void Database::Insert(sqlite3 *db,const Product &product) {
    sqlite3_stmt *statment;
    string sql;
    sql = "insert into PRODUCTS VALUES (?,?,?,?,?,?)";
    char *zErrMsg = nullptr;
    sqlite3_exec(db,sql.c_str(),Callback, nullptr, &zErrMsg);
    if (sqlite3_prepare_v2(db,
                           sql.c_str(),
                           -1,
                           &statment,
                           nullptr)
        != SQLITE_OK) {

    }
    if (sqlite3_bind_null(
            statment,
            1  // Index of wildcard
    ) != SQLITE_OK) {
        printf("\nCould not bind double.\n");
        return;
    }
    if (sqlite3_bind_text(
            statment,
            2,  // Index of wildcard
            product.GetName().c_str(), // Data as -> const * char
            product.GetName().length(), // Data length
            SQLITE_STATIC
    ) != SQLITE_OK) {
        printf("\nCould not bind double.\n");
        return;
    }
    if (sqlite3_bind_text(
            statment,
            3,  // Index of wildcard
            product.GetDescription().c_str(), // Data as -> const * char
            product.GetDescription().length(), // Data length
            SQLITE_STATIC
    ) != SQLITE_OK) {
        printf("\nCould not bind double.\n");
        return;
    }
    if (sqlite3_bind_double(
            statment,
            4,  // Index of wildcard
            product.GetPrice()
    ) != SQLITE_OK) {
        printf("\nCould not bind int.\n");
        return;
    }

    if (sqlite3_step(statment) != SQLITE_DONE) {
        printf("\nCould not step (execute) stmt.\n");
        return;
    }

    printf("\n");
    //select_stmt("select * from foo");

    sqlite3_close(db);

}
string Database::tblName(string tableName){
    return tableName;
}
string Database::tableData(string TABLE) {
    return TABLE;
}
void Database::CreateTable(sqlite3 *db,string sql) {
    char *zErrMsg = nullptr;

    /* Open database */
    int rc = sqlite3_open("products.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return;
    } else {
        fprintf(stdout, "Opened database successfully\n");
    }

    /* Create SQL statement */


    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), Callback, nullptr, &zErrMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Table created successfully\n");
    }
    sqlite3_close(db);
}
void Database::Display(sqlite3 *db) {

    char *zErrMsg = nullptr;
    const char *data = "Callback function called";

    /* Create SQL statement */
    string sql = "SELECT * from LOGDATA";

    /* Execute SQL statement */
    int rc = sqlite3_exec(db, sql.c_str(), Callback, (void *) data, &zErrMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }
}
void Database::executeSql(sqlite3 *db,string SQL){
    char *zErrMsg = nullptr;
    int rc = sqlite3_exec(db, SQL.c_str(), Callback, nullptr, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        cout<<"NOT DELETED"<<endl;
    } else {
        fprintf(stdout, "Action completed\n");
    }
    sqlite3_close(db);
}
string Database::selectData(sqlite3 *db,string tableNm){
    Display(db);
    char tmp[101];
    message("Enter an Id of Element");
    scanf("%100s", tmp);
    string id = tmp;
    //scanf( "%s", id);
    string record;
    record=tableNm+" WHERE ID = "+id+";";
    cout<<record<<endl;
    return record;
}
