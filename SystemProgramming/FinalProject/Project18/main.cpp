#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <mutex>
#include <thread>
#include <time.h>

using namespace std;

bool LoadInteger(int arr[30])
{
	try {
		ifstream fin;
		int num = 0;
		int temp = 0;
		time_t nowTime = time(NULL);
		tm *lt = localtime(&nowTime);

		fin.open("integer.txt");
		if (!fin.is_open()) throw 0;

		while (!fin.eof())
		{
			if (num > 29) throw 1; // 자료의갯수가 30개보다 많으면

			fin >> arr[num];
			if (fin.fail()) throw 2; // 정수형이 아닌 다른 것이 들어오면 
			num++;
		}
		if (num != 30) throw 1; // 자료의 갯수가 30개가 아니면 , 위에서 많은 경우는 체크 따라서 적은경우만 이곳에서 걸림

		cout << "자료 : ";
		for (int i = 0; i < 30; i++)
		{
			cout << arr[i] << " ";
		}

		cout << endl << "접근 시간 : "<< lt->tm_year + 1900 << "년 " <<
			lt->tm_mon + 1 << "월 " << lt->tm_mday << "일 " << lt->tm_hour  << "시 " << lt->tm_min  << "분" <<endl;
		return true;
	}
	catch (int expn)
	{
		switch (expn)
		{
		case 0:  // 파일 오픈 x
			cout << "파일 오픈 실패" << endl;
			break;
		case 1:
			cout << "자료의 갯수를 확인해주세요." << endl;
			break;
		case 2:
			cout << "자료에 숫자가 아닌 다른 문자가 있는 지 확인해주세요." << endl;
			break;
		default:
			cout << "원인을 알 수 없는 오류입니다." << endl;
			break;
		}

		return false;
	}
}

void GetSum(int arr[30], int& sum, mutex& m , int startIdx)
{
	m.lock();

	for (int i = startIdx; i < startIdx+10; i++)
	{
		sum += arr[i];
	}

	m.unlock();

	return;
}

void PrintSumAver(int& sum, mutex mArr[3])
{
	mArr[0].lock();
	mArr[1].lock();
	mArr[2].lock();

	cout << "합계 : " << sum << "  평균 : " << (float)sum / 30 << endl;

	mArr[0].unlock();
	mArr[1].unlock();
	mArr[2].unlock();
}

int main()
{
	int arr[30];
	if (!LoadInteger(arr))
	{
		cout << "파일 불러오기 실패" << endl;
		return 0;
	}

	int sum = 0;
	mutex m[3];
	thread sumFunc1(GetSum,arr,ref(sum),ref(m[0]),0);
	thread sumFunc2(GetSum,arr,ref(sum),ref(m[1]),10);
	thread sumFunc3(GetSum,arr,ref(sum),ref(m[2]),20);
	thread printFunc(PrintSumAver, ref(sum), m);

	sumFunc1.join();
	sumFunc2.join();
	sumFunc3.join();
	printFunc.join();


	return 0;
}