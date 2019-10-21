//practice6.cpp -- 记录捐款的名字和数目
#include <iostream>

using namespace std;
const int Size = 20;
const double stand = 10000.0;
struct patron
{
    char name[Size];
    double money;
};

int main ()
{
    int count;
    cout << "Enter the number of patrons:" << endl;
    cin >> count;
    cin.get();
    patron * peoplelist = new patron[count];

    cout << "Enter the patrons: " << endl;
    for(int i = 0; i < count  ;i++)
    {
        cout << "Patrons name:" << endl;
        cin.getline(peoplelist[i].name, Size);
        cout << "donation:" << endl;
        cin >> peoplelist[i].money;
        cin.get();
    }
//输出数据
    cout << "\n--------------" << endl;
    cout << "\nGrand Patrons: " << endl;
    int n = 0;
    for(int i = 0; i < count ;i++){
        if(peoplelist[i].money > stand)
        {
            cout << "Patrons name: " << peoplelist[i].name << endl;
            cout << "donation: " << peoplelist[i].money << endl;
            n++;
        }
    }
    if(n == 0)
        cout << "none";

    int m = 0;
    cout << "\nOtherPatrons: " << endl;
    for(int i = 0; i < count ;i++){

        if(peoplelist[i].money <= stand)
        {
            cout << "Patrons name: " << peoplelist[i].name << endl;
            cout << "donation: " << peoplelist[i].money << endl;
            m++;
        }
    }
    if(m == 0)
        cout << "none";

    delete peoplelist;
    return 0;

}
