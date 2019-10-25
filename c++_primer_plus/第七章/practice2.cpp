//practice2.cpp -- input 10 scores most ,calculate means
#include<iostream>

using namespace std;
const int Max = 10;

void show(double arr[], int n);
double sum(double arr[], int n);

int main()
{
    double arr[Max];
    double average;

    cout << "Enter your golf scores(no more than 10).\n";
    cout << "score #1: ";

//git data
    int  i =0;
    int n = 0;
    while(i<Max && cin >> arr[i])
    {
        if (++i< Max)
            cout << "score #" << i+1 << endl;
        n++;
    }
    cout << "\nThe result of golf scores: " << endl;

    show(arr, n);
    average = sum(arr, n)/n;
    cout << "\nThe average of golf scores: " << average << endl;

    return 0;

}

double sum(double arr[], int n)
{
    double total = 0;
    for (int i = 0; i < n; i++)
        total = total + arr[i];
    return total;

}

void show(double arr[], int n)
{
    int total =0 ;
    for (int i = 0; i<n; i++)
    {
        cout << "score # " << i+1 << ": ";
        cout << arr[i]<< endl;
    }
}
