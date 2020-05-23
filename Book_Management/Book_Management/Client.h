#pragma once
#include <string>
#include "Book.h"
#include <vector>
using namespace std;
class Client
{
	string clientId; // 회원 ID
	string password; // 회원 비밀번호
	string name; // 이름
	string phoneNumber; // 휴대폰 번호
	vector<Book> rentBooks; // 빌린 책들
public:
	Client();
	Client(string _ClientId, string _password, string _name, string _phoneNumber);
	~Client();
	string getClientId();
	string getPassword();
	string getName();
	string getPhoneNumber();
	void fillRentBook(const Book& book);
	void printRentBooks();
	bool emptyRentBooks(int _bookId);
	int getRentBooksSize();
};

