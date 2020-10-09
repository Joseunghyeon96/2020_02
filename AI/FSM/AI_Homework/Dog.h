#pragma once
#include "Character.h"
class Dog :
	public Character
{
	int isSleep;

public:
	Dog(string);
	~Dog();

	void Update(int);
};

