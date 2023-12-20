//
// Created by ahmed on 14/12/2023.
//

#include "BookSession.h"

BookSession::BookSession(const Book &book) : book(&book) {
    current_page = 1;
}

void BookSession::menu() {
    int status;
    do {
        printCurrentPage();
        cout << "\n";
        cout << "Menu:\n";
        cout << "\t1: Next Page\n";
        cout << "\t2: Previous Page\n";
        cout << "\t3: Stop Reading\n";
        cout << "\nEnter a number between 1 - 3: ";
        cin >> status;
        if (status == 1)
            nextPage();
        else if (status == 2)
            previousPage();
        else if (status != 3)
            cout << "Invalid Choice\n";

        setLastTime(getCurrentTime());
    } while (status != 3);
}

const string BookSession::getCurrentTime() const {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    return ss.str();
}

void BookSession::setLastTime(const string &last_time) {
    this->last_time = last_time;
}

const string &BookSession::getLastTime() const {
    return last_time;
}

void BookSession::nextPage() {
    if (getCurrentPage() + 1 <= book->getNumberOfPages())
        setCurrentPage(getCurrentPage() + 1);
}

void BookSession::previousPage() {
    if (getCurrentPage() - 1 >= 1)
        setCurrentPage(getCurrentPage() - 1);
}

const string BookSession::SessionToStr() const {
    ostringstream output;
    output << book->getTitle() << " Page: " << getCurrentPage() << "/" <<
           book->getNumberOfPages() << " - " << getLastTime();
    return output.str();
}

int BookSession::getCurrentPage() const {
    return current_page;
}

void BookSession::setCurrentPage(int current_page) {
    this->current_page = current_page;
}

void BookSession::printCurrentPage() const {
    cout << "Current Page: " << getCurrentPage() << "/" << book->getNumberOfPages() << "\n";
    cout << book->getPageAt(getCurrentPage() - 1) << "\n";
}
