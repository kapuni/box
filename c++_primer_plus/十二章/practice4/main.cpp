//Ö÷³ÌÐò
#include <iostream>
#include "stack1.h"

int main()
{
    using namespace std;
    Stack st;
    cout << "Is st empty:";
    cout << st.isempty() << endl;
    cout << "Is st full:";
    cout << st.isfull() << endl;

    Item it[10];
    cout << "Push to st:";
    for(int i=0;i<10;i++)
    {
        it[i]=i+1;
        st.push(it[i]);
        cout << it[i] << " ";
    }
    cout << "\nIs st full:";
    cout << st.isfull() << endl;

    Stack po;
    cout << "\nAt first\nIs po empty:";
    cout << po.isempty() << endl;
    po = st;
    cout << "\nAfter po = st\nIs po empty:";
    cout << po.isempty();
    cout << "\nIs po full:";
    cout << po.isfull() << endl;

    cout << "\nPop to st:";
    for(int i=0;i<10;i++)
    {
        st.pop(it[i]);
        cout << it[i] << " ";
    }
    cout << "\nIs st empty:";
    cout << st.isempty() << endl;
    return 0;
}

