//acctabc.h -- bank account classes
#ifndef ACCTABC_H_INCLUDED
#define ACCTABC_H_INCLUDED

//Abstract Base Class
class AcctABC
{
private:
    enum {MAX = 35};
    char fullName[MAX];
    long acctNum;
    double balance;
protected:
    const char *  FullName()const {return fullName;}
    long AcctNum()const {return acctNum;}
    std::ios_base::fmtflags SetFormat()const;   //定义std::ios_base::fmtflags  格式
public:
    AcctABC(const char * s= "Nullbody", long an = -1, double bal=0.0);
    void Deposit(double amt);
    virtual void Withdraw (double amt) =0;   //纯虚函数
    double Balance()const {return balance;};
    virtual void ViewAcct()const = 0;        //纯虚函数
    virtual ~AcctABC(){}
};

//Brass Account Class
class Brass:public AcctABC
{
public:
    Brass(const char *s="Nullbody", long an = -1, double bal = 0.0):AcctABC(s, an,bal){};
    virtual void Withdraw(double amt);
    virtual void ViewAcct()const;
    virtual ~Brass(){}
};

//BrassPlus Account class
class BrassPlus :public AcctABC
{
private:
    double maxLoan;
    double rate;
    double owesBank;
public:
    BrassPlus (const char *s="Nullbody", long an = -1,
               double bal = 0.0, double ml =500, double r =0.10);
    BrassPlus (const Brass &ba, double ml = 500, double r = 0.1);
    virtual void ViewAcct()const;
    virtual void Withdraw(double atm);
    void ResetMax (double m) {maxLoan = m;}
    void ResetRate (double r) {rate = r; };
    void ResetOwes () {owesBank = 0;}
};


#endif // ACCTABC_H_INCLUDED
