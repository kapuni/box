//practice6.cpp -- creating a cat struct ,store year and maker .using new
#include<iostream>
int main()
{
    using namespace std;
    int i,j;
    cout << "How many car do you wish to catalog?\n";
    int num;
    cin >> num;
    struct Car
    {
        char maker[20];
        int year;
    };
    Car cars[num];
    //Car * ps =new car [num]
    for (i=1;i<= num;i++)
    {
        cout << "Car#" << i << ":\n";
        cout << "Please enter the make:";
        cin >> cars[i].maker;
        cout << "Please enter the year made:";
        cin >> cars[i].year;

    }
    cout << "Here is your collection:\n";
    for (j=1;j<=i;j++)
    {
        cout << cars[j].year << " " <<cars[j].maker<<endl;

    }
    return 0;
}
