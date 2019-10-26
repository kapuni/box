//practice6.cpp -- 输入数组，显示数组，反转数组
#include <iostream>

using namespace std;
//函数声明
int Fill_array(double * p_arr, int n);
void Show_array(double * p_arr, int n);
void Reverse_array(double * p_arr, int bagin, int end, int n);

int main()
{
	int n, size;

	cout << "Please enter the length of array: " << endl;

	cin >> size;

	double * p_arr = new double[size];
	//未修改前的代码double arr[size];

	n = Fill_array(p_arr, size);

	Show_array(p_arr, n);

    Reverse_array(p_arr, 0, n-1, n);

	Show_array(p_arr, n);

    Reverse_array(p_arr, 1, n-2, n);//除首尾元素外进行交换

	Show_array(p_arr, n);

	cout << "Over.\n";

	return 0;
}

//填充函数
int Fill_array(double * p_arr, int size)
{
	int count = 0;
	cout << "Please enter the array: " << endl;
	for(int i = 0; i<size && cin >> p_arr[i]; i++)//注意输入条件
	{
		count++;
	}

	return count;
}

//显示函数
void Show_array(double * p_arr, int n)
{
	cout << "Now, the array is: " << endl;
	for(int i = 0; i < n; i++)
	{
		cout << p_arr[i] << " ";
	}
	cout << endl;
}

//反转函数
void Reverse_array(double * p_arr, int begin, int end, int n)//注意参数起止
{
	double t;//原来这里是int类型，经提醒后修改
	for(int i = begin; i < n/2; i++)
	{
		t = p_arr[i];
		p_arr[i] = p_arr[begin + end - i];//注意参数起止对交换的影响
		p_arr[begin + end - i] = t;
	}
}
