//
// Created by ahmed on 14/12/2023.
//

#include "Book.h"

Book::Book() {}

Book::Book(int isbn, const std::string &title, const std::string &author_name, int total_pages,
           const vector<std::string> &pages) : isbn(isbn), title(title), author_name(author_name),
           number_of_pages(total_pages), pages(pages) {
}

void Book::InputBookData() {
    cout << "Enter ISBN: ";
    cin >> isbn;
    cout << "Enter Title: ";
    cin >> title;
    cout << "Enter Author Name: ";
    cin >> author_name;
    cout << "Enter How many pages: ";
    cin >> number_of_pages;
    cin.ignore();
    for (int i = 0; i < number_of_pages; ++i) {
        cout << "Enter page # " << i + 1 << ": ";
        string page;
        getline(cin, page);
        pages.push_back(page);
    }
}

int Book::getIsbn() const {
    return isbn;
}

void Book::setIsbn(int isbn) {
    Book::isbn = isbn;
}

const string &Book::getTitle() const {
    return title;
}

void Book::setTitle(const string &title) {
    Book::title = title;
}

const string &Book::getAuthorName() const {
    return author_name;
}

void Book::setAuthorName(const string &authorName) {
    author_name = authorName;
}

int Book::getNumberOfPages() const {
    return number_of_pages;
}

void Book::setNumberOfPages(int bookBages) {
    number_of_pages = bookBages;
}

const vector<string> &Book::getPages() const {
    return pages;
}

void Book::setPages(const vector<string> &pages) {
    Book::pages = pages;
}

const string &Book::getPageAt(int page_number) const {
    if (page_number >= 0 && page_number < number_of_pages)
        return pages[page_number];

    return "Invalid pages number";
}
