//practice6.cpp -- �������飬��ʾ���飬��ת����
#include <iostream>

using namespace std;
//��������
int Fill_array(double * p_arr, int n);
void Show_array(double * p_arr, int n);
void Reverse_array(double * p_arr, int bagin, int end, int n);

int main()
{
	int n, size;

	cout << "Please enter the length of array: " << endl;

	cin >> size;

	double * p_arr = new double[size];
	//δ�޸�ǰ�Ĵ���double arr[size];

	n = Fill_array(p_arr, size);

	Show_array(p_arr, n);

    Reverse_array(p_arr, 0, n-1, n);

	Show_array(p_arr, n);

    Reverse_array(p_arr, 1, n-2, n);//����βԪ������н���

	Show_array(p_arr, n);

	cout << "Over.\n";

	return 0;
}

//��亯��
int Fill_array(double * p_arr, int size)
{
	int count = 0;
	cout << "Please enter the array: " << endl;
	for(int i = 0; i<size && cin >> p_arr[i]; i++)//ע����������
	{
		count++;
	}

	return count;
}

//��ʾ����
void Show_array(double * p_arr, int n)
{
	cout << "Now, the array is: " << endl;
	for(int i = 0; i < n; i++)
	{
		cout << p_arr[i] << " ";
	}
	cout << endl;
}

//��ת����
void Reverse_array(double * p_arr, int begin, int end, int n)//ע�������ֹ
{
	double t;//ԭ��������int���ͣ������Ѻ��޸�
	for(int i = begin; i < n/2; i++)
	{
		t = p_arr[i];
		p_arr[i] = p_arr[begin + end - i];//ע�������ֹ�Խ�����Ӱ��
		p_arr[begin + end - i] = t;
	}
}
