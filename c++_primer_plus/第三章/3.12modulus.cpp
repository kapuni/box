//modulus.cpp -- uses % operator tp convert 1bs to stone
#include<iostream>
using namespace std;
int main()
{
    const int Lbs_per_stn =14;
    int lbs;

    cout << "Enter your weigh in pounds: ";
    cin >> lbs;
    int stone = lbs / Lbs_per_stn;
    int pounds = lbs % Lbs_per_stn;

    cout << lbs << " pounds are " << stone;
     cout    << "stone, " << pounds << " pounds(s)./n";
    return 0;
}
