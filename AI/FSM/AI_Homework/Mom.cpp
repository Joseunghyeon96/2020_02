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
		cout << name << ": ȭ����� ���ٿ;߰ڴ�.." << endl;
		bathRoom = false;
	}
	else {
		if (rand() % 5 == 0)
			bathRoom = true;
	}

	if (time == 12 || time == 18 || time == 13 || time == 19)
	{
		cout << name << ": �丮�� �ؾ߰ڴ�." << endl;
		return;
	}
	else
	{
		cout << name << " : ������ �޽����Դϴ�."<<endl;
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
		cout << name << " : �츮 �Ƶ� ���ϴ��� ����?"<< endl;
		Sleep(800);
		if (sun->GetIsStudy())
		{
			cout << name << " : �츮 �Ƶ� ���� �������ϳ�~" << endl;
		}
		else
		{
			cout << name << " : �Ƶ�!! �ǳ� ���Ӹ� �������� ���ε� �� ��!" << endl;
			sun->AngrySay();
		}
		TextColor(BLUE, BLACK);
	}
}

void Mom::AngrySay()
{
	TextColor(BLUE, BLACK);
	cout << name << " : ���ϴٰ� �� �ð��� ����! ������ �ض�.." << endl;
}

void Mom::WaterToDog()
{
	Sleep(800);
	TextColor(BLUE, BLACK);
	if(!isSleep)
		cout << name << ": ����� �񸶸�����. ���ٰ�" << endl;
	else
		cout << name << ": ���� ������ ��þ� .. �� �� ����.." << endl;
}

void Mom::Greet()
{
	Sleep(800);
	TextColor(BLUE, BLACK);
	cout << name << ": �츮 �Ƶ� �Ա���~" << endl;
}
