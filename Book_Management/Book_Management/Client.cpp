#include "Client.h"
#include <iostream>
#include <iomanip>
Client::Client(string _ClientId, string _password, string _name, string _phoneNumber){
	clientId = _ClientId;
	password = _password;
	name = _name;
	phoneNumber = _phoneNumber;
}
Client::Client() {}
Client::~Client(){}
string Client::getClientId() {
	return clientId;
}
string Client::getPassword() {
	return password;
}
string Client::getName() {
	return name;
}
string Client::getPhoneNumber() {
	return phoneNumber;
}
void Client::fillRentBook(const Book& book) {
	rentBooks.push_back(book);
}
void Client::printRentBooks() { // 회원의 도서 내역 출력
	int booksSize = rentBooks.size();
	cout << setw(45) << clientId << "님의 도서 대여 내역\n";
	cout << "=================================================================================================================\n";
	cout << setw(7) << "책번호" << setw(22) << "책이름" << setw(25) << "저자" << setw(25) << "책상태" << setw(27) << "가격\n";
	cout << "=================================================================================================================\n";
	for (int i = 0; i < booksSize; i++) {
		cout << setw(5) << rentBooks[i].getBookId() << setw(25) << rentBooks[i].getBookName() << setw(25) << rentBooks[i].getAuthor()
			<< setw(25) << rentBooks[i].getBookState() << setw(25) << rentBooks[i].getPrice() << setw(9) << "|\n";
	}
	cout << "=================================================================================================================\n\n";
}
bool Client::emptyRentBooks(int _bookId) { // 책 반환 시 고객 도서 내역에서 삭제
	int booksSize = rentBooks.size();
	int emptyId = -1;
	for (int i = 0; i < booksSize; i++) {
		if (rentBooks[i].getBookId() == _bookId) {
			emptyId = i;
			break;
		}
	}
	if (emptyId == -1) return false; // 번호와 같은 도서가 없으면		
	else {
		rentBooks.erase(rentBooks.begin() + emptyId);
		return true;
	}
}
int Client::getRentBooksSize() { 
	int rentBooksSize = rentBooks.size();
	return rentBooksSize;
}