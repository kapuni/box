//queue.cpp -- Queue and Customer methods
#include <iostream>
#include <cstdlib>
#include "queue.h"

////Queue  methods
Queue::Queue(int qs): qsize(qs)
{
    front = rear = NULL;
    items = 0;
}

Queue::~Queue()
{
    Node *temp;
    while(front != NULL)
    {
        temp = front;           //保存front地址
        front = front -> next;  //指针☞下一个地址
        delete temp;
    }


}
bool Queue::isempty()const
{
    return items == 0;
}

bool Queue::isfull()const
{
    return items == qsize;
}

int Queue::queuecount()const
{
    return items;
}

//Add item to queue
bool Queue::enqueue(const Item & item)
{
    if(isfull())
        return false;
    Node* add = new Node;
    if (add == NULL)
        return false;
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

//place front item into item variable and remove from queue
bool Queue::dequeue(Item & item)
{
    if(front == NULL)
        return false;
    item = front->item;
    items--;
    Node * temp = front;
    front = front->next;
    delete temp;
    if (items == 0)
        rear = NULL;
    return true;
}

//customer method

//when is the time

void Customer::set(long when)
{
    processtime = std::rand()%3 + 1;
    arrive = when;
}
