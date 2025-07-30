// Library.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "Book.h"
using namespace std;
int main()
{
    Book book1;
    book1.setBookDetails("Twilight", "12345", "Alex", true);
    Book book2;
    book2.setBookDetails("Sapiens", "54321", "Camila", true);
    Book book3;
    book3.setBookDetails("Harry Potter", "CCCCC", "Zin Ko", true);
    Book book4;
    book4.setBookDetails("Dune", "DDDDD", "John", true);
    Book book5;
    book5.setBookDetails("Game of Thrones", "EEEEE", "Martin", true);

    Book array[300];
    array[0] = book1;
    array[1] = book2;
    array[2] = book3;
    array[3] = book4;
    array[4] = book5;

    string isbnToBorrow = "";
    while (isbnToBorrow != "0") {
        cout << "Input the book's ISBN you want to borrow: ";
        cin >> isbnToBorrow;
        
        for (int i = 0; i < 300; i++)
        {
            if (array[i].isbn == isbnToBorrow) {
                if (array[i].borrowBook()) {
                    cout << "Don't forget to return the book: " << array[i].title << endl;
                    break;
                }
                else { // we couldn't borrow the book
                    cout << "The book is unavailable\n";
                }
            }
        }

    }

}
