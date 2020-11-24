#include <iostream>
#include <Windows.h>
#include <thread>
#include <vector>

using namespace std;

// 10개밖에 for문이 돌아가지 않아서 쓰레드가 왔다갔다하면서 실행하는것처럼 보이지 않는데
// 갯수를 10개가아닌 10개정도만 늘리면 왔다갔다 하면서 실행됩니다.

void input(vector<int>& vec,CRITICAL_SECTION& crit1, CRITICAL_SECTION& crit2)
{
	EnterCriticalSection(&crit1);
	EnterCriticalSection(&crit2);

	int a;

	cout << " input thread 실행" << endl;
	for (int i = 0; i < 10; i++)
	{
		cin >> a;
		vec.push_back(a);
	}

	LeaveCriticalSection(&crit1);
	LeaveCriticalSection(&crit2);

	cout << " input thread 종료" << endl;
	return;
}

void GetAverage(vector<int>& vec,float& aver ,CRITICAL_SECTION& crit)
{
	EnterCriticalSection(&crit);

	cout << " aver thread 실행" << endl;

	for (auto iter : vec)
	{
		cout << " aver thread 실행 중"<< endl;
		aver += iter;
	}

	aver /= vec.size();

	cout << " aver thread 종료" << endl;
	LeaveCriticalSection(&crit);
	return;
}

void GetSum(vector<int>& vec,int& sum, CRITICAL_SECTION& crit)
{
	EnterCriticalSection(&crit);

	cout << " sum thread 실행" << endl;

	for (auto iter : vec)
	{
		cout << " sum thread 실행 중" << endl;
		sum += iter;
	}
	cout << " sum thread 종료" << endl;
	LeaveCriticalSection(&crit);
	return;
}

void Print(vector<int>& vec, float& aver, int& sum, CRITICAL_SECTION& crit1, CRITICAL_SECTION& crit2)
{
	EnterCriticalSection(&crit1);
	EnterCriticalSection(&crit2);

	cout << "입력받은 값:";
	for (auto iter : vec)
	{
		cout << " " << iter;
	}
	cout << endl;

	cout << "평균 : " << aver << endl;
	cout << "합계 : " << sum << endl;
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