#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int GCD(int a, int b)
{
	if (b == 0)
		return a;

	int mod = a % b;	
	return GCD(b,mod); // �ִ����� ����
}

int LCM(int a, int b)
{
	return (a*b)/GCD(a,b); // �ּҰ���� ����
}

int Combination(vector<int> arr, int m)
{
	int amount = 0;
	int size = arr.size();
	vector<int> tempArr(size, 0);

	for (int i = 0; i < m; i++)
	{
		tempArr[i] = 1;
	}
	sort(tempArr.begin(), tempArr.end());

	do
	{
		for (int i = 0; i < size; i++)
		{
			if (tempArr[i] == 1)
				cout << arr[i] << "  ";
		}
		cout << endl;
		amount++;
	} while (next_permutation(tempArr.begin(), tempArr.end()));

	return amount;
}

int Permutation(vector<int> arr, int m)
{

	int amount = 0;
	int size = arr.size();
	vector<int> tempArr(size, 0);

	for (int i = 0; i < m; i++)
	{
		tempArr[i] = 1;
	}
	sort(tempArr.begin(), tempArr.end());

	do
	{
		vector<int> perArr;
		for (int i = 0; i < size; i++)
		{
			if (tempArr[i] == 1)
				perArr.push_back(arr[i]);
		}
		sort(perArr.begin(), perArr.end()); // m �� ����
		
		do
		{
			for (auto iter : perArr)
			{
				cout << iter <<" ";
			}
			cout << endl;
			amount++;
		} while (next_permutation(perArr.begin(), perArr.end())); // ������ m ���� ���������

	} while (next_permutation(tempArr.begin(), tempArr.end()));

	return amount;

}
int main()
{
	vector<int> arr;
	for (int i = 1; i < 6; i++)
	{
		arr.push_back(i);
	}
	cout << "���� : " << Combination(arr,3) << endl;
	return 0;
}