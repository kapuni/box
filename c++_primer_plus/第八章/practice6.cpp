//practica6.cpp -- write function maxn() that includes specialization

#include<iostream>
#include<stdlib.h>
#include<string>
#include<cstring>
using namespace std;
template<typename T>
T maxn(T a[], int num);

template<>char *maxn(char* a[], int num);

int main()
{
    int a[] = {1,2,3,4,5};
    double b[] = {1.0, 2.0, 3.0, 4.0,5.0};
    char *str[3] = {"I am kpp", "I love you ", "who are you"};
    int a1 = sizeof(a)/sizeof(int) + 1;
    int b1 = sizeof(b)/sizeof(double)+1;
    int i = maxn(a,a1);
    double j = maxn(b,b1);
    char *add = maxn(str, 3);
    cout << i << endl;
    cout << j << endl;
    cout << (int)add << endl;
    system("pause");
    return 0;
}
template<typename T>
T maxn(T a[], int num)
{
    T max = a[0];
    for (int i=0; i< num; i++)
    {
        if(a[i] > max)
            max = a[i];

    }
    return max;
}

template<>char* maxn(char* a[], int num)
{
    int max = strlen(a[0]);
    int count ;
    for (int i =0; i< num; i++)
    {
        if(strlen(a[i]) > max)
        {
            max = strlen(a[i]);
            count = i;
        }
    }
    return a[count];
}
