#pragma once
#include "Client.h"

class BookStore
{
	vector<Book> books; // ���� ���α׷��� ����Ǿ� �ִ� ������
	vector<Client> clients; // ���� ���α׷��� ����Ǿ� �ִ� ȸ����
	static BookStore* instance; // ���� 
public:
	BookStore();
	~BookStore();
	
	static BookStore* getInstance() { // �̱��� �������� ���� ����
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

