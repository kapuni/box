//morechar.cpp -- the char type and int type contrasted
#include<iostream>
using namespace std;
int main()
{
    char ch = 'M';
    int i = ch ;
    cout << " The ASCII code for " << ch << " is " << i << endl;
    cout << "Add one to the character code:" << endl;
    ch = ch + 1 ;
    i = ch;
    cout << "The ASCII code for " << ch << " is " << i << endl;
    cout << "Displaying char ch using cout.put(ch): ";  // ʹ�� cout.put() ��ʾ�ַ�
    cout.put(ch);

    cout.put('!');

    cout << endl << "Done" << endl;
    return 0;
}
