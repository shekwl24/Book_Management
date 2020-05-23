#include "BookStore.h"
#include <iostream>  
#include <iomanip>
using namespace std;
BookStore* BookStore::instance = nullptr; // �̱���
BookStore::BookStore(){}
BookStore::~BookStore(){}
void BookStore::addBook(const Book& book) {
	books.push_back(book);
}
void BookStore::checkBookList() { // å ����Ʈ Ȯ��
	int booksSize = books.size();
	cout << "=================================================================================================================\n";
	cout << setw(7) << "å��ȣ" << setw(22) << "å�̸�" << setw(25) << "����" << setw(25) << "å����" << setw(27) << "����\n";
	cout << "=================================================================================================================\n";
	for (int i = 0; i < booksSize; i++) {
		cout << setw(5) << books[i].getBookId() << setw(25) << books[i].getBookName() << setw(25) << books[i].getAuthor()
			<< setw(25) << books[i].getBookState() << setw(25) << books[i].getPrice() << setw(9) << "|\n";
	}
	cout << "=================================================================================================================\n\n";
}
void BookStore::addBook() { // å �߰�
	string _bookName;
	string _author;
	int _price;
	cout << "å �̸��� �Է��Ͻÿ� : ";
	cin >> _bookName;
	cout << "���ڸ� �Է��Ͻÿ� : ";
	cin >> _author;
	cout << "������ �Է��Ͻÿ� : ";
	cin >> _price;
	addBook(Book(_bookName, _author, _price));
	cout << "                                            ���� �߰��� �Ϸ�Ǿ����ϴ�.\n";
}
void BookStore::checkClientList() { // ȸ�� ����Ʈ ���
	int clientsSize = clients.size();
	cout << "============================================================================================\n";
	cout << setw(8) << "ID" << setw(28) << "Password" << setw(23) << "�̸�" << setw(28) << "�޴��� ��ȣ\n";
	cout << "============================================================================================\n";
	for (int i = 0; i < clientsSize; i++) {
		cout << setw(10) << clients[i].getClientId() << setw(25) << clients[i].getPassword() << setw(25) << clients[i].getName()
			<< setw(27) << clients[i].getPhoneNumber() << setw(6) <<"|\n";
	}
	cout << "============================================================================================\n\n";
}
void BookStore::removeBook() { // ���� ����
	int booksSize = books.size();
	int removeNumber;
	int removeId;
	checkBookList(); // ���� ����Ʈ ���
	while (true) {
		cout << "�����ϰ� ���� å ��ȣ�� �Է��Ͻÿ�(���� �޴�(-1)) : ";
		cin >> removeNumber;
		if (removeNumber == -1) break;
		else if (removeNumber < 1 || removeNumber > booksSize) { // �߸��� ���� �Է� ��
			cout << "                                            �߸��� �Է��Դϴ�.\n";
		}
		else { 
			for (int i = 0; i < booksSize; i++) {
				if (books[i].getBookId() == removeNumber) {
					removeId = i;
					break;
				}
			}
			books.erase(books.begin() + removeId); // ���� ����
			cout << "                                            ������ �Ϸ�Ǿ����ϴ�.\n";
			break;
		}
	}
}
void BookStore::rentBook(Client& client) { // ���� �뿩
	int rentNumber;
	int BooksSize = books.size();
	checkBookList();
	while (true) {
		cout << "������ ���� å ��ȣ�� �Է��Ͻÿ�(���� �޴�(-1)) : ";
		cin >> rentNumber;
		if (rentNumber == -1) break;
		else if (rentNumber < 1 || rentNumber > BooksSize) { // �߸��� ���� �Է� ��
			cout << "                                            �߸��� �Է��Դϴ�.\n";
		}
		else if (books[rentNumber - 1].getBookState() == "�뿩 ����") { // �뿩 ������ ��
			books[rentNumber - 1].changeBookState(); // å ���� ����
			client.fillRentBook(books[rentNumber - 1]);
			cout << "                                            �뿩�� �Ϸ�Ǿ����ϴ�.\n";
			break;
		}
		else if (books[rentNumber - 1].getBookState() == "�뿩 �Ұ�") { // �뿩 �Ұ� ��
			cout << "                                            ���� �뿩 ���̹Ƿ� �뿩�� �� �����ϴ�.\n";
		}
	}
}
void BookStore::returnBook(Client& client) { // ���� �ݳ�
	int returnNumber;
	client.printRentBooks(); // �������� ���
	int booksSize = books.size();
	while (true) {
		cout << "�ݳ� �ϰ� ���� å ��ȣ�� �Է��Ͻÿ�(���� �޴�(-1)) : ";
		cin >> returnNumber;
		if (returnNumber == -1) break;
		else if (client.emptyRentBooks(returnNumber)) {
			for (int i = 0; i < booksSize; i++) {
				if (books[i].getBookId() == returnNumber) {
					books[i].changeBookState(); // å ���� ����
					break;
				}
			}
			cout << "                                            ���������� �ݳ��Ǿ����ϴ�.\n";
			break;
		}
		else cout << "                                            �߸��� �Է��Դϴ�.\n";
	}
}
bool BookStore::widthDraw(Client& client) { // ȸ�� Ż��
	int clientsSize = clients.size();
	int widthDrawId;
	char isReal;
	if (client.getRentBooksSize() > 0) { // �뿩 ���� ������ ������
		cout << "                                            �뿩 ���� ������ �����Ƿ� Ż���� �� �����ϴ�.\n";
		return false;
	}
	while (true) {
		cout << "                                            ���� Ż���Ͻðڽ��ϱ�?(Y, N) : ";
		cin >> isReal;
		if (isReal == 'Y' || isReal == 'y') break;
		else if (isReal == 'N' || isReal == 'n') {
			cout << "                                            Ż�� ����Ͽ����ϴ�.\n";
			return false;
		}
		else cout << "                                            �߸��� �Է��Դϴ�.\n";
	}
	for (int i = 0; i < clientsSize; i++) { 
		if (client.getClientId() == clients[i].getClientId()) {
			widthDrawId = i;
			break;
		}
	}
	cout << "                                            ���������� Ż��Ǿ����ϴ�.\n";
	clients.erase(clients.begin() + widthDrawId);
	return true;
}
void BookStore::signUp() { // ȸ������
	int clientsSize = clients.size();
	string _id;
	string _password;
	string _name;
	string _phoneNumber;
	cout << "\n==========ȸ�������� �����մϴ�.==========\n";
	while (true) {
		bool isIdRight = true;
		cout << "����ϰ��� �ϴ� ���̵� �Է��Ͻÿ� : ";
		cin >> _id;
		for (int i = 0; i < clientsSize; i++) {
			if (_id == clients[i].getClientId()) { // ������ ���̵�� ������ 
				cout << "                                            �ش��ϴ� ���̵� �̹� �����մϴ�.\n";
				isIdRight = false;
				break;
			}
		}
		if (isIdRight == true) {
			cout << "                                            ȸ�������� �Ϸ�Ǿ����ϴ�.\n";
			break;
		}
	}
	cout << "����ϰ��� �ϴ� ��й�ȣ�� �Է��Ͻÿ� : ";
	cin >> _password;
	cout << "�̸��� �Է��Ͻÿ� : ";
	cin >> _name;
	cout << "�޴��� ��ȣ�� �Է��Ͻÿ�(010-xxxx-xxxx) : ";
	cin >> _phoneNumber;
	cout << "==========ȸ�������� ���ƽ��ϴ�.==========\n\n";
	addClient(Client(_id, _password, _name, _phoneNumber));
}
Client* BookStore::login() { // �α��� 
	int clientsSize = clients.size();
	string _id;
	string _password;
	cout << "\n==========�α����� �����մϴ�.==========\n";
	cout << "ID�� �Է��Ͻÿ� : ";
	cin >> _id;
	cout << "��й�ȣ�� �Է��Ͻÿ� : ";
	cin >> _password;
	for (int i = 0; i < clientsSize; i++) {
		if (_id == clients[i].getClientId()) { // ���̵� ������
			if (_password == clients[i].getPassword()) { // ��й�ȣ�� ������
				cout << "=========�α��ο� �����߽��ϴ�.=========\n\n";
				return &clients[i];
			}
		}
	}
	cout << "=========�α��ο� �����߽��ϴ�.=========\n";
	return nullptr;
}
void BookStore::addClient(const Client& client) { // ȸ�� �߰�
	clients.push_back(client);
}