#ifndef STOCK3_H_INCLUDED
#define STOCK3_H_INCLUDED

#include <string>

class Stock
{
private:
    char * company;
    int shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }
public:
    Stock();
    Stock(const char * c0, long n = 0, double pr = 0.0);
    ~Stock();//Îö¹¹º¯Êý
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    const Stock & topval(const Stock & s) const;

    friend std::ostream & operator<<(std::ostream & os, const Stock & st);
};


#endif // STOCK3_H_INCLUDED
