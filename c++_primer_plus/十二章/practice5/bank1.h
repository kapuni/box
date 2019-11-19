
//ͷ�ļ�
#ifndef BANK1_H_INCLUDED
#define BANK1_H_INCLUDED

class Customer
{
private:
    long arrive;
    int processtime;
public:
    Customer() {arrive = processtime = 0;}
    void set (long when);
    long when()const {return arrive;}
    int ptime()const {return processtime;}
};
typedef Customer Item;

class Queue
{
private:
    //class scope definitions
    //Node is a nested structure definition local to this class
    struct Node {Item item; struct Node * next;};
    enum {Q_size = 10};
    //private class members
    Node * front;        //ָ��ָ�����ͷ
    Node * rear;         //ָ��ָ�����β
    int items;           //���� Ŀǰ��Ա����
    const int qsize;      //����������
    //preemptive definitions to prevent public copying
    Queue (const Queue & q):qsize(0){}
    Queue &  operator= (const Queue & q) {return *this;}
public:
    Queue(int qs = Q_size);
    ~Queue();
    bool isempty()const;
    bool isfull()const;
    int queuecount()const;
    bool enqueue(const Item &iten);       //���ӵ�ĩ��
    bool dequeue(Item &item);              //ȥ��ǰ��
};

#endif // BANK1_H_INCLUDED
