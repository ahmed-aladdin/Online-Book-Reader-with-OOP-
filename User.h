//
// Created by ahmed on 13/12/2023.
//
#include <iostream>
#include "BookSession.h"
#include <vector>

using namespace std;
#ifndef ONLINE_BOOK_READER_USER_H
#define ONLINE_BOOK_READER_USER_H

class User {
private:
    string user_name, password, full_name, email;
    bool is_admin;
    vector<BookSession *> sessions;
public:
    User();

    User(const string &user_name, const string &password, const string &full_name,
         const string &email, const bool &is_admin);

    ~User();

    bool checkPassord(string &password) const;

    void printProfile() const;

    const string &getUserName() const;

    void setUserName(const std::string &userName);

    const string &getPassword() const;

    void setPassword(const std::string &password);

    const string &getFullName() const;

    void setFullName(const std::string &fullName);

    const string &getEmail() const;

    void setEmail(const std::string &email);

    bool isAdmin() const;

    void addBookSession(BookSession *booksession);

    void printAllSessions() const;

    int getNumberOfSessions() const;

    bool getIsAdmin() const;

    const vector<BookSession *> &getAllSessions() const;

    BookSession *getSessionAt(int id) const;


};


#endif //ONLINE_BOOK_READER_USER_H
