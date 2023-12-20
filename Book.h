//
// Created by ahmed on 14/12/2023.
//
#include <iostream>
#include <vector>

using namespace std;
#ifndef ONLINE_BOOK_READER_BOOK_H
#define ONLINE_BOOK_READER_BOOK_H


class Book {
private:
    int isbn;
    string title, author_name;
    int number_of_pages;
    vector<string> pages;
public:
    Book();

    Book(int isbn, const string &title, const string &author_name, int total_pages,
         const vector<string> &pages);

    void InputBookData();

    int getIsbn() const;

    void setIsbn(int isbn);

    const string &getTitle() const;

    void setTitle(const string &title);

    const string &getAuthorName() const;

    void setAuthorName(const string &authorName);

    int getNumberOfPages() const;

    void setNumberOfPages(int bookBages);

    const vector<string> &getPages() const;

    void setPages(const vector<string> &pages);

    const string &getPageAt(int page_number) const;
};


#endif //ONLINE_BOOK_READER_BOOK_H
