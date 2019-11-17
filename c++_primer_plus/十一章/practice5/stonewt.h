//stonewt.h -- definition foe Stonewt class
#ifndef STONEWT_H_INCLUDED
#define STONEWT_H_INCLUDED

class Stonewt
{
private:
    enum {Lbs_per_stn = 14};
    //static const int Lbs_stn = 14;
    int state;
    int stone;
    double pds_left;
    double pounds;
public:
    Stonewt(double lbs );
    Stonewt(int stn, double lbs);
    Stonewt();
    ~Stonewt();
    void setstate(int x);
    friend Stonewt operator+(const Stonewt & s1, const Stonewt & s2);
    friend Stonewt operator-(const Stonewt & s1, const Stonewt & s2);
    friend Stonewt operator*(const Stonewt &s, double n);
    friend Stonewt operator*(double m, const Stonewt & s);
    friend std::ostream & operator<<(std::ostream& os, const Stonewt & s);
};

#endif // STONEWT_H_INCLUDED
