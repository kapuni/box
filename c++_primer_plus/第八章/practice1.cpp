//practice1.cpp -- ����һ��������ӡ���ַ�������
#include<iostream>
#include<stdlib.h>

using namespace std;
void showstr(char * str, int n = 0);

int main()
{
    char *p = "I'm a boy!";
    showstr(p);
    cout << endl;
    for (int i = 0; i< 3;i++)
    {
        cout << i+1 << ":\n";
        showstr(p, i);
        cout << endl;
    }
    system("pause");
    return 0;
}

void showstr( char *str, int n)
{
    int limit = 0;
    if(n == 0)
    {
        limit = 1;

    }
    static int use = 0;
    limit = ++use;
    for (int i = 0;i<limit;i++)
    {
        cout << str << endl;
    }
}
