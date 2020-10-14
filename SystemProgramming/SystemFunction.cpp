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

	cout << "오늘 날짜는 " << lt->tm_year + 1900 << "년 " <<
		lt->tm_mon + 1 << "월 " << lt->tm_mday << "일 입니다." << endl;

	cout << "현재 시간은 " << lt->tm_hour  << "시 " << lt->tm_min  << "분 입니다." << endl;

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