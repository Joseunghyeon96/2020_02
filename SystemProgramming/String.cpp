#include <iostream>
#include <string>

using namespace std;

string combineString(string src1, string src2)
{
	return src1 + src2;
}

class Car {
	string company;
	string model;
	int productionYear;
	int price;

public:
	Car() 
	{
		company = " ";
		model = " ";
		productionYear = 0;
		price = 0;
	}
	~Car() {}

	void writeModel(string input) {
		model = input;
	}
	void writeCompany(string input)
	{
		company = input;
	}
	void writeYear(int input)
	{
		productionYear = input;
	}
	void writePrice(int input)
	{
		price = input;
	}
	void printModel()
	{
		cout << model << endl;
	}
	void printCompany()
	{
		cout << company << endl;
	}

	void printInfo()    // �ǽ� 3������
	{
		string temp = company + " " + model;
		cout <<"ȸ��, �𵨸�: "<< temp << endl;
		cout << "���� : " << price << "  ���۳⵵ : " << productionYear << endl;
	}

};
int main()
{
	string src1, src2,src3;
	src1 = "This is ";
	src2 = "a C++ classroom";
	src3 = combineString(src1, src2);
	cout << src3 << endl;

	Car sonata;
	sonata.writeCompany("HyunDai");
	sonata.writeModel("Sonata");
	sonata.writePrice(100000);
	sonata.writeYear(2020);

	sonata.printInfo();

	
	return 0;
}