// Library.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "Book.h"
#include <algorithm>
using namespace std;

void showMenu();
void showAllBooks();

Book arrayBook[100];
//TODO: Change totalBooks to 5
int totalBooks = 3;

int main()
{
    cout << boolalpha;
    Book book1;
    book1.setBookDetails("Harry Potter", "12345", "J. K. Rowling", true);
    Book book2;
    book2.setBookDetails("Dune", "12346", "John", true);
    Book book3;
    book3.setBookDetails("Game of Thrones", "12347", "Martin", true);
    //TODO: ADD 2 MORE BOOKS

    arrayBook[0] = book1;
    arrayBook[1] = book2;
    arrayBook[2] = book3;

    int option;
    while (true) {
        showMenu();
        cout << "Select an option: ";
        cin >> option;
        if (option == 1) {
            showAllBooks();

        }
        if (option == 2) {
            string isbnToBorrow = "";
            while (isbnToBorrow != "0") {

                cout << "==> Input the book's ISBN you want to borrow or 0 (zero) to Quit: ";
                cin >> isbnToBorrow;

                for (int i = 0; i < totalBooks; i++)
                {
                    if (arrayBook[i].isbn == isbnToBorrow) {
                        if (arrayBook[i].borrowBook()) {
                            cout << "==> You have borrowed the book: " << arrayBook[i].title << endl;
                            cout << "Don't forget to return the book: " << arrayBook[i].title << endl;
                            break;
                        }
                        else { // we couldn't borrow the book
                            cout << "==> The book is unavailable" << endl;
                        }
                    }
                }

            }
        }
        if (option == 3) {
            string isbnToReturn;
            cout << "==> Input the ISBN of the book you want to return, 0 (zero) to QUIT ";
            cin >> isbnToReturn;
            for (int i = 0; i < totalBooks; i++)
            {
                if (arrayBook[i].isbn == isbnToReturn) {
                    arrayBook[i].returnBook();
                    cout << "==> You have returned the book: " << arrayBook[i].title << endl;
                }
            }
        }
        if (option == 4) {
            cout << "BYE I hope to see you soon again!";
            break;
        }

    }

    /*

    */
}

void showMenu() {
    cout << "========================================" << endl;
    cout << "=                OPTIONS               =" << endl;
    cout << "= 1: Show all books                    =" << endl;
    cout << "= 2: Borrow Books                      =" << endl;
    cout << "= 3: Return a Book                     =" << endl;
    cout << "= 4: QUIT the program                  =" << endl;
    cout << "========================================" << endl;

}

void showAllBooks() {
    std::sort(arrayBook, arrayBook + totalBooks, [](const Book& a, const Book& b) {
        return a.title > b.title;
        });

    for (int i = 0; i < totalBooks; i++) {
        cout << "isbn: " << arrayBook[i].isbn << ", "
            << "title: " << arrayBook[i].title << ", "
            << "author: " << arrayBook[i].author << endl;
    }
    cout << endl;
}