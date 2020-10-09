#include "Student.h"
#include "State.h"
#include "Mom.h"
#include <iostream>
#include <Windows.h>

Student::Student(string input):Character(input)
{
	win = 0;
	homeWork = -2;
	isStudy = false;
	allCharacters.push_back(this);
}

Student::~Student()
{
}

void Student::AngrySay()
{
	TextColor(YELLOW, BLACK);
	if (homeWork == -2)
		cout << name << " : �̹� ���� �� ������ �����ִ°ſ���!" << endl;
	else
		cout << name << " : ���� �ҷ��� �߾�� ��.��....." << endl;
	Sleep(800);
}

void Student::HouseUpdate(int time)
{
	if (time > 23 || time < 7)
	{
		homeWork = -2;
		cout << name << ": ZZZZ......" << endl;
	}
	else if (time== 7)
		SwitchState(SCHOOL);
	else
	{
		switch (homeWork)
		{
		case 2:
			isStudy = true;
			cout << name << ": ������ �����ؾ߰ڴ�." << endl;
			homeWork--;
			break;
		case 1:
			cout << name << ":���� �� ���� �� ������?" << endl;
			homeWork--;
			break;
		case 0:
			cout << name << ": ���� ������ ���ߴ�!" << endl;
			homeWork--;
			break;
		default:
			isStudy = false;
			cout << name << ": ������ �޽� �� �Դϴ�." << endl;
			break;
		}
	}
}

void Student::PCUpdate(int time)
{
	int temp = rand() % 2;
	if (temp == 0)
	{
		cout << name << ": �����ȴ�..." << endl;
	}
	else
	{
		win++;
		cout << name << ": " << win << "���� �ߴ�!" << endl;
	}

	if (win > 2)
	{
		win = 0;
		cout << name << ": ���� ���� ���߰ڴ�." << endl;
		SwitchState(HOUSE);
		if (GetCharacter("mother") != nullptr)
		{
			Mom* mom = dynamic_cast<Mom*>(GetCharacter("mother"));
			mom->Greet();
			TextColor(YELLOW, BLACK);
			cout << name << ": �ٳ�Ծ��." << endl;
		}
		return;
	}

	if (time > 21)
	{
		win = 0;
		cout << name << ": ����� 10�ð� �Ѿ���ȳ�.. ���� ���߰ڴ�.." << endl;
		SwitchState(HOUSE);
		if (GetCharacter("mother") != nullptr)
		{
			Mom* mom = dynamic_cast<Mom*>(GetCharacter("mother"));
			mom->AngrySay();
		}
		TextColor(YELLOW, BLACK);
		cout << name << ": �˾Ƽ� �ҰԿ�.." << endl;
		return;
	}

}

void Student::SchoolUpdate(int time)
{
	if (time == 16)
	{
		int temp = rand() % 2;
		switch (temp)
		{
		case 0:
			cout << name << ": ������ ������ �ֳ�. ������ ���߰ڴ�." << endl;
			homeWork = 2;
			SwitchState(HOUSE);
			if (GetCharacter("mother") != nullptr)
			{
				Mom* mom = dynamic_cast<Mom*>(GetCharacter("mother"));
				mom->Greet();
				TextColor(YELLOW, BLACK);
				cout << name << ": �ٳ�Ծ��." << endl;
			}
			break;
		case 1:
			cout << name << ": ������ ���µ� pc���̳� ������" << endl;
			SwitchState(PC);
			break;
		}
	}
	else
		cout << name << "�� �б����� �������Դϴ�." << endl;
}

void Student::Update(int time)
{
	TextColor(YELLOW, BLACK);
	switch(state.GetSpace())
	{
	case HOUSE:
		HouseUpdate(time);
		break;
	case SCHOOL:
		SchoolUpdate(time);
		break;
	case PC:
		PCUpdate(time);
		break;
	}
}
