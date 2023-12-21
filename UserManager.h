//
// Created by ahmed on 14/12/2023.
//
#include <map>
#include "User.h"
#include "BookManager.h"
#include "AdminView.h"
#include "UserView.h"

#ifndef ONLINE_BOOK_READER_USERMANAGER_H
#define ONLINE_BOOK_READER_USERMANAGER_H


class UserManager {
private:
    map<std::string, User *> users;
    BookManger *bookManger;
public:
    UserManager(BookManger &bookManger);

    ~UserManager();

    bool is_registered(string &user_name);

    bool verifyLogin(string &user_name, string &password);

    void Login();

    void SignUp();

    void addUser(User *user);

    User *getUser(string &user_name);

    void loadData(ifstream &user_data);

    void saveData(ofstream &user_data);
};


#endif //ONLINE_BOOK_READER_USERMANAGER_H
