#include "BookStore.h"
#include <iostream>  
#include <iomanip>
using namespace std;
BookStore* BookStore::instance = nullptr; // 싱글톤
BookStore::BookStore(){}
BookStore::~BookStore(){}
void BookStore::addBook(const Book& book) {
	books.push_back(book);
}
void BookStore::checkBookList() { // 책 리스트 확인
	int booksSize = books.size();
	cout << "=================================================================================================================\n";
	cout << setw(7) << "책번호" << setw(22) << "책이름" << setw(25) << "저자" << setw(25) << "책상태" << setw(27) << "가격\n";
	cout << "=================================================================================================================\n";
	for (int i = 0; i < booksSize; i++) {
		cout << setw(5) << books[i].getBookId() << setw(25) << books[i].getBookName() << setw(25) << books[i].getAuthor()
			<< setw(25) << books[i].getBookState() << setw(25) << books[i].getPrice() << setw(9) << "|\n";
	}
	cout << "=================================================================================================================\n\n";
}
void BookStore::addBook() { // 책 추가
	string _bookName;
	string _author;
	int _price;
	cout << "책 이름을 입력하시오 : ";
	cin >> _bookName;
	cout << "저자를 입력하시오 : ";
	cin >> _author;
	cout << "가격을 입력하시오 : ";
	cin >> _price;
	addBook(Book(_bookName, _author, _price));
	cout << "                                            도서 추가가 완료되었습니다.\n";
}
void BookStore::checkClientList() { // 회원 리스트 출력
	int clientsSize = clients.size();
	cout << "============================================================================================\n";
	cout << setw(8) << "ID" << setw(28) << "Password" << setw(23) << "이름" << setw(28) << "휴대폰 번호\n";
	cout << "============================================================================================\n";
	for (int i = 0; i < clientsSize; i++) {
		cout << setw(10) << clients[i].getClientId() << setw(25) << clients[i].getPassword() << setw(25) << clients[i].getName()
			<< setw(27) << clients[i].getPhoneNumber() << setw(6) <<"|\n";
	}
	cout << "============================================================================================\n\n";
}
void BookStore::removeBook() { // 도서 삭제
	int booksSize = books.size();
	int removeNumber;
	int removeId;
	checkBookList(); // 도서 리스트 출력
	while (true) {
		cout << "삭제하고 싶은 책 번호를 입력하시오(이전 메뉴(-1)) : ";
		cin >> removeNumber;
		if (removeNumber == -1) break;
		else if (removeNumber < 1 || removeNumber > booksSize) { // 잘못된 숫자 입력 시
			cout << "                                            잘못된 입력입니다.\n";
		}
		else { 
			for (int i = 0; i < booksSize; i++) {
				if (books[i].getBookId() == removeNumber) {
					removeId = i;
					break;
				}
			}
			books.erase(books.begin() + removeId); // 도서 제거
			cout << "                                            삭제가 완료되었습니다.\n";
			break;
		}
	}
}
void BookStore::rentBook(Client& client) { // 도서 대여
	int rentNumber;
	int BooksSize = books.size();
	checkBookList();
	while (true) {
		cout << "빌리고 싶은 책 번호를 입력하시오(이전 메뉴(-1)) : ";
		cin >> rentNumber;
		if (rentNumber == -1) break;
		else if (rentNumber < 1 || rentNumber > BooksSize) { // 잘못된 숫자 입력 시
			cout << "                                            잘못된 입력입니다.\n";
		}
		else if (books[rentNumber - 1].getBookState() == "대여 가능") { // 대여 가능할 시
			books[rentNumber - 1].changeBookState(); // 책 상태 변경
			client.fillRentBook(books[rentNumber - 1]);
			cout << "                                            대여가 완료되었습니다.\n";
			break;
		}
		else if (books[rentNumber - 1].getBookState() == "대여 불가") { // 대여 불가 시
			cout << "                                            현재 대여 중이므로 대여할 수 없습니다.\n";
		}
	}
}
void BookStore::returnBook(Client& client) { // 도서 반납
	int returnNumber;
	client.printRentBooks(); // 도서내역 출력
	int booksSize = books.size();
	while (true) {
		cout << "반납 하고 싶은 책 번호를 입력하시오(이전 메뉴(-1)) : ";
		cin >> returnNumber;
		if (returnNumber == -1) break;
		else if (client.emptyRentBooks(returnNumber)) {
			for (int i = 0; i < booksSize; i++) {
				if (books[i].getBookId() == returnNumber) {
					books[i].changeBookState(); // 책 상태 변경
					break;
				}
			}
			cout << "                                            정상적으로 반납되었습니다.\n";
			break;
		}
		else cout << "                                            잘못된 입력입니다.\n";
	}
}
bool BookStore::widthDraw(Client& client) { // 회원 탈퇴
	int clientsSize = clients.size();
	int widthDrawId;
	char isReal;
	if (client.getRentBooksSize() > 0) { // 대여 중인 도서가 있으면
		cout << "                                            대여 중인 도서가 있으므로 탈퇴할 수 없습니다.\n";
		return false;
	}
	while (true) {
		cout << "                                            정말 탈퇴하시겠습니까?(Y, N) : ";
		cin >> isReal;
		if (isReal == 'Y' || isReal == 'y') break;
		else if (isReal == 'N' || isReal == 'n') {
			cout << "                                            탈퇴를 취소하였습니다.\n";
			return false;
		}
		else cout << "                                            잘못된 입력입니다.\n";
	}
	for (int i = 0; i < clientsSize; i++) { 
		if (client.getClientId() == clients[i].getClientId()) {
			widthDrawId = i;
			break;
		}
	}
	cout << "                                            정상적으로 탈퇴되었습니다.\n";
	clients.erase(clients.begin() + widthDrawId);
	return true;
}
void BookStore::signUp() { // 회원가입
	int clientsSize = clients.size();
	string _id;
	string _password;
	string _name;
	string _phoneNumber;
	cout << "\n==========회원가입을 진행합니다.==========\n";
	while (true) {
		bool isIdRight = true;
		cout << "사용하고자 하는 아이디를 입력하시오 : ";
		cin >> _id;
		for (int i = 0; i < clientsSize; i++) {
			if (_id == clients[i].getClientId()) { // 기존의 아이디와 같으면 
				cout << "                                            해당하는 아이디가 이미 존재합니다.\n";
				isIdRight = false;
				break;
			}
		}
		if (isIdRight == true) {
			cout << "                                            회원가입이 완료되었습니다.\n";
			break;
		}
	}
	cout << "사용하고자 하는 비밀번호를 입력하시오 : ";
	cin >> _password;
	cout << "이름을 입력하시오 : ";
	cin >> _name;
	cout << "휴대폰 번호를 입력하시오(010-xxxx-xxxx) : ";
	cin >> _phoneNumber;
	cout << "==========회원가입을 마쳤습니다.==========\n\n";
	addClient(Client(_id, _password, _name, _phoneNumber));
}
Client* BookStore::login() { // 로그인 
	int clientsSize = clients.size();
	string _id;
	string _password;
	cout << "\n==========로그인을 진행합니다.==========\n";
	cout << "ID를 입력하시오 : ";
	cin >> _id;
	cout << "비밀번호를 입력하시오 : ";
	cin >> _password;
	for (int i = 0; i < clientsSize; i++) {
		if (_id == clients[i].getClientId()) { // 아이디가 같으면
			if (_password == clients[i].getPassword()) { // 비밀번호가 같으면
				cout << "=========로그인에 성공했습니다.=========\n\n";
				return &clients[i];
			}
		}
	}
	cout << "=========로그인에 실패했습니다.=========\n";
	return nullptr;
}
void BookStore::addClient(const Client& client) { // 회원 추가
	clients.push_back(client);
}