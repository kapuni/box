//practice5.cpp -- ����ÿ�����۶ ��������۶�
#include <iostream>
#include<string>
/*
int main()
{
    using namespace std;
    int i,sum,j,Add;
    sum = 0;
    int year[3];
    int sales[12];
    int Sale[12][3];
    const string months[]={ "һ��", "����", "����" ,"����", "����", "����", "����", "����", "����", "ʮ��", "ʮһ��", "ʮ����"};

    cout << "����ÿ�µ����۶ " << "\n";
    for (j=0;j<3;j++)
    {
         for (i = 0; i<12;i++)
    {
        cout << months[i] << ":";
        cin >> sales[i];

        sum += sales[i];
        Sale[i][j]=sales[i];

    }
    year[j] = sum;
    sum = 0;

    cout << "The one year total  saling is" << year[j] << endl;
    }
    Add = year[0] + year[1]+ year[3];
    cout << "The three year total money is" << Add << endl;

    return 0;
}
*/
//������
int main()
{
    using namespace std;
    int i,j,all=0;
    int sum[3] = {0,0,0};

    int sales[3][12];
    const string year[]={"��һ��","�ڶ���","������"};
    const string months[]={ "һ��", "����", "����" ,"����", "����", "����", "����", "����", "����", "ʮ��", "ʮһ��", "ʮ����"};

    cout << "����ÿ�µ����۶ " << "\n";
    for (j=0;j<3;j++)
    {
         for (i = 0; i<12;i++)
    {
        cout << year[j] <<months[i]<< "������:";
        cin >> sales[j][i];

        sum[j]+= sales[j][i];


    }
    all +=sum[j];

    cout << "The one year total  saling is" << sum[j] << endl;
    }

    cout << "The three year total money is" << all << endl;

    return 0;
}
