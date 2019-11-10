#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef int Item;

class List
{
private:
    static const int MAX = 100;
    Item items[MAX];
    int top;
public:
    List(){ top = 0; }
    bool add(const Item item);
    bool isempty() const;
    bool isfull() const;
    void visit(void(*pf)(Item & item));
};

#endif // LIST_H_INCLUDED
