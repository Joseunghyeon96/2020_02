#include "Mom.h"
#include "Student.h"
#include <Windows.h>

Mom::Mom(string input):Character(input)
{
	bathRoom = false;
	isGreet = false;
	isCheck = true;
	isSleep = true;
	allCharacters.push_back(this);
}

Mom::~Mom()
{
}

void Mom::HouseUpdate(int time)
{
	if (time > 23 || time < 7)
	{
		isSleep = true;
		cout << name << ": ZZZZ......" << endl;
		isGreet = true;
		isCheck = true;
		return;
	}

	isSleep = false;
	if (bathRoom)
	{
		cout << name << ": 화장실을 갔다와야겠다.." << endl;
		bathRoom = false;
	}
	else {
		if (rand() % 5 == 0)
			bathRoom = true;
	}

	if (time == 12 || time == 18 || time == 13 || time == 19)
	{
		cout << name << ": 요리를 해야겠다." << endl;
		return;
	}
	else
	{
		cout << name << " : 집에서 휴식중입니다."<<endl;
		if (rand() % 3 == 0)
		{
			if(isCheck)
			CheckStudy();
		}
	}
}

void Mom::Update(int time)
{
	TextColor(BLUE, BLACK);
	HouseUpdate(time);
}

void Mom::CheckStudy()
{
	
	if (GetCharacter("SH") != nullptr)
	{
		Student* sun = dynamic_cast<Student*>(GetCharacter("SH"));
		if (sun->GetState().GetSpace() != HOUSE) return;

		isCheck = false;
		cout << name << " : 우리 아들 뭐하는지 볼까?"<< endl;
		Sleep(800);
		if (sun->GetIsStudy())
		{
			cout << name << " : 우리 아들 공부 열심히하네~" << endl;
		}
		else
		{
			cout << name << " : 아들!! 맨날 게임만 하지말고 공부도 좀 해!" << endl;
			sun->AngrySay();
		}
		TextColor(BLUE, BLACK);
	}
}

void Mom::AngrySay()
{
	TextColor(BLUE, BLACK);
	cout << name << " : 뭐하다가 이 시간에 들어와! 공부좀 해라.." << endl;
}

void Mom::WaterToDog()
{
	Sleep(800);
	TextColor(BLUE, BLACK);
	if(!isSleep)
		cout << name << ": 댕댕이 목마르구나. 물줄게" << endl;
	else
		cout << name << ": 댕댕아 지금이 몇시야 .. 잠 좀 자자.." << endl;
}

void Mom::Greet()
{
	Sleep(800);
	TextColor(BLUE, BLACK);
	cout << name << ": 우리 아들 왔구나~" << endl;
}
