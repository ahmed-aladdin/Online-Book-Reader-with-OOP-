//
// Created by ahmed on 14/12/2023.
//
#include "UserManager.h"

UserManager::UserManager(BookManger &bookManger) {
    UserManager::bookManger = &bookManger;
}

bool UserManager::is_registered(string &user_name) {
    return users.count(user_name);
}

bool UserManager::verifyLogin(string &user_name, string &password) {
    if (!is_registered(user_name))
        return false;
    return getUser(user_name)->checkPassord(password);
}

void UserManager::Login() {
    string user_name, password;
    cout << "Enter username: ";
    cin >> user_name;
    cout << "Enter password: ";
    cin >> password;
    if (verifyLogin(user_name, password)) {
        User *user = getUser(user_name);
        if (user->isAdmin()) {
            AdminView view(*user, *bookManger);
            view.menu();
        } else {
            UserView view(*user, *bookManger);
            view.menu();
        }
    } else {
        cout << "Sorry you entered an invalid username or password.\n";
    }
}

void UserManager::SignUp() {
    string user_name, password, name, email;
    cout << "Enter username: ";
    cin >> user_name;
    cout << "Enter password: ";
    cin >> password;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter email: ";
    cin >> email;
    User new_user;
    if (is_registered(user_name)) {
        cout << "Sorry this username is already registered.\n";
        return;
    }
    new_user.setUserName(user_name);
    new_user.setPassword(password);
    new_user.setFullName(name);
    new_user.setEmail(email);
    addUser(new_user);
}

void UserManager::addUser(User &user) {
    users[user.getUserName()] = user;
}

User *UserManager::getUser(std::string &user_name) {
    return &users.find(user_name)->second;
}
