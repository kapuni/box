//stock1.cpp -- Stock class declaration with constructors, destructor added

#ifndef STOCK_H_INCLUDED
#define STOCK_H_INCLUDED

class Stock
{
private:
    char company[30];
    int shares;
    double share_val;
    double total_val;
    void set_tot(){ total_val = shares * share_val;}
public:
    Stock();
    Stock(const char * co, int n=0, double pr = 0.0);
    ~Stock();

     void buy(int num, double price);
     void sell (int num, double price);
     void update(double price);
     void show();
};
#endif // STOCK_H_INCLUDED
