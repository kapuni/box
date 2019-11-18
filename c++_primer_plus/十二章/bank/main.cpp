//bank.cpp -- using thw Queue interface
//compile with queue.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"
const int MIN_PER_HR = 60;

bool newcustomer(double x);

int main()
{
    using namespace std;
    //setting things up;
    std::srand(std::time(0));

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line(qs);

    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;
    //simulation will run 1 cycle per minutes
    long cyclelimit = MIN_PER_HR * hours; //# of cycles

    cout << "Enter the average number of customers per hours: ";
    double perhours;
    cin >> perhours;
    double min_per_cust;
    min_per_cust = MIN_PER_HR / perhours;

    Item temp;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time = 0;
    long line_wait = 0;

    //running the simulation
    for (int cycle = 0;cycle <cyclelimit;cycle++)
    {
        if (newcustomer(min_per_cust))
        {
            if(line.isfull())
                turnaways++;
            else
            {
                customers++;
                temp.set(cycle);
                line.enqueue(temp);    //增加新来者
            }
        }
        if (wait_time <=0 && !line.isempty())
        {
            line.dequeue(temp);
            wait_time = temp.ptime();
            line_wait +=cycle - cycle.when();
            served++;
        }
        if (wait_time > 0)
            wait_time--;
        sum_line += line.queuecount();
    }

    //reporting results
    if (customers > 0)
    {
        cout << "customers accepted: " << customers <<endl;
        cout << "  customers served: " << served <<endl;
        cout << "         turnaways" << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed,ios_base::floatfield);
        cout.setf(ios_base::showpoint);
        cout << (double)sum_line / cyclelimit << endl;
        cout << " average wait time: "
        << (double)line_wait / served << " minutes\n";

    }
    else
        cout << "No customers!\n";
    cout << "Done!\n";
    return 0;
}
