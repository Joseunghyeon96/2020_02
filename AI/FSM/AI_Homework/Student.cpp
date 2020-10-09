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
		cout << name << " : 이미 과제 다 끝내고 쉬고있는거에요!" << endl;
	else
		cout << name << " : 지금 할려고 했어요 ㅡ.ㅡ....." << endl;
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
			cout << name << ": 과제를 시작해야겠다." << endl;
			homeWork--;
			break;
		case 1:
			cout << name << ":거의 다 끝난 것 같은데?" << endl;
			homeWork--;
			break;
		case 0:
			cout << name << ": 드디어 과제를 다했다!" << endl;
			homeWork--;
			break;
		default:
			isStudy = false;
			cout << name << ": 집에서 휴식 중 입니다." << endl;
			break;
		}
	}
}

void Student::PCUpdate(int time)
{
	int temp = rand() % 2;
	if (temp == 0)
	{
		cout << name << ": 져버렸다..." << endl;
	}
	else
	{
		win++;
		cout << name << ": " << win << "승을 했다!" << endl;
	}

	if (win > 2)
	{
		win = 0;
		cout << name << ": 이제 집에 가야겠다." << endl;
		SwitchState(HOUSE);
		if (GetCharacter("mother") != nullptr)
		{
			Mom* mom = dynamic_cast<Mom*>(GetCharacter("mother"));
			mom->Greet();
			TextColor(YELLOW, BLACK);
			cout << name << ": 다녀왔어요." << endl;
		}
		return;
	}

	if (time > 21)
	{
		win = 0;
		cout << name << ": 어느새 10시가 넘어버렸네.. 집에 가야겠다.." << endl;
		SwitchState(HOUSE);
		if (GetCharacter("mother") != nullptr)
		{
			Mom* mom = dynamic_cast<Mom*>(GetCharacter("mother"));
			mom->AngrySay();
		}
		TextColor(YELLOW, BLACK);
		cout << name << ": 알아서 할게요.." << endl;
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
			cout << name << ": 오늘은 과제가 있네. 집으로 가야겠다." << endl;
			homeWork = 2;
			SwitchState(HOUSE);
			if (GetCharacter("mother") != nullptr)
			{
				Mom* mom = dynamic_cast<Mom*>(GetCharacter("mother"));
				mom->Greet();
				TextColor(YELLOW, BLACK);
				cout << name << ": 다녀왔어요." << endl;
			}
			break;
		case 1:
			cout << name << ": 과제가 없는데 pc방이나 가야지" << endl;
			SwitchState(PC);
			break;
		}
	}
	else
		cout << name << "이 학교에서 공부중입니다." << endl;
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
