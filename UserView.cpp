//
// Created by ahmed on 15/12/2023.
//

#include "UserView.h"

UserView::UserView(User &user, BookManger &book_manger) : user(&user), book_manger(&book_manger) {

}

void UserView::menu() {
    cout << "Menu: ";
    cout << "\t1: View Profile.\n";
    cout << "\t2: List & Select from My Reading History.\n";
    cout << "\t3: List & Select from Available Books.\n";
    cout << "\t4: Logout.\n";
    int status;
    do {
        cout << "Enter number in range 1 - 4: ";
        cin >> status;
        if (status == 1) {
            user->printProfile();
        } else if (status == 2) {
            listMyReadingSessions();
        } else if (status == 3) {
            listAllBooks();
        } else if (status != 4) {
            cout << "Invalid number.\n";
        }
    } while (status != 4);
}

void UserView::listMyReadingSessions() {
    user->printAllSessions();
    int number_of_sessions = user->getNumberOfSessions(), choice;
    if (number_of_sessions == 0) {
        cout << "Your reading session is empty.\n";
        return;
    }
    while (true) {
        cout << "Choose number between 1 - " << number_of_sessions << ": ";
        cin >> choice;
        if (choice >= 1 && choice <= number_of_sessions) {
            break;
        }
        cout << "Invalid choice try again.\n";
    }
    user->getSessionAt(choice)->menu();
}

void UserView::listAllBooks() {
    book_manger->printBookList();
    int number_of_books = book_manger->getNumberOfBooks(), choice;
    if (number_of_books == 0) {
        cout << "There is no books right now\n";
        return;
    }
    while (true) {
        cout << "Choose number between 1 - " << number_of_books << ": ";
        cin >> choice;
        if (choice >= 1 && choice <= number_of_books)
            break;
        cout << "Invalid choice try again.\n";
    }
    BookSession *new_session = new BookSession(*book_manger->getBook(choice),choice);
    user->addBookSession(new_session);
    new_session->menu();
}
