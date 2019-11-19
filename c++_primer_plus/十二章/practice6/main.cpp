#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue2.h"

const int MIN_PER_HR  = 60;

//新顾客随机
bool newcustomer(double x);

int main()
{
    using namespace std;
    std::srand(std::time(0));  //随机初始化

    cout << "Case Study:Bank of Heather Automatic Teller\n";
    cout <<  " Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line1(qs);  //有qs 个人
    Queue line2(qs);

    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;
    long cyclelimit = MIN_PER_HR * hours;

    cout << "Enter the average number of customers per hours: ";
    double perhour;
    cin >> perhour;
    double min_per_cust;
    min_per_cust = MIN_PER_HR / perhour;

//设置参数
    Item temp;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait1_time = 0;
    int wait2_time = 0;
    long line1_wait = 0;
    long line2_wait = 0;

    for (int cycle = 0;cycle < cyclelimit; cycle++)
    {
        if(newcustomer(min_per_cust))
        {
            if (line1.isfull() && line2.isfull())
                turnaways++;
            else if (line2 > line1 || line1.isfull())
            {
                customers++;
                temp.set(cycle);
                line1.enqueue(temp);
            }
            else
            {
                customers++;
                temp.set(cycle);
                line2.enqueue(temp);
            }

        }

        if (wait2_time <=0 && !line2.isempty())
        {
            line2.dequeue(temp);
            wait2_time = temp.ptime();
            line2_wait += cycle - temp.when();
            served++;
        }
        if (wait1_time > 0)
            wait1_time--;
        sum_line += line1.queuecount();
        if (wait2_time > 0)
            wait2_time--;
        sum_line += line2.queuecount();
    }
//报告结果
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
            << (double) (line1_wait + line2_wait) / served << " minutes\n";
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


/*------------网上的第二种方法，结果接近---------------------

bool newCustomer(double x)//每隔x次，rand()/RAND_max会有一次值<1
{
    return rand()*x/RAND_MAX<1;
}
int main()
{
    using namespace std;
    srand(time(0));//初始化rand();
    cout<<"Case Study:Bank of Heather Automatic Teller"<<endl;
    cout<<"Enter maximum size of queue:";
    int qs;
    cin>>qs;
    Queue line(qs);
    Queue line2(qs);//视为同样大小的队列

    cout<<"Enter the number of simulation hours:";
    int hours;
    cin>>hours;
    long cyclelimit=MIN_PER_HR*hours;//循环的分钟数

    cout<<"Enter the average number of customers per hour:";//一个小时来的人数
    double perhour;
    cin>>perhour;
    double min_per_cust;
    min_per_cust=MIN_PER_HR/perhour;//平均多少分钟来一个人


    Item temp;
    long turnaways=0;
    long customers=0;
    //long served=0;
    long served=0;
    long sum_line=0;
    int wait_time=0;
    int wait_time2=0;//等待时间要+1个
    long line_wait=0;

    for(int cycle=0;cycle<cyclelimit;cycle++)//cycle每循环一次，代表过了一分钟
    {
        //line.s();
        if(newCustomer(min_per_cust))
        {
            if(line.isfull()&&line2.isfull())//当两个队列都满了的时候才拒绝服务
                turnaways++;//拒绝服务？？？//恩,应该就是拒绝服务的人数
            else
            {
                customers++;//队列人数//应该是顾客人数+1而不是队列人数+1
                temp.set(cycle);//cycle是到达时间
                if(line.queuecount()>=line2.queuecount())
                    line2.enqueue(temp);
                else
                    line.enqueue(temp);//这里的items++才是队列人数+1
                //cout<<"after insert "<<line;//test

            }

        }
        if(wait_time<=0&&!line.isempty())//队列1中有用户处理完了业务
        {
            line.dequeue(temp);
            //cout<<"after the delete"<<line;//test
            wait_time=temp.ptime();//wait_time是该客户处理业务所用时间
            line_wait+=cycle-temp.when();//cycle-temp.when();是该客户一共在队列中等了多久
            //一开始wait_time初始化是0，然后进入这里之后，又重新设置了使其=processtime
            //line_wait是该队列一共等了多久？？哦，应该是所有客户的等待时间
            //line_wait是客户等待总时间
            served++;//服务人数+1
        }
        if(wait_time2<=0&&!line2.isempty())//队列1中有用户处理完了业务
        {
            line2.dequeue(temp);
            wait_time2=temp.ptime();//wait_time是该客户处理业务所用时间
            line_wait+=cycle-temp.when();//cycle-temp.when();是该客户一共在队列中等了多久
            served++;//服务人数+1
        }

        if(wait_time>0)//队列1正在处理业务的处理时间-1，因为过了一分钟
            wait_time--;
        if(wait_time2>0)//队列2正在处理业务的处理时间-1，因为过了一分钟
            wait_time2--;
        //wait_time=temp.ptime()这里随机设置了wait-time
        sum_line+=line.queuecount()+line2.queuecount();//sum_line又是神马东东？？
        //sum_line是队伍总长度，每分钟计算一次队伍长度
    }

    if(customers>0)
    {
        cout<<"customers accepted:"<<customers<<endl;
        cout<<"  customers served:"<<served<<endl;
        cout<<"         turnaways:"<<turnaways<<endl;
        cout<<"average queue size:";
        cout.precision(2);
        cout.setf(ios_base::fixed,ios_base::floatfield);
        cout<<(double)sum_line/cyclelimit<<endl;
        cout<<" average wait time:"<<(double)line_wait/served<<"  minutes"<<endl;
    }//我机器上面是18人最接近1分钟，队列长度10,时间100
    else
        cout<<"No coustomer!"<<endl;
    cout<<"Done!"<<endl;
    return 0;
}
*/

