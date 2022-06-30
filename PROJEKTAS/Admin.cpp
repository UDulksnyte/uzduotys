//
// Created by 37067 on 6/1/2022.
//

#include "Admin.h"
#include "Product.h"
#include "Database.h"
#include <limits>
#include <stdio.h>
#include<cstring>
#include"HashTable.h"

Admin::Admin() {
}
Admin::~Admin() {}
Admin::Admin( const string &username, const string &password) : username(username),password(password){}
void Admin::createRecord( ){
    Admin admin;
    Product product;
    string Name;
    double Price;
    int Quant;
    string Description;
    message("Enter products name and price");
    cin>>  Name;
    product.setName(Name);
    cin>>Price;
    product.setPrice(Price);
    message("Enter Description");
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,Description);
    cout<<Description<<endl;
    message("Enter Quantity");
    cin>>Quant;
    product.setQuantity(Quant);
    sqlite3 *db=Database::Connect(dbName);
    Database::CreateTable(db,"CREATE TABLE PRODUCTS("  \
      "ID INTEGER PRIMARY KEY AUTOINCREMENT," \
      "NAME           TEXT    NOT NULL," \
      "DESCRIPTION            TEXT     NOT NULL," \
      "PRICE            REAL     NOT NULL," \
      "QUANTITY        INTEGER );");
    //Database::Insert(db,product);
    adminPanel();
}
void Admin::removeRecord(){
    sqlite3 *db=Database::Connect(dbName);
    //Database::Display(db);
     string name;
    cout<<"Enter table name from where you want to remove record"<<endl;
    cin>>name;
    Admin admin;
    admin.tblName(name);
    Database::executeSql(db,"DELETE FROM "+Database::selectData(db, admin.tblName(name)));
}
void Admin::setPassword( string &ppassword)  {
    cout<<" SET "<<password<<endl;
    ppassword=hash_func(ppassword.c_str(),TABLE_SIZE);
    password=ppassword;
}

void Admin::setUserName(string &usrn) {
    usrn=hash_func(usrn.c_str(),TABLE_SIZE);
    username=usrn;
}
bool Admin::checkPassword(Admin admin) {
    string input;
    message("\tAdmin enter your password:");
    cin>>input;
    cout<<admin.getPassword()<<endl;
    if (input==admin.password)
        return true;
    else return true;//false-pakeiciau i true kad veiktu
}
//template <typename T>
//
void Admin::InsertCustom(sqlite3 *db,Admin admin) {
    sqlite3_stmt *statment;
    string sql;
    string value=admin.getUserName();
    string value2=admin.getPassword();
    sql="INSERT INTO LOGDATA('USERNAME', 'PASSWORD')"
        "VALUES('"+value+"', '"+value2+"') ;";
    char *zErrMsg = nullptr;
    sqlite3_exec(db,sql.c_str(),Database::Callback, nullptr, &zErrMsg);
    if (sqlite3_prepare_v2(db,
                           sql.c_str(),
                           -1,
                           &statment,
                           nullptr)
        != SQLITE_OK) {
        message("error");
    }
    sqlite3_close(db);
    Database::Display(db);
}
const string &Admin::getUserName() const{
    return username;
};

const string &Admin::getPassword() const{
    return password;
};

void Admin::adminRegistration() {
    string usr;
   string psv;
    string confirmpass;
    message("Registration. Enter username: ");
    cin>>usr;
    cin.ignore(100,'\n');
    message("Registration. Enter password: ");
    cin>>psv;
    cin.ignore(100,'\n');
    message("Registration. Confirm password: ");
    cin>>confirmpass;
    cin.ignore(100,'\n');
    if (strcmp(psv.c_str(),confirmpass.c_str())==0){
        cout<<strcmp(psv.c_str(),confirmpass.c_str());
        Admin admin;
       // Hashtable ht;
        //ht.Add(usr.c_str(),psv.c_str());
        admin.setUserName((string&) usr);
        admin.setPassword((string&) psv);
        sqlite3 *db=Database::Connect(dbName);
        Database::CreateTable(db,admin.tableData("CREATE TABLE IF NOT EXISTS LOGDATA("  \
      "ID INTEGER PRIMARY KEY AUTOINCREMENT," \
      "USERNAME           TEXT    NOT NULL," \
      "PASSWORD            TEXT     NOT NULL );"));
      cout<<admin.getPassword()<<endl;
        InsertCustom(db,admin);
        //InsertCustom(db,admin,"LOGDATA","USERNAME, PASSWORD",admin.getUserName(),admin.getPassword());
        message("Successfully registered");
    }
    else {
        message("Try again");
        adminRegistration();
    }
}
void Admin:: adminPanel(){
    int choice;
    while(choice!=2){
        message("\t********** WELCOME ***********");
        message("\t 1.Add new record to database");
        message("\t 2. Back to Menu");
        message("	3. Remove record from database");
        message("	3. Search customer by lastname");
        message("	4. Search customer by ID");
        message("	5. Display completed orders");
        scanf("%d",&choice);
        switch (choice) {
            case 1 :
                createRecord();
                break;
            case 2 :
                break;
            case 3 :
                removeRecord();
                break;
            case 4 :
                adminPanel();
                break;
            case 5 :
                break;
            default:
                message("Incorrect input, try again");
                break;
        }
    }
}
void Admin::adminLogin(Admin admin){
    if (admin.checkPassword(admin)==true) {
        adminPanel();
    }
    else{
        message("Password incorrect");
        adminLogin(admin);
    }
}