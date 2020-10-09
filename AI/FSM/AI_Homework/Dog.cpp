#include "Dog.h"
#include "Mom.h"

Dog::Dog(string input) : Character(input)
{
	isSleep = -1;
	allCharacters.push_back(this);
}

Dog::~Dog()
{
}

void Dog::Update(int time)
{
	TextColor(RED, BLACK);
	if (isSleep == -1)
	{
		int temp = rand() % 8;
		if (temp == 0)
			isSleep = 3;
		else if (temp == 1)
		{
			cout << name << " : �۸۸۸�!!(�񸻶� ����)" << endl;
			if (GetCharacter("mother") != nullptr)
			{
				Mom* mom = dynamic_cast<Mom*>(GetCharacter("mother"));
				mom->WaterToDog();
				TextColor(RED, BLACK);
			}
		}

		cout << name << " : �۸۸۸�!!" << endl;
	}
	else
	{
		cout << name << " : ZZZZ...." << endl;
		isSleep--;
	}
}
