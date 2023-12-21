//
// Created by ahmed on 14/12/2023.
//


#include "OnlineBookSystem.h"

OnlineBookSystem::OnlineBookSystem() : user_manager(book_manager) {

}

void OnlineBookSystem::run() {
    loadData();

    while (true) {
        cout << "Menu: \n";
        cout << "\t1: Login.\n";
        cout << "\t2: SignUp.\n";
        cout << "\t3: End.\n";

        cout << "Enter number in range 1-3: ";
        int status;
        cin >> status;
        if (status == 1) {
            user_manager.Login();
        } else if (status == 2) {
            user_manager.SignUp();
        } else if (status == 3) {
            break;
        }
    }

    saveData();
}

void OnlineBookSystem::loadData() {
    ifstream book_data("BookData.txt");
    book_manager.loadData(book_data);

    ifstream user_data("UserData.txt");
    user_manager.loadData(user_data);
}

void OnlineBookSystem::saveData() {
    ofstream book_data("BookData.txt");
    book_manager.saveData(book_data);

    ofstream user_data("UserData.txt");
    user_manager.saveData(user_data);
}