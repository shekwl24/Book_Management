#include "Book.h"

int Book::idNumber = 0;
Book::Book(string _bookName, string _author, int _price){
	idNumber++;
	bookId = idNumber;
	bookName = _bookName;
	author = _author;
	bookState = "대여 가능";
	price = _price;
}
Book::Book() {}
Book::~Book(){}
int Book::getBookId() {
	return bookId;
}
string Book::getBookName() {
	return bookName;
}
string Book::getAuthor() {
	return author;
}
string Book::getBookState() {
	return bookState;
}
int Book::getPrice() {
	return price;
}
void Book::changeBookState() { // 책 상태 변경
	if (bookState == "대여 가능") bookState = "대여 불가";
	else bookState = "대여 가능";
}