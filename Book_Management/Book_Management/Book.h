#pragma once
#include <string>
using namespace std;

class Book
{
	int bookId; // 책 번호
	string bookName; // 책 이름
	string author; // 저자
	string bookState; // 책 상태
	int price; // 가격
	static int idNumber; // 책 번호 생성
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

