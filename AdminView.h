//
// Created by ahmed on 14/12/2023.
//
#include "User.h"
#include "BookManager.h"

#ifndef ONLINE_BOOK_READER_ADMINVIEW_H
#define ONLINE_BOOK_READER_ADMINVIEW_H


class AdminView {
    User *user;
    BookManger *bookManger;
public:
    AdminView(User &user,BookManger &bookManger);

    void menu();
};


#endif //ONLINE_BOOK_READER_ADMINVIEW_H
