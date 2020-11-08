#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

// 10개밖에 for문이 돌아가지 않아서 쓰레드가 왔다갔다하면서 실행하는것처럼 보이지 않는데
// 갯수를 10개가아닌 10개정도만 늘리면 왔다갔다 하면서 실행됩니다.

void input(vector<int>& vec,mutex& m1, mutex& m2)
{
	m1.lock();
	m2.lock();

	int a;

	cout << " input thread 실행" << endl;
	for (int i = 0; i < 10; i++)
	{
		cin >> a;
		vec.push_back(a);
	}

	m1.unlock();
	m2.unlock();

	cout << " input thread 종료" << endl;
	return;
}

void GetAverage(vector<int>& vec,float& aver ,mutex& m)
{
	m.lock();

	cout << " aver thread 실행" << endl;

	for (auto iter : vec)
	{
		cout << " aver thread 실행 중"<< endl;
		aver += iter;
	}

	aver /= vec.size();

	cout << " aver thread 종료" << endl;
	m.unlock();
	return;
}

void GetSum(vector<int>& vec,int& sum, mutex& m)
{
	m.lock();

	cout << " sum thread 실행" << endl;

	for (auto iter : vec)
	{
		cout << " sum thread 실행 중" << endl;
		sum += iter;
	}
	cout << " sum thread 종료" << endl;
	m.unlock();
	return;
}

void Print(vector<int>& vec, float& aver, int& sum, mutex& m1, mutex& m2)
{
	m1.lock();
	m2.lock();

	cout << "입력받은 값:";
	for (auto iter : vec)
	{
		cout << " " << iter;
	}
	cout << endl;

	cout << "평균 : " << aver << endl;
	cout << "합계 : " << sum << endl;
	m1.unlock();
	m2.unlock();

	return;
}

int main()
{
	vector<int> v;
	float aver=0;
	int sum=0;

	mutex sumMtx;
	mutex averMtx;
	thread inputFunc(input,ref(v),ref(sumMtx),ref(averMtx));
	thread averFunc(GetAverage, ref(v), ref(aver), ref(averMtx));
	thread sumFunc(GetSum, ref(v), ref(sum), ref(sumMtx));
	thread printFunc(Print, ref(v), ref(aver), ref(sum), ref(sumMtx), ref(averMtx));

	inputFunc.join();
	averFunc.join();
	sumFunc.join();
	printFunc.join();

	return 0;
}