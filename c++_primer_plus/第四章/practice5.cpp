//practice5.cpp -- stating struct CandyBar that includes three members
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
    cout << "Band: " << snack.band <<endl;
    cout << "Weight: " << snack.weight << endl;
    cout << "Calorie: " << snack.calorie << endl;
    return 0;
}
