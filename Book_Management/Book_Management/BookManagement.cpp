#include <iostream>
#include "BookStore.h"
#include <Windows.h>
using namespace std;

void init();
void startAdminister();
void startUser();
void beforeStartUser();
void selectUserType();

Client* client = nullptr; // ���� �α��� �����
int main(void) {
	init();
	selectUserType();

	system("pause");
	return 0;
}

void selectUserType() { // ������, ����� ����
	int userType;
	while (true) {
		cout << "������(0) / �����(1) / ���α׷� ����(2)�� �Է��Ͻÿ� : ";
		cin >> userType;
		switch (userType) {
			case 0:
				startAdminister(); // ������ ��� ����
				break;
			case 1:
				while (client == nullptr) {
					beforeStartUser(); // ȸ������, �α��� ����
				}
				startUser(); // �α����� ���������� ���� �� ����� ��� ����
				break;
			case 2:
				exit(0); // ���α׷� ����
			default:
				cout << "                                            ��ȣ�� �߸��Ǿ����ϴ�. �ٽ��Է����ּ���.\n";
				break;
		}
	}
}
void startAdminister() { // �����ڸ��
	int number;
	cout << "                                            �����ڷ� �α��εǾ����ϴ�.\n";

	while (true) {
		cout << "1. ���� �߰��ϱ�\n";
		cout << "2. ���� �����ϱ�\n";
		cout << "3. ��ü������� Ȯ���ϱ�\n";
		cout << "4. ��üȸ����� Ȯ���ϱ�\n";
		cout << "5. ����� ���� �̵��ϱ�\n";
		cout << "6. ���α׷� �����ϱ�\n\n";
		cout << "��ȣ�� �Է��Ͻÿ� : ";
		cin >> number;
		
		switch (number) {
			case 1 :
				BookStore::getInstance()->addBook(); // ���� �߰��ϱ�
				break;
			case 2 :
				BookStore::getInstance()->removeBook(); // ���� �����ϱ�
				break;
			case 3 : 
				BookStore::getInstance()->checkBookList(); // ��ü������� Ȯ���ϱ�
				break;
			case 4 :
				BookStore::getInstance()->checkClientList(); // ��üȸ����� Ȯ���ϱ�
				break;
			case 5:
				while (client == nullptr) {
					beforeStartUser(); // ȸ������, �α��� ����
				}
				startUser(); // �α����� ���������� ���� �� ����� ��� ����
				break;
			case 6 :
				exit(0);
			default :
				cout << "                                            ��ȣ�� �߸��Ǿ����ϴ�. �ٽ��Է����ּ���.\n";
				break;
		}
	}
}
void startUser() {
	int number;
	cout << "                                            ����ڷ� �α��εǾ����ϴ�.\n";

	while (true) {
		cout << "1. ��ü������� Ȯ���ϱ�\n";
		cout << "2. ���� �뿩�ϱ�\n";
		cout << "3. ���� �ݳ��ϱ�\n";
		cout << "4. ���� �����뿩 ���� Ȯ���ϱ�\n";
		cout << "5. ȸ�� Ż���ϱ�\n";
		cout << "6. ������ ���� �̵��ϱ�\n";
		cout << "7. ���α׷� �����ϱ�\n\n";
		cout << "��ȣ�� �Է��Ͻÿ� : ";
		cin >> number;
		
		switch (number) {
		case 1:
			BookStore::getInstance()->checkBookList(); // ��ü������� Ȯ���ϱ�
			break;
		case 2:
			BookStore::getInstance()->rentBook(*client); // ���� �뿩�ϱ�
			break;
		case 3:
			BookStore::getInstance()->returnBook(*client); // ���� �ݳ��ϱ�
			break;
		case 4:
			client->printRentBooks(); // �α��� ������� �����뿩 ���� Ȯ��
			break;
		case 5:
			if (BookStore::getInstance()->widthDraw(*client)) { // ȸ��Ż�� ���������� �Ǿ�����
				client = nullptr;
				selectUserType(); // ������, ����� ���� â���� �̵�
			}
			break;
		case 6:
			client = nullptr; 
			startAdminister(); // ������ ���� �̵�
			break;
		case 7:
			exit(0);
		default:
			cout << "                                            ��ȣ�� �߸��Ǿ����ϴ�. �ٽ��Է����ּ���.\n";
			break;
		}
	}
}
void init() { // �ʱ� ������
	BookStore::getInstance()->addBook(Book("�ȶ�Ƽ��", "�迵ȯ", 13000));
	BookStore::getInstance()->addBook(Book("PowerJava", "õ�α�", 28000));
	BookStore::getInstance()->addBook(Book("���", "ä��", 17000));
	BookStore::getInstance()->addBook(Book("���ΰ��ٴ�", "�ȼ���", 31000));
	BookStore::getInstance()->addBook(Book("�ΰ���ǰ��", "��쿬", 15000));
	BookStore::getInstance()->addBook(Book("û���ǵ���", "������", 26000));
	BookStore::getInstance()->addBook(Book("��������", "������", 24000));
	BookStore::getInstance()->addBook(Book("�ɾ�������", "�ϻ�ȣ", 10000));
	BookStore::getInstance()->addBook(Book("�������̷��", "�ֿ���", 48000));
	BookStore::getInstance()->addBook(Book("Ÿ�ο��Ը��ɱ�", "�Ѽ���", 29000));
	BookStore::getInstance()->addClient(Client("abcd000", "qwer000", "ȫ�浿", "010-0000-0001"));
	BookStore::getInstance()->addClient(Client("abcd001", "qwer001", "������", "010-0000-0002"));
	BookStore::getInstance()->addClient(Client("abcd002", "qwer002", "�迹��", "010-0000-0003"));
	BookStore::getInstance()->addClient(Client("abcd003", "qwer003", "�赵��", "010-0000-0004"));
	BookStore::getInstance()->addClient(Client("abcd004", "qwer004", "���ֿ�", "010-0000-0005"));
	BookStore::getInstance()->addClient(Client("abcd005", "qwer005", "������", "010-0000-0006"));
	BookStore::getInstance()->addClient(Client("abcd006", "qwer006", "���ؼ�", "010-0000-0007"));
	BookStore::getInstance()->addClient(Client("abcd007", "qwer007", "������", "010-0000-0008"));
	BookStore::getInstance()->addClient(Client("abcd008", "qwer008", "������", "010-0000-0009"));
	BookStore::getInstance()->addClient(Client("abcd009", "qwer009", "���ǿ�", "010-0000-0000"));
}
void beforeStartUser() {
	int loginType;
	cout << "ȸ������(0) / �α���(1) / ���α׷� ����(2)�� �Է��Ͻÿ� : ";
	cin >> loginType;

	switch (loginType) {
	case 0:
		BookStore::getInstance()->signUp(); // ȸ������
		client = BookStore::getInstance()->login(); // �α���
		break;
	case 1:
		client = BookStore::getInstance()->login(); // �α���
		break;
	case 2:
		exit(0);
	default:
		cout << "                                            ��ȣ�� �߸��Ǿ����ϴ�. �ٽ��Է����ּ���.\n";
		break;
	}
}