//
// Created by ahmed on 14/12/2023.
//
#include "BookManager.h"
#include "UserManager.h"
#include <map>
#include <fstream>

#ifndef ONLINE_BOOK_READER_ONLINEBOOKSYSTEM_H
#define ONLINE_BOOK_READER_ONLINEBOOKSYSTEM_H


class OnlineBookSystem {
private:
    BookManger book_manager;
    UserManager user_manager;
public:
    OnlineBookSystem();

    void run();

    void loadData();

    void saveData();
};


#endif //ONLINE_BOOK_READER_ONLINEBOOKSYSTEM_H
