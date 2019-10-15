//practice5.cpp -- 输入每月销售额， 输出年销售额
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
    const string months[]={ "一月", "二月", "三月" ,"四月", "五月", "六月", "七月", "八月", "九月", "十月", "十一月", "十二月"};

    cout << "输入每月的销售额： " << "\n";
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
//方法二
int main()
{
    using namespace std;
    int i,j,all=0;
    int sum[3] = {0,0,0};

    int sales[3][12];
    const string year[]={"第一年","第二年","第三年"};
    const string months[]={ "一月", "二月", "三月" ,"四月", "五月", "六月", "七月", "八月", "九月", "十月", "十一月", "十二月"};

    cout << "输入每月的销售额： " << "\n";
    for (j=0;j<3;j++)
    {
         for (i = 0; i<12;i++)
    {
        cout << year[j] <<months[i]<< "销售量:";
        cin >> sales[j][i];

        sum[j]+= sales[j][i];


    }
    all +=sum[j];

    cout << "The one year total  saling is" << sum[j] << endl;
    }

    cout << "The three year total money is" << all << endl;

    return 0;
}
