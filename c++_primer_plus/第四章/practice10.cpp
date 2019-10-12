//practice6.cpp --
#include<iostream>
struct CandyBar
{
    char band[20];
    double weight;
    int calorie;
};
int main()
{
    using namespace std;
    CandyBar snack =
    {
        "Mocha Munch",
        2.3,
        350
    };
    double * p = new double [2];
    p[0] = snack.weight;
    p[1] = snack.calorie;
    cout << "Band: " << snack.band <<endl;
    cout << "Weight: " << p[0] << endl;
    cout << "Calorie: " << p[1] << endl;
    return 0;
}
