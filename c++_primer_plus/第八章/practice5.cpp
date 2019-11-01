//practice5.cpp -- ±àÐ´Ä£°åº¯Êýmax5£¨£©
#include<iostream>
#include<stdlib.h>

using namespace std;
template <class T>
T max5 (T a[]);

int main()
{
    int a[5] = {1,2,3,4,5};
    double b[5] = {1.0,2.0,3.0,4.0,5.0};
    int i=max5(a);
    double j=max5(b);
    cout << i << endl;
    cout << j << endl;
    system("pause");
    return 0;
}

template<class T>
T max5(T a[])
{
    T max = a[0];
    for (int i = 0;i<5; i++)
    {
        if(a[i] > max)
            max = a[i];
    }
    return max;
}
