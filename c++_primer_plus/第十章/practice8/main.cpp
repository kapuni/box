#include <iostream>
#include <string>
#include <cctype>
#include <windows.h>
#include "list.h"

void func(Item & item);

int main()
{
    using namespace std;
    List st;
    string str;
    cout << "At first: " << endl;
    if(st.isempty() == 1)
        str = "Yes!";
    if(st.isempty() == 0)
        str = "No!";
    cout << "isEmpty? " << str << endl;
    if(st.isfull() == 1)
        str = "Yes!";
    if(st.isfull() == 0)
        str = "No!";
    cout << "isFull? " << str << endl;

    st.add(1);
    st.add(2);
    st.add(3);
    st.add(4);
    cout << "\nNow: " << endl;

    if(st.isempty() == 1)
        str = "Yes!";
    if(st.isempty() == 0)
        str = "No!";
    cout << "isEmpty? " << str << endl;
    if(st.isfull() == 1)
        str = "Yes!";
    if(st.isfull() == 0)
        str = "No!";
    cout << "isFull? " << str << endl;

    void(*pf)(Item & item);
    pf = func;//指向func函数
    st.visit(pf);
    system("pause");//显示暂停
    return 0;
}

void func(Item & item)
{
    std::cout << item << std::endl;
}
