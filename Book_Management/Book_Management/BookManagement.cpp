#include <iostream>
#include "BookStore.h"
#include <Windows.h>
using namespace std;

void init();
void startAdminister();
void startUser();
void beforeStartUser();
void selectUserType();

Client* client = nullptr; // 현재 로그인 사용자
int main(void) {
	init();
	selectUserType();

	system("pause");
	return 0;
}

void selectUserType() { // 관리자, 사용자 선택
	int userType;
	while (true) {
		cout << "관리자(0) / 사용자(1) / 프로그램 종료(2)를 입력하시오 : ";
		cin >> userType;
		switch (userType) {
			case 0:
				startAdminister(); // 관리자 모드 시작
				break;
			case 1:
				while (client == nullptr) {
					beforeStartUser(); // 회원가입, 로그인 과정
				}
				startUser(); // 로그인이 정상적으로 됬을 시 사용자 모드 시작
				break;
			case 2:
				exit(0); // 프로그램 종료
			default:
				cout << "                                            번호가 잘못되었습니다. 다시입력해주세요.\n";
				break;
		}
	}
}
void startAdminister() { // 관리자모드
	int number;
	cout << "                                            관리자로 로그인되었습니다.\n";

	while (true) {
		cout << "1. 도서 추가하기\n";
		cout << "2. 도서 삭제하기\n";
		cout << "3. 전체도서목록 확인하기\n";
		cout << "4. 전체회원목록 확인하기\n";
		cout << "5. 사용자 모드로 이동하기\n";
		cout << "6. 프로그램 종료하기\n\n";
		cout << "번호를 입력하시오 : ";
		cin >> number;
		
		switch (number) {
			case 1 :
				BookStore::getInstance()->addBook(); // 도서 추가하기
				break;
			case 2 :
				BookStore::getInstance()->removeBook(); // 도서 삭제하기
				break;
			case 3 : 
				BookStore::getInstance()->checkBookList(); // 전체도서목록 확인하기
				break;
			case 4 :
				BookStore::getInstance()->checkClientList(); // 전체회원목록 확인하기
				break;
			case 5:
				while (client == nullptr) {
					beforeStartUser(); // 회원가입, 로그인 과정
				}
				startUser(); // 로그인이 정상적으로 됬을 시 사용자 모드 시작
				break;
			case 6 :
				exit(0);
			default :
				cout << "                                            번호가 잘못되었습니다. 다시입력해주세요.\n";
				break;
		}
	}
}
void startUser() {
	int number;
	cout << "                                            사용자로 로그인되었습니다.\n";

	while (true) {
		cout << "1. 전체도서목록 확인하기\n";
		cout << "2. 도서 대여하기\n";
		cout << "3. 도서 반납하기\n";
		cout << "4. 나의 도서대여 내역 확인하기\n";
		cout << "5. 회원 탈퇴하기\n";
		cout << "6. 관리자 모드로 이동하기\n";
		cout << "7. 프로그램 종료하기\n\n";
		cout << "번호를 입력하시오 : ";
		cin >> number;
		
		switch (number) {
		case 1:
			BookStore::getInstance()->checkBookList(); // 전체도서목록 확인하기
			break;
		case 2:
			BookStore::getInstance()->rentBook(*client); // 도서 대여하기
			break;
		case 3:
			BookStore::getInstance()->returnBook(*client); // 도서 반납하기
			break;
		case 4:
			client->printRentBooks(); // 로그인 사용자의 도서대여 내역 확인
			break;
		case 5:
			if (BookStore::getInstance()->widthDraw(*client)) { // 회원탈퇴가 정상적으로 되었으면
				client = nullptr;
				selectUserType(); // 관리자, 사용자 선택 창으로 이동
			}
			break;
		case 6:
			client = nullptr; 
			startAdminister(); // 관리자 모드로 이동
			break;
		case 7:
			exit(0);
		default:
			cout << "                                            번호가 잘못되었습니다. 다시입력해주세요.\n";
			break;
		}
	}
}
void init() { // 초기 데이터
	BookStore::getInstance()->addBook(Book("팔란티어", "김영환", 13000));
	BookStore::getInstance()->addBook(Book("PowerJava", "천인국", 28000));
	BookStore::getInstance()->addBook(Book("모모", "채희만", 17000));
	BookStore::getInstance()->addBook(Book("노인과바다", "안성일", 31000));
	BookStore::getInstance()->addBook(Book("인간의품격", "김우연", 15000));
	BookStore::getInstance()->addBook(Book("청춘의독서", "윤혜주", 26000));
	BookStore::getInstance()->addBook(Book("습관의힘", "최은정", 24000));
	BookStore::getInstance()->addBook(Book("걸어서세계까지", "하상호", 10000));
	BookStore::getInstance()->addBook(Book("기적을이룬꿈", "최영규", 48000));
	BookStore::getInstance()->addBook(Book("타인에게말걸기", "한석민", 29000));
	BookStore::getInstance()->addClient(Client("abcd000", "qwer000", "홍길동", "010-0000-0001"));
	BookStore::getInstance()->addClient(Client("abcd001", "qwer001", "서민준", "010-0000-0002"));
	BookStore::getInstance()->addClient(Client("abcd002", "qwer002", "김예준", "010-0000-0003"));
	BookStore::getInstance()->addClient(Client("abcd003", "qwer003", "김도윤", "010-0000-0004"));
	BookStore::getInstance()->addClient(Client("abcd004", "qwer004", "박주원", "010-0000-0005"));
	BookStore::getInstance()->addClient(Client("abcd005", "qwer005", "최하준", "010-0000-0006"));
	BookStore::getInstance()->addClient(Client("abcd006", "qwer006", "이준서", "010-0000-0007"));
	BookStore::getInstance()->addClient(Client("abcd007", "qwer007", "최현우", "010-0000-0008"));
	BookStore::getInstance()->addClient(Client("abcd008", "qwer008", "김지훈", "010-0000-0009"));
	BookStore::getInstance()->addClient(Client("abcd009", "qwer009", "도건우", "010-0000-0000"));
}
void beforeStartUser() {
	int loginType;
	cout << "회원가입(0) / 로그인(1) / 프로그램 종료(2)를 입력하시오 : ";
	cin >> loginType;

	switch (loginType) {
	case 0:
		BookStore::getInstance()->signUp(); // 회원가입
		client = BookStore::getInstance()->login(); // 로그인
		break;
	case 1:
		client = BookStore::getInstance()->login(); // 로그인
		break;
	case 2:
		exit(0);
	default:
		cout << "                                            번호가 잘못되었습니다. 다시입력해주세요.\n";
		break;
	}
}