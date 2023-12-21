//
// Created by ahmed on 14/12/2023.
//
#include "Book.h"
#include "sstream"
#include "chrono"
#include "iomanip"
#include "iostream"

#ifndef ONLINE_BOOK_READER_BOOKSESSION_H
#define ONLINE_BOOK_READER_BOOKSESSION_H


class BookSession {
private:
    const Book *book;
    int current_page, book_id;
    string last_time;
public:
    BookSession(const Book &book, int book_id);

    BookSession(const Book &book, int book_id, int current_page, const string &last_time);

    void menu();

    const string getCurrentTime() const;

    void setLastTime(const string &current_time);

    const string &getLastTime() const;

    void nextPage();

    void previousPage();

    int getCurrentPage() const;

    void setCurrentPage(int current_page);

    const string SessionToStr() const;

    int getBookId() const;

    void printCurrentPage() const;
};


#endif //ONLINE_BOOK_READER_BOOKSESSION_H
