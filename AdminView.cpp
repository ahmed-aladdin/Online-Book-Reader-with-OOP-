//
// Created by ahmed on 14/12/2023.
//

#include "AdminView.h"
#include<iostream>

using namespace std;

AdminView::AdminView(User &user, BookManger &bookManger) : user(&user), bookManger(&bookManger) {

}

void AdminView::menu() {
    int status;
    do {
        cout << user->getFullName() << " | Admin View\n";
        cout << "Menu:\n";
        cout << "\t1: View Profile.\n";
        cout << "\t2: Add Book.\n";
        cout << "\t3: Logout.\n";
        cout << "Enter a number between 1 - 3: ";
        cin >> status;
        if (status == 1) {
            user->printProfile();
        } else if (status == 2) {
            bookManger->addBook();
        } else if (status != 3) {
            cout << "Invalid number.\n";
        }
    } while (status != 3);
}