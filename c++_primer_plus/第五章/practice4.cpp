//practice5.cpp -- 输入每月销售额， 输出年销售额
#include <iostream>
#include<string>
int main()
{
    using namespace std;
    int i,sum;
    sum = 0;
    int sales[12];
    const string months[]={ "一月", "二月", "三月" ,"四月", "五月", "六月", "七月", "八月", "九月", "十月", "十一月", "十二月"};

    cout << "输入每月的销售额： " << "\n";
    for (i = 0; i<12;i++)
    {
        cout << months[i] << ":";
        cin >> sales[i];
        sum += sales[i];
    }
    cout << "The total year saling is" << sum << endl;
    return 0;
}
