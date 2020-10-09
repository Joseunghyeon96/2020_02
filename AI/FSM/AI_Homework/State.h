#pragma once
#include <string>
#include <iostream>

using namespace std;

enum state
{
	HOUSE,
	SCHOOL,
	PC
};
class State
{
	int state;
	string location;

public:
	State();
	~State();

	void SetState(int);
	int GetSpace();
	string GetLocation();
};

