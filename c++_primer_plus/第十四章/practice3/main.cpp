#include <iostream>
#include <cstring>
#include "workermi.h"
#include "queuetp.h"

const int SIZE = 5;

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    using std::strchr;
    QueueTp<Worker *> lolas(SIZE);
    int ct;
    for (ct= 0;ct < SIZE; ct++)
    {
        char choice;
         cout << "Enter the employee category: \n"
            << "w: waiter             s:singer\n "
            << "t: singing waiter     q:quit\n";
        cin >> choice;
        while(strchr("wstq", choice) == NULL)
        {
            cout << "Please enter a w, s, t, or q: ";
            cin >> choice;
        }
        if(choice == 'q')
            break;
        switch(choice)
        {
            case 'w':
                lolas.Push(new Waiter) ;
                break;
            case 's' :
                lolas.Push(new Singer) ;
                break;
            case 't' :
                lolas.Push(new SingingWaiter);
                break;
        }
        cin.get();
        lolas.rear() ->Set();
    }

    cout << "\nHere is your staff:\n";
    int i;
    for (i= 0; i< ct; i++)
    {
        cout << endl;
        lolas.front() ->Show();
        lolas.Push(lolas.front());
        lolas.Pop();
    }
    for (i = 0;i<ct; ++i)
    {
        delete lolas.front();
        lolas.Pop();
    }

    cout << "Bye.\n";

    return 0;
}
