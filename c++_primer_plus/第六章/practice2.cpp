//practice2.cpp -- input 10 numbers ,calculate average and the number bigger than it
#include<iostream>
const int Max = 10;

int main()
{
    using namespace std;

    double donation[Max];
    cout << "Please enter the donation (not bigger than 10)\n";
    cout << "donation #1: ";

    int i = 0;
    while (i<Max && cin >>donation[i])
    {
        if (++i <Max)
            cout << "donation #" << i+1 << ": \n";

    }
    double total =0.0;
    double average;
    int count = 0;
    int j;
    for (j=0; j<i; j++)
        total +=donation[j];
    average = total/i;

    for (j=0; j<i; j++)
    {
        if (donation[j] > average)
            count ++ ;

    }
    if (i==0)
        cout << "No donation.\n";
    else
    {
        cout << "Total donations are " << total << endl;
        cout << "Average of " << i << "donations = " << average << endl;
        cout << count << "donations bigger than average.\n";
    }
    cout << "Done.\n";
    return 0;

}
