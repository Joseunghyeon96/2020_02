#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <time.h>
#include <iomanip>

using namespace std;

struct person {

public:
	int personNumber;
	string email;
	string name;
	string phoneNumber;
};

bool PersonException(person input)//�ùٸ� ������ ��ȣ�� �ƴϸ� return false
{
	int personNumber = input.personNumber;
	string email = input.email;
	string name = input.name;
	string phoneNumber = input.phoneNumber;
	
	// ******************* personNumber ����ó�� ****************
	try {
		if (personNumber < 0) // ��ȣ�� ������
			throw 0;
	}
	catch (...) {
		cout << "�ùٸ� ��ȣ�� �Է��ϼ���." << endl;
		return false;
	}

	// ******************* name ����ó�� ***********************
	try {
		for (int i = 0; i < name.size(); i++)
		{
			if (name.at(i) <= '9' && name.at(i) >= '0') throw i;
		}
	}
	catch (int i)
	{
		cout << "�̸��� ���ڰ� ���ֽ��ϴ�. " << endl;
		return false;
	}

	//******************** phone number����ó��*************
	try {
		if (phoneNumber.at(0) == '-') throw '-'; // ù�ڸ��� -��

		for (int i = 0; i < phoneNumber.size(); i++) // '-' �� ���ڰ� �ƴ� �ٸ� ���� �Է����� ���� ���
		{
			if (phoneNumber.at(i) != '-' && (phoneNumber.at(i) < '0' || phoneNumber.at(i) > '9')) throw phoneNumber;
		}
	}
	catch (char c)
	{
		cout << "��ȭ��ȣ ������ �ùٸ��� �ʽ��ϴ�." << endl;
		return false;
	}
	catch (...)
	{
		cout << "��ȭ��ȣ ������ �ùٸ��� �ʽ��ϴ�." << endl;
		return false;
	}

	return true;
}

void SavePerson()
{
	ofstream fout("address.dat",ios::app);
	if (!fout)
	{
		cout << "file open or create fail!\n" << endl;
		return;
	}

	person tempPerson;
	cout << "\n��ȣ�� �Է��ϼ��� : ";
	cin >> tempPerson.personNumber;
	cout << "�̸��� �Է��ϼ��� : ";
	cin >> tempPerson.name;
	cout << "email�� �Է��ϼ��� : ";
	cin >> tempPerson.email;
	cout << "�޴��� ��ȣ�� �Է��ϼ���.(xxx-xxx-xxxx �������� �Է�) : ";
	cin >> tempPerson.phoneNumber;
	cout << endl;
	if (!PersonException(tempPerson))
	{
		fout.close();
		cout << "���忡 �����߽��ϴ�." << endl;
		return;
	}

	string timeStr;
	time_t nowTime = time(NULL);
	tm *lt = localtime(&nowTime);

	timeStr = to_string(lt->tm_year + 1900) + "��" + to_string(lt->tm_mon + 1) + "��" + to_string(lt->tm_mday) + "�� "
		+ to_string(lt->tm_hour) + ":" + to_string(lt->tm_min);

	fout.setf(ios::left);
	fout << setw(7) <<tempPerson.personNumber << setw(7) << tempPerson.name << setw(25) << tempPerson.phoneNumber << setw(25) << tempPerson.email << setw(30) << timeStr << endl;
	cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
	fout.close();

	return;
}

void PrintAllPerson()
{
	cout << endl;
	try {
		ifstream fin("address.dat");
		if (!fin.is_open()) throw 0;

		cout << "��ȣ\t�̸�\t��ȭ��ȣ\t\t�̸����ּ�\t\t����� �Ͻ�" << endl;
		char buffer[100];
		while (!fin.eof())
		{
			fin.getline(buffer, 99);
			cout << buffer<<endl;
		}
		fin.close();
		return;
	}
	catch(int i){
		if (i == 0)
			cout << "���� ���¿� �����Ͽ����ϴ�." << endl;
		return;
	}
}
void DeleteAllData()
{
	remove("address.dat");
	cout << "\n��� �ڷḦ �����Ͽ����ϴ�." << endl;
}

void DeleteSelectData()
{
	cout << endl;
	try {
		int number = -1;
		cout << "����� ���� �������� ��ȣ�� �Է����ּ���.";
		cin >> number;
		if (number < 0) throw -1;

		ifstream fin("address.dat");
		if (!fin.is_open()) throw 0;
		ofstream temp("temp.dat");
		if (!temp) throw 0;
	
		char buffer[100];
		bool isDelete = false;

		while (!fin.eof())
		{

			int tNum = -1;
			fin >> tNum;
			if (tNum == -1) break; // �ڷ᳡

			fin.getline(buffer, 99);

			if (tNum == number)
				isDelete = true;
			else
			{
				temp << tNum << buffer << endl;
			}
		}

		fin.close();
		temp.close();

		if (!isDelete) // �ƹ����ϵ� ������ ���Ѱ��
		{
			remove("temp.dat");
			throw 1;
		}

		remove("address.dat");
		rename("temp.dat", "address.dat");
		cout << "�����Ͻ� ��ȣ�� ���� �����͸� ��� �����Ͽ����ϴ�." << endl;


	}
	catch (int errorType)
	{
		if (errorType == 0)
			cout << "���� ���¿� �����Ͽ����ϴ�!" << endl;
		else if (errorType == 1)
			cout << "���� �Ϸ��� ��ȣ�� ���� �����͸� ã�� ���߽��ϴ�." << endl;
		else if (errorType < 0)
			cout << "���� �Ϸ��� ��ȣ�� �߸��Ǿ����ϴ�." << endl;
		
		return;
	}
}

void PrintSelectData() {
	cout << endl;
	try {
		int number = -1;
		cout << "����ϰ� ���� �������� ��ȣ�� �Է����ּ���.";
		cin >> number;
		if (number < 0) throw - 1;

		ifstream fin("address.dat");
		if (!fin.is_open()) throw 0;

		char buffer[100];
		bool isPrint = false;
		while (!fin.eof())
		{

			int tNum = -1;
			fin >> tNum;
			if (tNum == -1) break; // �ڷ᳡

			fin.getline(buffer, 99);

			if (tNum == number)
			{
				if(!isPrint) cout << "\n��ȣ\t�̸�\t��ȭ��ȣ\t\t�̸����ּ�\t\t����� �Ͻ�" << endl;

				isPrint = true;
				cout << tNum << buffer << endl;
			}
		}

		fin.close();
		if (!isPrint) throw -2;

	}
	catch (int eType)
	{
		if (eType == -1)
			cout << "����Ϸ��� ��ȣ�� �߸��Ǿ����ϴ�." << endl;
		else if (eType == 0)
			cout << "���Ͽ��⸦ �����Ͽ����ϴ�." << endl;
		else if (eType == -2)
			cout << "����Ϸ��� ��ȣ�� ã�� ���Ͽ����ϴ�." << endl;

		return;
	}
}
int main()
{
	char c = ' ';
	while (c != '6')
	{
		cout << "������ �����ϱ� ���Ͻó���?\n(1) �ڷ� �߰� (2)Ư���ڷ���� (3) ��ü�ڷ���� (4) ��ü�ڷ���� (5) Ư���ڷ���� (6)���� \n�Է����ּ��� : ";
		cin >> c;

		switch (c)
		{
		case '1': SavePerson();
			break;
		case '2': DeleteSelectData();
			break;
		case '3': DeleteAllData();
			break;
		case '4': PrintAllPerson();
			break;
		case '5': PrintSelectData();
			break;
		case '6':
			cout << "���α׷��� �����մϴ�." << endl;
			break;
		default:
			cout << "������ ���ڸ� �Է����ּ���." << endl;
			break;
		}
		cout << "\n\n\n\n\n\n" << endl;
	}
	return 0;
}