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
    User admin("admin", "123", "Main_admin", "admin@gmail.com", true);
    user_manager.addUser(admin);
    User user("user", "123", "user1", "user1@gmail.com", false);
    user_manager.addUser(user);
    Book *book = new Book(123, "C++", "hussien", 2,
                          {"hello", "world"});
    book_manager.addBook(book);
}

void OnlineBookSystem::saveData() {
    ofstream user_data("UserData.txt");
    ofstream book_data("BookData.txt");
}