//
// Created by 37067 on 6/1/2022.
//

#ifndef PROJEKTAS_CUSTOMER_H
#define PROJEKTAS_CUSTOMER_H
#include "sqlite3.h"
#include<iostream>
#include<string>

class Customer {
private:
     int customerId;
     std::string name;
     std::string lastName;
     std::string username;
     std::string password;
     std::string eMail;
    std::string phoneNumber;
    std::string lastPay;
public:
    Customer();
    Customer(const int &customerId,const std::string &name,const std::string &lastName,const std::string &username,const std::string &password,
             const std::string &eMail,const std::string &phoneNumber);
    Customer addCustomer(Customer customer);
    Customer removeCustomer(Customer costumer);
    int setCustomerId()const;
    std::string getlastPay();
};


#endif //PROJEKTAS_CUSTOMER_H
