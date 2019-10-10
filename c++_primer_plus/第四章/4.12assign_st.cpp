//assign_st.cpp -- assigning atructures
#include<iostream>
struct inflatable
{
    char name[20];
    float volume;
    double price;
};

int main()
{
    using namespace std;
    inflatable bouquet =
    {
        "sunflows",
        0.20,
        12.49
    };
    inflatable choice;
    cout << "bouquet: " << bouquet.name << " for $ ";
    cout << bouquet.price << endl;
    choice = bouquet;
    cout  << " choice: " << choice.name << " for $ ";
    cout << choice.price << endl;
    return 0;
}
