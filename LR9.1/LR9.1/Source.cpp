#include <iostream>
#include <list>
#include <string>

using namespace std;

struct Book {
    string udc;
    string author;
    string title;
    int year;
    int quantity;
};

class Library {
private:
    list<Book> books;

public:
    void addBook(const Book& b) {
        books.push_back(b);
    }

    list<Book>::iterator findBook(const string& udc) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->udc == udc)
                return it;
        }
        return books.end();
    }

    void takeBook(const string& udc) {
        auto it = findBook(udc);
        if (it == books.end()) {
            cout << "Book not found\n";
        }
        else if (it->quantity == 0) {
            cout << "Book is unavailable\n";
        }
        else {
            it->quantity--;
            cout << "Book taken\n";
        }
    }

    void returnBook(const string& udc) {
        auto it = findBook(udc);
        if (it == books.end()) {
            cout << "Book not found\n";
        }
        else {
            it->quantity++;
            cout << "Book returned\n";
        }
    }

    void showBooks() {
        for (const auto& b : books) {
            cout << "UDC: " << b.udc << endl;
            cout << "Author: " << b.author << endl;
            cout << "Title: " << b.title << endl;
            cout << "Year: " << b.year << endl;
            cout << "Quantity: " << b.quantity << endl;
            cout << "---------------------\n";
        }
    }
};

int main() {
    Library lib;

    lib.addBook({ "001", "Shevchenko T.G.", "Kobzar", 1840, 3 });
    lib.addBook({ "002", "Franko I.Y.", "Zakhar Berkut", 1883, 2 });

    int choice;
    string udc;

    do {
        cout << "\n1. Show books\n";
        cout << "2. Take book\n";
        cout << "3. Return book\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            lib.showBooks();
            break;
        case 2:
            cout << "Enter UDC: ";
            cin >> udc;
            lib.takeBook(udc);
            break;
        case 3:
            cout << "Enter UDC: ";
            cin >> udc;
            lib.returnBook(udc);
            break;
        }
    } while (choice != 0);

    return 0;
}