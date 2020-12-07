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
			if (num > 29) throw 1; // �ڷ��ǰ����� 30������ ������

			fin >> arr[num];
			if (fin.fail()) throw 2; // �������� �ƴ� �ٸ� ���� ������ 
			num++;
		}
		if (num != 30) throw 1; // �ڷ��� ������ 30���� �ƴϸ� , ������ ���� ���� üũ ���� ������츸 �̰����� �ɸ�

		cout << "�ڷ� : ";
		for (int i = 0; i < 30; i++)
		{
			cout << arr[i] << " ";
		}

		cout << endl << "���� �ð� : "<< lt->tm_year + 1900 << "�� " <<
			lt->tm_mon + 1 << "�� " << lt->tm_mday << "�� " << lt->tm_hour  << "�� " << lt->tm_min  << "��" <<endl;
		return true;
	}
	catch (int expn)
	{
		switch (expn)
		{
		case 0:  // ���� ���� x
			cout << "���� ���� ����" << endl;
			break;
		case 1:
			cout << "�ڷ��� ������ Ȯ�����ּ���." << endl;
			break;
		case 2:
			cout << "�ڷῡ ���ڰ� �ƴ� �ٸ� ���ڰ� �ִ� �� Ȯ�����ּ���." << endl;
			break;
		default:
			cout << "������ �� �� ���� �����Դϴ�." << endl;
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

	cout << "�հ� : " << sum << "  ��� : " << (float)sum / 30 << endl;

	mArr[0].unlock();
	mArr[1].unlock();
	mArr[2].unlock();
}

int main()
{
	int arr[30];
	if (!LoadInteger(arr))
	{
		cout << "���� �ҷ����� ����" << endl;
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