#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

using namespace std;

void PrintTime()
{
	time_t nowTime = time(NULL);
	tm *lt = localtime(&nowTime);

	cout << "���� ��¥�� " << lt->tm_year + 1900 << "�� " <<
		lt->tm_mon + 1 << "�� " << lt->tm_mday << "�� �Դϴ�." << endl;

	cout << "���� �ð��� " << lt->tm_hour  << "�� " << lt->tm_min  << "�� �Դϴ�." << endl;

	return;
}

void PrintHostName()
{
	
	printf("%s\n", getenv("COMPUTERNAME"));
}

int main()
{
	PrintTime();
	printf("\n");
	PrintHostName();
	return 0;
}