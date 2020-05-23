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
void Client::printRentBooks() { // ȸ���� ���� ���� ���
	int booksSize = rentBooks.size();
	cout << setw(45) << clientId << "���� ���� �뿩 ����\n";
	cout << "=================================================================================================================\n";
	cout << setw(7) << "å��ȣ" << setw(22) << "å�̸�" << setw(25) << "����" << setw(25) << "å����" << setw(27) << "����\n";
	cout << "=================================================================================================================\n";
	for (int i = 0; i < booksSize; i++) {
		cout << setw(5) << rentBooks[i].getBookId() << setw(25) << rentBooks[i].getBookName() << setw(25) << rentBooks[i].getAuthor()
			<< setw(25) << rentBooks[i].getBookState() << setw(25) << rentBooks[i].getPrice() << setw(9) << "|\n";
	}
	cout << "=================================================================================================================\n\n";
}
bool Client::emptyRentBooks(int _bookId) { // å ��ȯ �� �� ���� �������� ����
	int booksSize = rentBooks.size();
	int emptyId = -1;
	for (int i = 0; i < booksSize; i++) {
		if (rentBooks[i].getBookId() == _bookId) {
			emptyId = i;
			break;
		}
	}
	if (emptyId == -1) return false; // ��ȣ�� ���� ������ ������		
	else {
		rentBooks.erase(rentBooks.begin() + emptyId);
		return true;
	}
}
int Client::getRentBooksSize() { 
	int rentBooksSize = rentBooks.size();
	return rentBooksSize;
}