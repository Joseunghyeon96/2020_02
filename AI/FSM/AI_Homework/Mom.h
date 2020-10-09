#pragma once
#include "Character.h"

class Mom :
	public Character
{
	bool bathRoom;
	bool isGreet;	
	bool isSleep;
	bool isCheck;
public:
	Mom(string);
	~Mom();
	void HouseUpdate(int);
	void Update(int);
	void CheckStudy();
	void AngrySay();
	void WaterToDog();
	void Greet();
};

