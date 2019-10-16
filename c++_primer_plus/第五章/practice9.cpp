//practice.cpp -- 输入行数，显示”*“和”。“
#include<iostream>

int main()
{
    using namespace std;
    int i,j,z;
    cout << "Enter number of rows:\n";
    int rows;
    cin >> rows;
    for (j=rows;j > 0;j--)
    {
        for (i=0;i<j-1;i++)
            cout << ".";
        for (;i<rows;i++)
            cout << "*";
        cout<<endl;
    }
    return 0;
}
