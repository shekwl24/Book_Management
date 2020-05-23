#pragma once
#include <string>
#include "Book.h"
#include <vector>
using namespace std;
class Client
{
	string clientId; // ȸ�� ID
	string password; // ȸ�� ��й�ȣ
	string name; // �̸�
	string phoneNumber; // �޴��� ��ȣ
	vector<Book> rentBooks; // ���� å��
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

