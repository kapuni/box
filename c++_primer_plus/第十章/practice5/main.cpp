#include <iostream>
#include <cctype>
#include "stack.h"
//主程序
int main()
{
    using namespace std;
    double payment;
    Stack st;
    char ch;
    Item po;
    cout << "Please enter A to add a purchase order,\n"
        << "P to process a po, or Q to quit.\n";
    while(cin >> ch && toupper(ch) != 'Q')//输入不为Q（q）时
    {
        while(cin.get() != '\n')
            continue;
        if (!isalpha(ch))
        {
            cout << '\a';
            continue;
        }
        switch(ch)
        {
            case'A':
            case'a':cout << "Enter a PO fullname: ";
                    cin.get(po.fullname, 35);
                    cout << "Enter a PO number to add: ";
                    cin >> po.payment;
                    cin.get();
                    if(st.isfull())
                        cout << "stack already full\n";
                    else
                        st.push(po);
                    break;
            case'P':
            case'p':if (st.isempty())
                        cout << "stack already empty\n";
                    else {
                        st.pop(po);
                        cout << "PO: " << po.fullname << "  ayment: " << po.payment << " popped\n";
                        payment += po.payment;
                        cout << "The total of payment: " << payment << endl;
                    }
                    break;
        }
        cout << "Please enter A to add a purchase order,\n"
             << "P to process a PO, or Q to quit.\n";
    }
    cout << "Bye\n";
    return 0;
}
