//practice2.cpp -- input numbers step by step ,output their sum, when input "0" ,over
#include <iostream>
using namespace std;
int main()
{
    int i;
    int sum = 0;
    while(i != 0)
    {
        cout << "Enter your number: " << endl;
        cin >> i;
        sum +=i;
        cout << "Sum :" << sum << endl;
    }
    return 0;
}
