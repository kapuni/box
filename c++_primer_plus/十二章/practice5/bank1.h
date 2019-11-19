
//头文件
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
    Node * front;        //指针指向队列头
    Node * rear;         //指针指向队列尾
    int items;           //队列 目前成员个数
    const int qsize;      //队列最大个数
    //preemptive definitions to prevent public copying
    Queue (const Queue & q):qsize(0){}
    Queue &  operator= (const Queue & q) {return *this;}
public:
    Queue(int qs = Q_size);
    ~Queue();
    bool isempty()const;
    bool isfull()const;
    int queuecount()const;
    bool enqueue(const Item &iten);       //增加到末端
    bool dequeue(Item &item);              //去除前端
};

#endif // BANK1_H_INCLUDED
