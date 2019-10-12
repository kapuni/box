//practice8.cpp -- pizza name diameter, weight    using new with a structure
#include<iostream>
struct pizza
{
    char name[20];
    int diameter;
    int weight;
};
int main()
{
    using namespace std;
    pizza * pie = new pizza;
    cout << "What is your name of company? \n";
    cin.getline(pie->name,20);
    cout << "What is the diameter of the pizza in inches?\n";
    cin >> (*pie).diameter;
    cout << "How much does the pizza ?\n";
    cin >> pie->weight;
    cout << "Company : " << (*pie).name << endl;
    cout << "Diameter: " << pie->diameter << endl;
    cout << "Weight: " << pie->weight << endl;
    delete pie;
    return 0;
}
