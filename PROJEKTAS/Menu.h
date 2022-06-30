//
// Created by 37067 on 6/10/2022.
//
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include "Product.h"
#include "Database.h"
#include"Admin.h"
void signingUp(){

};
void shop(){
};
void Login(){
    Admin admin;
int choice;
    message("\tWhat would you like to do?");
    message("	1. Login as Administrator");
    message("	2. Register Admin ");
    message("	3. Exit");
    message("	4. ****");
    message("	5. Exit");
    scanf("%d",&choice);
    switch (choice) {
        case 1 :
            admin.adminLogin(admin);
            break;
        case 2 :
            admin.adminRegistration();
            Login();
            break;
        case 3:
            break;
        default:
            message("Incorrect input, try again");
            Login();
            break;
}
}

#define PROJEKTAS_MENU_H
