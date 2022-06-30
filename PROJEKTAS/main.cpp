#include <iostream>
#include "Database.h"
#include "Product.h"
#include "Customer.h"
#include "ShoppingCart.h"
#include "Menu.h"
#include<iostream>

#include<string>
using namespace std;


int main() {
    Login();
    string key, value;
    /*Hashtable ht;
    HashtableItem *item;

    while (true)
    {
        cout << "enter a key (string) for the hash (q to quit): ";
        cin >> key;
        if (key == "q")
            break;
        item = ht[key];
        if (item == nullptr)
        {
            cout << "enter a value for the key \"" << key << "\" (q to quit): ";
            cin >> value;
            if (value == "q")
                break;
            ht.Add(key, value);
        }
        else
        {
            cout << "the value at \"" << item->Key() << "\" is \"" << item->Value() << "\"\r\nenter a new value: ";
            cin >> value;
            (*item) = value;
        }
    }
    while (true)
    {
        item = ht.GetFirst();
        while (item)
        {
            cout << "the value at \"" << item->Key() << "\" is \"" << item->Value() << "\"\r\n";
            item = ht.GetNext();
        }
        cout << "enter the key (string) to delete (q to quit): ";
        cin >> key;
        if (key == "q")
            break;
        ht.Remove(key);
    }
    return 0;
}
*/
}