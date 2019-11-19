//类实现文件
#include <cstdlib>
#include "queue2.h"

Queue::Queue(int qs) : qsize(qs)
{
    front = rear = NULL;
    items = 0;
}

Queue::~Queue()
{
    Node * temp;
    while (front != NULL)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}

bool Queue::isempty() const
{
    return items == 0;
}

bool Queue::isfull() const
{
    return items == qsize;
}

int Queue::queuecount() const
{
    return items;
}

//加入队伍，同书12-11
bool Queue::enqueue(const Item & item)
{
    if (isfull())
        return false;
    Node * add = new Node;
    add->item = item;
    add->next = NULL;
    items++;
    if (front == NULL)
        front = add;
    else
        rear->next = add;
    rear = add;
    return true;
}

//离开队伍
bool Queue::dequeue(Item & item)
{
    if (front == NULL)
        return false;
    item = front ->item;
    items--;
    Node * temp = front;
    front = front->next;
    delete temp;
    if (temp == 0)
        rear = NULL;
    return true;
}

void Customer::set(long when)
{
    processtime = std::rand() % 3 + 1;
    arrive = when;
}
//比较人数
bool operator>(const Queue & item1, const Queue & item2)
{
    return item1.items > item2.items;
}
