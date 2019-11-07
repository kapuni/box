//more stocks.cpp -- implementing the class member function
void Stock::acquire(const char* co,int n, double pr)
{
    std::strncpy(company, co, 29);
    company[29] = '\0';
    if (n < 0)
    {
        std:: cerr << "Number of shares can't be negative."
        << company << " shares set to 0.\n";
        shares = 0;
    }
    else
        shares =n;
    share_val = pr;
    set_tot();
}

void Stock::buy(int num, double price)
{
    if (num < 0)
    {
        std::cerr << "Number of shares purchased can't be negative,"
        << "Transaction id aborted.\n";

    }
    else
    {
        shares +=num;
        share_val = price;
        set_tot();

    }
}

void Stock::sell(int num, double price)
{
    using std::cerr;
    if (num < 0)
    {
        cerr << "Number of shares purchased can't be negative,"
        << "Transaction id aborted.\n";

    }
    else if (num > shares)
    {
        cerr << "You can't sell more than you have!"
        << "Transaction is aborted.\n";
    }
    else
    {
        shares -=num;
        share_val = price;
        set_tot();
    }

}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show()
{
    using std::cout;
    using std::endl;
    cout << "Company: " << company
    << " Shares: " << shares << endl
    << " Share Price: $" << share_val
    << " Total Worth :$" << total_val<< endl;
}
