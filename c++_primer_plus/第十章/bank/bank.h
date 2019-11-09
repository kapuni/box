#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED
class BankAccount
{
private:
    std::string fullname;
    std::string account;
    double money;
public:
    BankAccount(const std::string & client, const std::string & acc, double cash = 0.0);
    void save(double cash);
    void withdraw(double cash);
    void show() const;
};


#endif // BANK_H_INCLUDED
