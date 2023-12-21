//
// Created by ahmed on 14/12/2023.
//
#include <vector>
#include <fstream>
#include <sstream>
#include "Book.h"

#ifndef ONLINE_BOOK_READER_BOOKMANGER_H
#define ONLINE_BOOK_READER_BOOKMANGER_H


class BookManger {
private:
    vector<Book *> books;

public:
    ~BookManger();

    void printBookList() const;

    const Book *getBook(int id) const;

    int getNumberOfBooks() const;

    void addBook();

    void addBook(Book *new_book);

    void loadData(ifstream &book_data);

    void saveData(ofstream &book_data);
};

#endif //ONLINE_BOOK_READER_BOOKMANGER_H
