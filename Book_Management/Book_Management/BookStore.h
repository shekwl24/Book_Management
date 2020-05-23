#pragma once
#include "Client.h"

class BookStore
{
	vector<Book> books; // 도서 프로그램에 저장되어 있는 도서들
	vector<Client> clients; // 도서 프로그램에 저장되어 있는 회원들
	static BookStore* instance; // 서점 
public:
	BookStore();
	~BookStore();
	
	static BookStore* getInstance() { // 싱글톤 패턴으로 서점 구현
		if (instance == NULL) {
			instance = new BookStore();
		}
		return instance;
	}
	void addBook(const Book& book);
	void addBook();
	void checkBookList();
	void checkClientList();
	void removeBook();
	void rentBook(Client& client);
	void returnBook(Client& client);
	bool widthDraw(Client& client);
	void signUp();
	void addClient(const Client& client);
	Client* login();
};

