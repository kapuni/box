#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>

//����˿���
class Customer
{
private:
    long arrive;
    int processtime;
public:
    Customer() { arrive = processtime = 0; }

    void set(long when)
    {
        processtime = std::rand() % 3 + 1;
        arrive = when;
    }
    long when() const { return arrive; }
    int ptime() const { return processtime; }
};
typedef Customer Item;

//�����¹˿��������
const int MIN_PER_HR = 60;
bool newcustomer(double x);

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    std::srand(std::time(0));//�����ʼ��

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maxmium size of queue: ";//�����Ŷ�����
    int qs;
    cin >> qs;
    std::queue <Item>line;//����qs���˵Ķ���

    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;
    long cyclelimit = MIN_PER_HR * hours;

    cout << "Enter the average number of customers per hours: ";
    double perhour;
    cin >> perhour;
    double min_per_cust;
    min_per_cust = MIN_PER_HR / perhour;//��¼�ܵķ�����

//���ò���
    Item temp;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time = 0;
    long line_wait = 0;

    for (int cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))
        {
            if (line.size()==qs)  //qs ����
                turnaways++;
            else
            {
                customers++;
                temp.set(cycle);
                line.push(temp);
            }
        }
        if (wait_time <= 0 && !line.empty())
        {
            line.pop();//����������Ҫitem����
            wait_time = temp.ptime();
            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time > 0)
            wait_time--;
        sum_line += line.size();
    }

//������
    if (customers > 0)
    {
        cout << "customers accepted: " << customers << endl;
        cout << "  customers served: " << served << endl;
        cout << "         turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line / cyclelimit << endl;
        cout << " average wait time: "
            << (double) line_wait / served << " minutes\n";
    }
    else
        cout << "No customers!\n";
    cout << "Done!\n";

    return 0;
}

bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}
