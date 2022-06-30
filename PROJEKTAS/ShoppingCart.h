//
// Created by 37067 on 6/2/2022.
//

#ifndef PROJEKTAS_SHOPPINGCART_H
#define PROJEKTAS_SHOPPINGCART_H
#include"Product.h"
#include <vector>

class ShoppingCart {
public:
    ShoppingCart();
    std::vector<Product>Items;
    void addItem(Product Item);
    void removeItem(Product Item);
    void displayCart();
};


#endif //PROJEKTAS_SHOPPINGCART_H
