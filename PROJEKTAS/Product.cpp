//
// Created by 37067 on 6/1/2022.
//

#include "Product.h"
Product::Product(){};
Product::Product(const string &name, const string &description, double price, int quantity) : name(name), description(description),
                                                                                price(price), quantity(quantity) {}
 void Product::setName( string &Pname)  {
     name=Pname;
}
void Product::setDescription( string &Pdescription) {
    description=Pdescription;

}
void Product::setPrice( double &Pprice){
    price=Pprice;
}
void Product::setQuantity( int &Qquantity){
    quantity=Qquantity;
}
const string &Product::GetName() const {
    return name;
}

const string &Product::GetDescription() const {
    return description;
}

double Product::GetPrice() const {
    return price;
}
int Product::getQuantity(){
    return quantity;
}