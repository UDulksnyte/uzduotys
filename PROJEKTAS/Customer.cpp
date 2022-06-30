//
// Created by 37067 on 6/1/2022.
//

#include "Customer.h"
Customer::Customer(const int &customerId,const std::string &name,const std::string &lastName,const std::string &username,const std::string &password,
                  const std::string &eMail,const std::string &phoneNumber) : customerId(customerId),name(name),lastName(lastName),username(username),password(password),eMail(eMail),phoneNumber(phoneNumber){}
