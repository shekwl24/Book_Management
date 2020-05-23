#pragma once
#include <string>
using namespace std;

class Book
{
	int bookId; // å ��ȣ
	string bookName; // å �̸�
	string author; // ����
	string bookState; // å ����
	int price; // ����
	static int idNumber; // å ��ȣ ����
public:
	Book();
	Book(string _bookName, string _author, int _price);
	~Book();
	int getBookId();
	string getBookName();
	string getAuthor();
	string getBookState();
	int getPrice();
	void changeBookState();
};

