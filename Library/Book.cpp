#include "Book.h"

void Book::setBookDetails(string title1, string isbn1, string author1, bool hasBeenBorrowed1) {
	title = title1;
	isbn = isbn1;
	author = author1;
	available = hasBeenBorrowed1;
}

void Book::displayBookDetails() {
	cout << "Title: " << title << endl;
	cout << "Isbn: " << isbn << endl;
	cout << "Author: " << author << endl;
	cout << "Availability: " << available << endl;
}

void Book::returnBook() {
	available = false;
}
bool Book::borrowBook() {
	if (available == false) {
		//cout << "You cannot borrow the book: " << title << endl;
		return false;
	}
	else {
		//cout << "You have borrowed the book: " << title << endl;
		available = false;
		return true;
	}
}

