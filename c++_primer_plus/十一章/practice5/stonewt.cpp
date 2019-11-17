//stonewt.cpp -- Stonewt methods
#include <iostream>
using std::cout;
#include "stonewt.h"

//construct Stonewt object from stone , double value
Stonewt::Stonewt(double lbs)
{
    stone = int (lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn + lbs - int (lbs);
    pounds = lbs;
}

//construct Stonewt object from stone , double values
Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn* Lbs_per_stn + lbs;
}

Stonewt::Stonewt()
{
    stone = pounds = pds_left = 0;
    state = 3;
}

Stonewt::~Stonewt()
{

}

void Stonewt::setstate(int x)
{
    state = x;
}

Stonewt operator+(const Stonewt & s1, const Stonewt & s2)
{
    Stonewt sum;
    sum.pounds = s1.pounds + s2.pounds;
    sum.stone = int(sum.pounds) / 14;
    sum.pds_left = int(sum.pounds) % 14 + sum.pounds - int(sum.pounds);
    return sum;
}

Stonewt operator-(const Stonewt & s1, const Stonewt & s2)
{
    double pounds;
    pounds = s1.pounds - s2.pounds;
    Stonewt diff(pounds);
    return diff;

}

Stonewt operator*(const Stonewt & s, double n)
{
    double pounds;
    pounds = s.pounds * n;
    Stonewt mult(pounds);
    return mult;
}

Stonewt operator*(double m, const Stonewt & s)
{
    double pounds;
    pounds = s.pounds * m;
    Stonewt mult(pounds);
    return mult;
}


std::ostream & operator<<(std::ostream & os, const Stonewt & s)
{
    if (s.state == 1)
    {
        os << s.stone << " stone, " << s.pds_left << " pounds\n";
    }
    if (s.state == 2)
    {
        os << int(s.pounds) << " pounds\n";
    }
    if (s.state == 3)
    {
        os << s.pounds << " pounds\n";
    }
    return os;
}
