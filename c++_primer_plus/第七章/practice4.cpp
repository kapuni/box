//practice4.cpp -- modify 7.4
#include<iostream>

long double probability(unsigned numbers, unsigned piceks, int special);
int main()
{
    using namespace std;
    double total,choices, s;
    cout << "Enter the total number of choices on the game card and \n"
    "the number  of picks allowed:\n";
    while ((cin >> total >> choices >> s) && choices <=total)
    {
        cout << "You have one chance in ";
        cout << probability(total, choices, s);
        cout << " of winning .\n";
        cout << "Next two numbers(q to quit) :";

    }
    cout << "bye .\n";
    return 0;
}

long double probability(unsigned numbers, unsigned picks,int s)
{
    long double result = 1.0;
    long double n;
    unsigned p;

    for (n=numbers, p=picks; p> 0;n--,p--)
        result = result *n/p;
    result = result * s;
    return result;
}
