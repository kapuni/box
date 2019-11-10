#include <iostream>
#include "list.h"

bool List::isfull() const
{
    return top == MAX;
}

bool List::isempty() const
{
    return top == 0;
}

bool List::add(const Item item)
{
    if (top < MAX)
    {
        items[top++] = item;
        return true;
    }
    else
        return false;
}

void List::visit(void(*pf)(Item & item))
{
    std::cout << "\nDisplay the item: \n";
    for (int i = 0; i < top; ++i)
        (*pf)(items[i]);
}
