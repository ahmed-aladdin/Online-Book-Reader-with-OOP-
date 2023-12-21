//
// Created by ahmed on 13/12/2023.
//
#include "User.h"

User::User() {
    is_admin = false;
}

User::User(const string &user_name, const string &password, const string &full_name,
           const string &email, const bool &is_admin)
        : user_name(user_name), password(password), full_name(full_name),
          email(email), is_admin(is_admin) {
}

User::~User() {
    for (auto &session: sessions) {
        delete session;
        session = nullptr;
    }
}

bool User::checkPassord(string &password) const {
    return password == getPassword();
}

void User::printProfile() const {
    cout << "Full Name: " << full_name;
    if (is_admin)
        cout << " | Admin";
    cout << "\n";
    cout << "Email: " << email << "\n";
    cout << "User Name: " << user_name << "\n";
}

const string &User::getUserName() const {
    return user_name;
}

void User::setUserName(const std::string &userName) {
    user_name = userName;
}

const string &User::getPassword() const {
    return password;
}

void User::setPassword(const std::string &password) {
    User::password = password;
}

const string &User::getFullName() const {
    return full_name;
}

void User::setFullName(const std::string &fullName) {
    full_name = fullName;
}

const string &User::getEmail() const {
    return email;
}

void User::setEmail(const std::string &email) {
    User::email = email;
}

bool User::isAdmin() const {
    return is_admin;
}

void User::addBookSession(BookSession *book_session) {
    sessions.push_back(book_session);
}

void User::printAllSessions() const {
    for (auto &book_session: sessions) {
        cout << book_session->SessionToStr();
    }
}

int User::getNumberOfSessions() const {
    return int(sessions.size());
}

bool User::getIsAdmin() const {
    return is_admin;
}

const vector<BookSession *> &User::getAllSessions() const {
    return sessions;
}

BookSession *User::getSessionAt(int id) const {
    if (id >= 1 && id <= getNumberOfSessions())
        return sessions[id - 1];
    return nullptr;
}