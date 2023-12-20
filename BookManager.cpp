//
// Created by ahmed on 14/12/2023.
//

#include "BookManager.h"

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
