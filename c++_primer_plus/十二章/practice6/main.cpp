#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue2.h"

const int MIN_PER_HR  = 60;

//�¹˿����
bool newcustomer(double x);

int main()
{
    using namespace std;
    std::srand(std::time(0));  //�����ʼ��

    cout << "Case Study:Bank of Heather Automatic Teller\n";
    cout <<  " Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line1(qs);  //��qs ����
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

//���ò���
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


/*------------���ϵĵڶ��ַ���������ӽ�---------------------

bool newCustomer(double x)//ÿ��x�Σ�rand()/RAND_max����һ��ֵ<1
{
    return rand()*x/RAND_MAX<1;
}
int main()
{
    using namespace std;
    srand(time(0));//��ʼ��rand();
    cout<<"Case Study:Bank of Heather Automatic Teller"<<endl;
    cout<<"Enter maximum size of queue:";
    int qs;
    cin>>qs;
    Queue line(qs);
    Queue line2(qs);//��Ϊͬ����С�Ķ���

    cout<<"Enter the number of simulation hours:";
    int hours;
    cin>>hours;
    long cyclelimit=MIN_PER_HR*hours;//ѭ���ķ�����

    cout<<"Enter the average number of customers per hour:";//һ��Сʱ��������
    double perhour;
    cin>>perhour;
    double min_per_cust;
    min_per_cust=MIN_PER_HR/perhour;//ƽ�����ٷ�����һ����


    Item temp;
    long turnaways=0;
    long customers=0;
    //long served=0;
    long served=0;
    long sum_line=0;
    int wait_time=0;
    int wait_time2=0;//�ȴ�ʱ��Ҫ+1��
    long line_wait=0;

    for(int cycle=0;cycle<cyclelimit;cycle++)//cycleÿѭ��һ�Σ��������һ����
    {
        //line.s();
        if(newCustomer(min_per_cust))
        {
            if(line.isfull()&&line2.isfull())//���������ж����˵�ʱ��žܾ�����
                turnaways++;//�ܾ����񣿣���//��,Ӧ�þ��Ǿܾ����������
            else
            {
                customers++;//��������//Ӧ���ǹ˿�����+1�����Ƕ�������+1
                temp.set(cycle);//cycle�ǵ���ʱ��
                if(line.queuecount()>=line2.queuecount())
                    line2.enqueue(temp);
                else
                    line.enqueue(temp);//�����items++���Ƕ�������+1
                //cout<<"after insert "<<line;//test

            }

        }
        if(wait_time<=0&&!line.isempty())//����1�����û���������ҵ��
        {
            line.dequeue(temp);
            //cout<<"after the delete"<<line;//test
            wait_time=temp.ptime();//wait_time�Ǹÿͻ�����ҵ������ʱ��
            line_wait+=cycle-temp.when();//cycle-temp.when();�Ǹÿͻ�һ���ڶ����е��˶��
            //һ��ʼwait_time��ʼ����0��Ȼ���������֮��������������ʹ��=processtime
            //line_wait�Ǹö���һ�����˶�ã���Ŷ��Ӧ�������пͻ��ĵȴ�ʱ��
            //line_wait�ǿͻ��ȴ���ʱ��
            served++;//��������+1
        }
        if(wait_time2<=0&&!line2.isempty())//����1�����û���������ҵ��
        {
            line2.dequeue(temp);
            wait_time2=temp.ptime();//wait_time�Ǹÿͻ�����ҵ������ʱ��
            line_wait+=cycle-temp.when();//cycle-temp.when();�Ǹÿͻ�һ���ڶ����е��˶��
            served++;//��������+1
        }

        if(wait_time>0)//����1���ڴ���ҵ��Ĵ���ʱ��-1����Ϊ����һ����
            wait_time--;
        if(wait_time2>0)//����2���ڴ���ҵ��Ĵ���ʱ��-1����Ϊ����һ����
            wait_time2--;
        //wait_time=temp.ptime()�������������wait-time
        sum_line+=line.queuecount()+line2.queuecount();//sum_line��������������
        //sum_line�Ƕ����ܳ��ȣ�ÿ���Ӽ���һ�ζ��鳤��
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
    }//�һ���������18����ӽ�1���ӣ����г���10,ʱ��100
    else
        cout<<"No coustomer!"<<endl;
    cout<<"Done!"<<endl;
    return 0;
}
*/

