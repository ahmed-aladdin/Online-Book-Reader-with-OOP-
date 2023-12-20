//
// Created by ahmed on 15/12/2023.
//
#include "BookSession.h"
#include "BookManager.h"
#include "User.h"

#ifndef ONLINE_BOOK_READER_USERVIEW_H
#define ONLINE_BOOK_READER_USERVIEW_H


class UserView {
private:
    User *user;
    const BookManger *book_manger;
public:
    UserView(User &user,BookManger &book_manger);
    void menu();
    void listMyReadingSessions();
    void listAllBooks();
};


#endif //ONLINE_BOOK_READER_USERVIEW_H
