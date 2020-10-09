#pragma once
#include "Character.h"

class State;

class Student :
	public Character
{
	int win;
	int homeWork;
	bool isStudy;
public:
	Student(string);
	~Student();
	bool GetIsStudy() { return isStudy; }
	void AngrySay();
	void HouseUpdate(int);
	void PCUpdate(int);
	void SchoolUpdate(int);
	void Update(int);
};

