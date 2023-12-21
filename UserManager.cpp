//
// Created by ahmed on 14/12/2023.
//
#include "UserManager.h"

UserManager::UserManager(BookManger &bookManger) {
    UserManager::bookManger = &bookManger;
}

UserManager::~UserManager() {
    for (auto &[name, user]: users) {
        delete user;
        user = nullptr;
    }
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

    if (is_registered(user_name)) {
        cout << "Sorry this username is already registered.\n";
        return;
    }
    User *new_user = new User;
    new_user->setUserName(user_name);
    new_user->setPassword(password);
    new_user->setFullName(name);
    new_user->setEmail(email);
    addUser(new_user);
}

void UserManager::addUser(User *user) {
    users[user->getUserName()] = user;
}

User *UserManager::getUser(std::string &user_name) {
    return users.find(user_name)->second;
}

void UserManager::loadData(ifstream &user_data) {
    string name, password, full_name, email, input;
    bool is_admin;
    int number_of_sessions;
    while (getline(user_data, input)) {
        istringstream line(input);

        line >> name >> password >> full_name
             >> email >> is_admin >> number_of_sessions;
        User *user = new User(name, password, full_name, email, is_admin);

        for (int i = 0; i < number_of_sessions; ++i) {

            int book_id, current_page;
            string last_time;

            getline(user_data, input);
            line = istringstream(input);

            line >> book_id >> current_page >> last_time;

            const Book *book = bookManger->getBook(book_id);

            if (book != nullptr) {
                BookSession *session = new BookSession(*book, book_id,
                                                       current_page, last_time);
                user->addBookSession(session);
            }
        }
        addUser(user);
    }
}

void UserManager::saveData(ofstream &user_data) {
    if (user_data.is_open() == 0) {
        cout << "UserData.txt con't\n";
    }
    for (auto &[name, user]: users) {
        user_data << user->getUserName() << " " << user->getPassword() << " " << user->getFullName() << " "
                  << user->getEmail() << " " << user->getIsAdmin() << " " << user->getNumberOfSessions() << "\n";
        for (auto session: user->getAllSessions()) {
            cout << session->getBookId() << " " << session->getCurrentPage() << " " << session->getLastTime() << "\n";
        }
    }
}