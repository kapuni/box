//practice5.cpp -- µÝ¹éº¯Êý
#include<iostream>

using namespace std;
long int factorial(int n);

int main()
{
    int x;
    long int ans;
    cout << "Please enter the number : (q to quit)" << endl;

    while(cin >> x)
    {

        cout << "The factorial is :" << factorial(x) << endl;
    }
    cout << "Over." << endl;

    return 0;
}

long int  factorial(int n)
{
    long int ans;
    if (n> 0)
        ans = n * factorial(n-1);
    if(n==0)
        ans = 1;
    return ans;
}
