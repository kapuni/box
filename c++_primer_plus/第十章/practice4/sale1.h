#ifndef SALE1_H_INCLUDED
#define SALE1_H_INCLUDED

namespace SALE
{
    class Sales
    {
    private:
        static const int QUARTERS = 4;
        double sales[QUARTERS];
        double average;
        double max;
        double min;
    public:
        Sales();
        Sales(const double *ar, const int n);
        void setsales();
        void showSales() const;
    };
}

#endif // SALE1_H_INCLUDED
