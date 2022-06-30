//
// Created by 37067 on 6/1/2022.
//
#include<string>
#include <stdio.h>
#include"Database.h"
#include <stdlib.h>
#ifndef PROJEKTAS_ADMIN_H
#define PROJEKTAS_ADMIN_H
using namespace std;
class Admin: public Database {
private:
     string password;
     string username;
public:
    Admin();
    ~Admin();
    Admin(const string &username,const string &password);
    static void adminLogin(Admin admin);
    static void removeRecord();
    static void adminPanel();
    static void createRecord( );
    static void InsertCustom(sqlite3 *db,Admin admin);
    bool checkPassword(Admin admin);
    void setPassword( string &ppasword);
    void setUserName( string &usr);
    const string& getPassword()const;
    const string &getUserName()const;
    void adminRegistration();

};


#endif //PROJEKTAS_ADMIN_H
