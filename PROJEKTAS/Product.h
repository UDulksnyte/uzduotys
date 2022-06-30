//
// Created by 37067 on 6/1/2022.
//

#ifndef DATABASESSQLITESTARTER_PRODUCT_H
#define DATABASESSQLITESTARTER_PRODUCT_H
#include <iostream>
#include<string>
using namespace std;
class Product {
private:
    string name;
    string description;
    double price;
    int quantity;
public:
    Product();
    Product(const string &name, const string &description, double price,int quantity);
    void setName(string &Pname);

    void setDescription(string &Pdescription) ;
    void setPrice(double &Pprice);
    void setQuantity(int &stock);
    int getQuantity();


    const string &GetName() const;

    const string &GetDescription() const;

    double GetPrice() const;


};


#endif //DATABASESSQLITESTARTER_PRODUCT_H