#include "Character.h"
#include <windows.h>

vector<Character*> Character::allCharacters;

Character::Character(string input)
{
	name = input;
	state.SetState(HOUSE);
}

Character::~Character()
{
}

void Character::TextColor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

State Character::GetState()
{
	return state;
}

Character* Character::GetCharacter(string input)
{
	for (auto iter : allCharacters)
	{
		if (iter->name == input)
			return iter;
	}

	return nullptr;
}

void Character::PrintLocation()
{
	cout << state.GetLocation() << "에 있습니다." << endl;
}

void Character::SwitchState(int input)
{
	if (input == state.GetSpace()) return;

	string temp = state.GetLocation();
	state.SetState(input);
	cout << name <<"이 "<< temp << "에서 " << state.GetLocation() << "로 이동했습니다." << endl;
}

void Character::Update()
{
}

void Character::Update(int)
{
}
