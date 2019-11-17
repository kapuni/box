// stonewt.cpp -- Stonewt methods

#include <iostream>
#include "stonewt.h"

using std::cout;

Stonewt::Stonewt(double lbs)
{
    stone = int(lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
    state = 1;
}

Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
    state = 1;
}

Stonewt::Stonewt()
{
    stone = pounds = pds_left = 0;
    state = 1;
}

Stonewt::~Stonewt()
{
}

void Stonewt::setstate(int x)
{
    state = x;
}

bool operator<(const Stonewt & s1, const Stonewt & s2)
{
    if (s1.pounds < s2.pounds)
        return true;
    else
        return false;
}

bool operator>(const Stonewt & s1, const Stonewt & s2)
{
    if (s1.pounds > s2.pounds)
        return true;
    else
        return false;
}

bool operator==(const Stonewt & s1, const Stonewt & s2)
{
    if (s1.pounds == s2.pounds)
        return true;
    else
        return false;
}

bool operator<=(const Stonewt & s1, const Stonewt & s2)
{
    if (s1.pounds <= s2.pounds)
        return true;
    else
        return false;
}

bool operator>=(const Stonewt & s1, const Stonewt & s2)
{
    if (s1.pounds >= s2.pounds)
        return true;
    else
        return false;
}

bool operator!=(const Stonewt & s1, const Stonewt & s2)
{
    if (s1.pounds != s2.pounds)
        return true;
    else
        return false;
}

std::ostream & operator<<(std::ostream & os, const Stonewt & s)
{
    if (s.state == 1)
    {
        os << s.stone << " stone, " << s.pds_left << " pounds";
    }
    if (s.state == 2)
    {
        os << int(s.pounds) << " pounds";
    }
    if (s.state == 3)
    {
        os << s.pounds << " pounds";
    }
    return os;

}
