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

bool PersonException(person input)//올바른 형태의 번호가 아니면 return false
{
	int personNumber = input.personNumber;
	string email = input.email;
	string name = input.name;
	string phoneNumber = input.phoneNumber;
	
	// ******************* personNumber 예외처리 ****************
	try {
		if (personNumber < 0) // 번호가 음수면
			throw 0;
	}
	catch (...) {
		cout << "올바른 번호를 입력하세요." << endl;
		return false;
	}

	// ******************* name 예외처리 ***********************
	try {
		for (int i = 0; i < name.size(); i++)
		{
			if (name.at(i) <= '9' && name.at(i) >= '0') throw i;
		}
	}
	catch (int i)
	{
		cout << "이름에 숫자가 들어가있습니다. " << endl;
		return false;
	}

	//******************** phone number예외처리*************
	try {
		if (phoneNumber.at(0) == '-') throw '-'; // 첫자리가 -면

		for (int i = 0; i < phoneNumber.size(); i++) // '-' 나 숫자가 아닌 다른 것이 입력으로 들어올 경우
		{
			if (phoneNumber.at(i) != '-' && (phoneNumber.at(i) < '0' || phoneNumber.at(i) > '9')) throw phoneNumber;
		}
	}
	catch (char c)
	{
		cout << "전화번호 형식이 올바르지 않습니다." << endl;
		return false;
	}
	catch (...)
	{
		cout << "전화번호 형식이 올바르지 않습니다." << endl;
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
	cout << "\n번호를 입력하세요 : ";
	cin >> tempPerson.personNumber;
	cout << "이름을 입력하세요 : ";
	cin >> tempPerson.name;
	cout << "email을 입력하세요 : ";
	cin >> tempPerson.email;
	cout << "휴대폰 번호를 입력하세요.(xxx-xxx-xxxx 형식으로 입력) : ";
	cin >> tempPerson.phoneNumber;
	cout << endl;
	if (!PersonException(tempPerson))
	{
		fout.close();
		cout << "저장에 실패했습니다." << endl;
		return;
	}

	string timeStr;
	time_t nowTime = time(NULL);
	tm *lt = localtime(&nowTime);

	timeStr = to_string(lt->tm_year + 1900) + "년" + to_string(lt->tm_mon + 1) + "월" + to_string(lt->tm_mday) + "일 "
		+ to_string(lt->tm_hour) + ":" + to_string(lt->tm_min);

	fout.setf(ios::left);
	fout << setw(7) <<tempPerson.personNumber << setw(7) << tempPerson.name << setw(25) << tempPerson.phoneNumber << setw(25) << tempPerson.email << setw(30) << timeStr << endl;
	cout << "저장이 완료되었습니다." << endl;
	fout.close();

	return;
}

void PrintAllPerson()
{
	cout << endl;
	try {
		ifstream fin("address.dat");
		if (!fin.is_open()) throw 0;

		cout << "번호\t이름\t전화번호\t\t이메일주소\t\t저장된 일시" << endl;
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
			cout << "파일 오픈에 실패하였습니다." << endl;
		return;
	}
}
void DeleteAllData()
{
	remove("address.dat");
	cout << "\n모든 자료를 삭제하였습니다." << endl;
}

void DeleteSelectData()
{
	cout << endl;
	try {
		int number = -1;
		cout << "지우고 싶은 데이터의 번호를 입력해주세요.";
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
			if (tNum == -1) break; // 자료끝

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

		if (!isDelete) // 아무파일도 삭제를 안한경우
		{
			remove("temp.dat");
			throw 1;
		}

		remove("address.dat");
		rename("temp.dat", "address.dat");
		cout << "지정하신 번호를 가진 데이터를 모두 삭제하였습니다." << endl;


	}
	catch (int errorType)
	{
		if (errorType == 0)
			cout << "파일 오픈에 실패하였습니다!" << endl;
		else if (errorType == 1)
			cout << "삭제 하려는 번호를 가진 데이터를 찾지 못했습니다." << endl;
		else if (errorType < 0)
			cout << "삭제 하려는 번호가 잘못되었습니다." << endl;
		
		return;
	}
}

void PrintSelectData() {
	cout << endl;
	try {
		int number = -1;
		cout << "출력하고 싶은 데이터의 번호를 입력해주세요.";
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
			if (tNum == -1) break; // 자료끝

			fin.getline(buffer, 99);

			if (tNum == number)
			{
				if(!isPrint) cout << "\n번호\t이름\t전화번호\t\t이메일주소\t\t저장된 일시" << endl;

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
			cout << "출력하려는 번호가 잘못되었습니다." << endl;
		else if (eType == 0)
			cout << "파일열기를 실패하였습니다." << endl;
		else if (eType == -2)
			cout << "출력하려는 번호를 찾지 못하였습니다." << endl;

		return;
	}
}
int main()
{
	char c = ' ';
	while (c != '6')
	{
		cout << "무엇을 실행하길 원하시나요?\n(1) 자료 추가 (2)특정자료삭제 (3) 전체자료삭제 (4) 전체자료출력 (5) 특정자료출력 (6)종료 \n입력해주세요 : ";
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
			cout << "프로그램을 종료합니다." << endl;
			break;
		default:
			cout << "정해진 숫자만 입력해주세요." << endl;
			break;
		}
		cout << "\n\n\n\n\n\n" << endl;
	}
	return 0;
}