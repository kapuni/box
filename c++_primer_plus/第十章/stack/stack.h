//10.10stack.cpp -- class definition for the stack ADT
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef unsigned long Item;
class Stack
{
private:
    enum{MAX = 10};
    Item items[MAX];
    int top;
public:
    Stack();
    bool isempty()const;
    bool isfull()const;
    //push()return false if stack already is full ,true otherwise
    bool push(const Item & item);
    //pop()return false if stack already is empty ,true otherwise
    bool pop(Item & item);
};

#endif // STACK_H_INCLUDED
