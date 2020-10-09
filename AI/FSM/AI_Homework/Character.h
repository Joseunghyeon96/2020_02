#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "State.h"

using namespace std;

enum Color
{
	 BLACK,
	 BLUE,
	 GREEN, 
	 CYAN, 
	 RED, 
	 MAGENTA, 
	 BROWN, 
	 LIGHTGRAY, 
	 DARKGRAY, 
	 LIGHTBLUE, 
	 LIGHTGREEN, 
	 LIGHTCYAN, 
	 LIGHTRED, 
	 LIGHTMAGENTA, 
	 YELLOW, 
	 WHITE, 
};

class Character
{
	friend class Student;
	friend class Mom;
	friend class Dog;

	string name;
	State state;
	static vector<Character*> allCharacters;

public:

	Character(string);
	~Character();

	static vector<Character*> AllCharacters()
	{
		return allCharacters;
	};
	void TextColor(int,int);
	State GetState();
	Character* GetCharacter(string);
	virtual void PrintLocation();
	virtual void SwitchState(int);
	virtual void Update();
	virtual void Update(int);
};

