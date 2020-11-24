#include <iostream>
#include <Windows.h>
#include <thread>
#include <vector>

using namespace std;

// 10���ۿ� for���� ���ư��� �ʾƼ� �����尡 �Դٰ����ϸ鼭 �����ϴ°�ó�� ������ �ʴµ�
// ������ 10�����ƴ� 10�������� �ø��� �Դٰ��� �ϸ鼭 ����˴ϴ�.

void input(vector<int>& vec,CRITICAL_SECTION& crit1, CRITICAL_SECTION& crit2)
{
	EnterCriticalSection(&crit1);
	EnterCriticalSection(&crit2);

	int a;

	cout << " input thread ����" << endl;
	for (int i = 0; i < 10; i++)
	{
		cin >> a;
		vec.push_back(a);
	}

	LeaveCriticalSection(&crit1);
	LeaveCriticalSection(&crit2);

	cout << " input thread ����" << endl;
	return;
}

void GetAverage(vector<int>& vec,float& aver ,CRITICAL_SECTION& crit)
{
	EnterCriticalSection(&crit);

	cout << " aver thread ����" << endl;

	for (auto iter : vec)
	{
		cout << " aver thread ���� ��"<< endl;
		aver += iter;
	}

	aver /= vec.size();

	cout << " aver thread ����" << endl;
	LeaveCriticalSection(&crit);
	return;
}

void GetSum(vector<int>& vec,int& sum, CRITICAL_SECTION& crit)
{
	EnterCriticalSection(&crit);

	cout << " sum thread ����" << endl;

	for (auto iter : vec)
	{
		cout << " sum thread ���� ��" << endl;
		sum += iter;
	}
	cout << " sum thread ����" << endl;
	LeaveCriticalSection(&crit);
	return;
}

void Print(vector<int>& vec, float& aver, int& sum, CRITICAL_SECTION& crit1, CRITICAL_SECTION& crit2)
{
	EnterCriticalSection(&crit1);
	EnterCriticalSection(&crit2);

	cout << "�Է¹��� ��:";
	for (auto iter : vec)
	{
		cout << " " << iter;
	}
	cout << endl;

	cout << "��� : " << aver << endl;
	cout << "�հ� : " << sum << endl;
	LeaveCriticalSection(&crit1);
	LeaveCriticalSection(&crit2);

	return;
}

int main()
{
	vector<int> v;
	float aver=0;
	int sum=0;

	CRITICAL_SECTION crit1;
	CRITICAL_SECTION crit2;

	InitializeCriticalSection(&crit1);
	InitializeCriticalSection(&crit2);

	thread inputFunc(input,ref(v),ref(crit1),ref(crit2));
	thread averFunc(GetAverage, ref(v), ref(aver), ref(crit2));
	thread sumFunc(GetSum, ref(v), ref(sum), ref(crit1));
	thread printFunc(Print, ref(v), ref(aver), ref(sum), ref(crit1), ref(crit2));

	inputFunc.join();
	averFunc.join();
	sumFunc.join();
	printFunc.join();


	DeleteCriticalSection(&crit1);
	DeleteCriticalSection(&crit2);

	return 0;
}