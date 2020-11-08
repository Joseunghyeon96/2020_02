#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

// 10���ۿ� for���� ���ư��� �ʾƼ� �����尡 �Դٰ����ϸ鼭 �����ϴ°�ó�� ������ �ʴµ�
// ������ 10�����ƴ� 10�������� �ø��� �Դٰ��� �ϸ鼭 ����˴ϴ�.

void input(vector<int>& vec,mutex& m1, mutex& m2)
{
	m1.lock();
	m2.lock();

	int a;

	cout << " input thread ����" << endl;
	for (int i = 0; i < 10; i++)
	{
		cin >> a;
		vec.push_back(a);
	}

	m1.unlock();
	m2.unlock();

	cout << " input thread ����" << endl;
	return;
}

void GetAverage(vector<int>& vec,float& aver ,mutex& m)
{
	m.lock();

	cout << " aver thread ����" << endl;

	for (auto iter : vec)
	{
		cout << " aver thread ���� ��"<< endl;
		aver += iter;
	}

	aver /= vec.size();

	cout << " aver thread ����" << endl;
	m.unlock();
	return;
}

void GetSum(vector<int>& vec,int& sum, mutex& m)
{
	m.lock();

	cout << " sum thread ����" << endl;

	for (auto iter : vec)
	{
		cout << " sum thread ���� ��" << endl;
		sum += iter;
	}
	cout << " sum thread ����" << endl;
	m.unlock();
	return;
}

void Print(vector<int>& vec, float& aver, int& sum, mutex& m1, mutex& m2)
{
	m1.lock();
	m2.lock();

	cout << "�Է¹��� ��:";
	for (auto iter : vec)
	{
		cout << " " << iter;
	}
	cout << endl;

	cout << "��� : " << aver << endl;
	cout << "�հ� : " << sum << endl;
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