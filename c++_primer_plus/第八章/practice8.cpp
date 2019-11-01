//practice8.cpp --  modify 8.14
#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;

template<class T> double SumArray(T arr[], int n)
{
	cout << "template A\n";
	double	sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	return (sum);
}

template<class T> double SumArray(T * arr[], int n)
{
	cout << "template B\n";
	double	sum = 0;
	for (int i = 0; i < n; i++)
		sum += *arr[i];
	return (sum);
}


struct debts
{
	char name[50];
	double amount;
};
int main()
{
	int things[6] = { 13, 31, 103, 301, 2, 4 };
	struct debts mr[3] =
	{
		{"I love you", 2400.0 },
		{"I hate you",1200.0},
		{"I fuck you",1100.0 },
	};
	double * pd[3];
	for (int i = 0; i < 3; i++)
		pd[i] = &mr[i].amount;
	cout << "the total number of Mr. E's things: " << SumArray(things, 6) << endl;
	cout << "the sum of Mr. E's all debts: " << SumArray(pd, 3) << endl;
	system("pause");
	return 0;
}
