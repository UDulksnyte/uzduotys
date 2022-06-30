cmake_minimum_required(VERSION 3.22)
project(PROJEKTAS)

set(CMAKE_CXX_STANDARD 14)

add_executable(PROJEKTAS sqlite3.h sqlite3.c main.cpp Product.cpp Product.h Admin.cpp Admin.h Customer.cpp Customer.h Database.cpp Database.h ShoppingCart.cpp ShoppingCart.h Menu.h HashTable.h)
add_compile_options(-l sqlite3)