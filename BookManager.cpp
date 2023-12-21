//
// Created by ahmed on 14/12/2023.
//

#include "BookManager.h"

BookManger::~BookManger() {
    for (auto &book: books) {
        delete book;
        book = nullptr;
    }
}

void BookManger::printBookList() const {
    cout << "Our current book collection:";
    for (int i = 0; i < books.size(); ++i) {
        cout << "\t" << i + 1 << ": " << books[i]->getTitle() << "\n";
    }
    cout << "Which book to read?:\n";

}

const Book *BookManger::getBook(int id) const {
    id--;
    if (id >= 0 && id < books.size())
        return books[id];
    return nullptr;
}

int BookManger::getNumberOfBooks() const {
    return int(books.size());
}

void BookManger::addBook() {
    Book *new_book = new Book;
    new_book->InputBookData();
    books.push_back(new_book);
}

void BookManger::addBook(Book *new_book) {
    books.push_back(new_book);
}

void BookManger::loadData(ifstream &book_data) {
    string input;
    while (getline(book_data, input)) {
        istringstream line(input);

        int isbn, total_pages;
        string title, author_name;

        line >> isbn >> title >> author_name >> total_pages;

        vector<string> pages(total_pages);

        for (int i = 0; i < total_pages; ++i) {
            getline(book_data, pages[i]);
        }

        Book *new_book = new Book(isbn, title, author_name, total_pages, pages);
        addBook(new_book);
    }
}

void BookManger::saveData(ofstream &book_data) {
    for (const auto &book: books) {
        book_data << book->getIsbn() << " " << book->getTitle() << " " << book->getAuthorName() << " "
                  << book->getNumberOfPages() << "\n";
        for (auto &page: book->getPages()) {
            book_data << page << "\n";
        }
    }
}