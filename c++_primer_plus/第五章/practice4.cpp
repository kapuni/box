//practice5.cpp -- ����ÿ�����۶ ��������۶�
#include <iostream>
#include<string>
int main()
{
    using namespace std;
    int i,sum;
    sum = 0;
    int sales[12];
    const string months[]={ "һ��", "����", "����" ,"����", "����", "����", "����", "����", "����", "ʮ��", "ʮһ��", "ʮ����"};

    cout << "����ÿ�µ����۶ " << "\n";
    for (i = 0; i<12;i++)
    {
        cout << months[i] << ":";
        cin >> sales[i];
        sum += sales[i];
    }
    cout << "The total year saling is" << sum << endl;
    return 0;
}
