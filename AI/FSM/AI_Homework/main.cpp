#include <iostream>
#include <string>
#include <Windows.h>
#include <time.h>
#include "Student.h"
#include "Mom.h"
#include "Dog.h"

using namespace std;

int main()
{
	srand(time(NULL));
	Student A("SH");
	Mom B("mother");
	Dog C("Dog");

	vector<Character*> allCharacters = Character::AllCharacters();

	for (int i = 0; i < 25; i++)
	{
		for (auto iter : allCharacters)
		{
			iter->Update(i%25);
		}

		Sleep(1000);
	}

	system("pause");
	return 0;
}