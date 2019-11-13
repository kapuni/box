//stonewt1.h -- revised definition for Stonewt class
#ifndef STONEWT1_H_INCLUDED
#define STONEWT1_H_INCLUDED

class Stonewt
{
private:
    enum {Lbs_per_stn = 14};
    //static const int Lbs_stn = 14;
    int stone;
    double pds_left;
    double pounds;
public:
    Stonewt(double lbs );
    Stonewt(int stn, double lbs);
    Stonewt();
    ~Stonewt();
    void show_lbs()const;
    void show_stn()const;
    //conversion functions
    operator int()const;
    operator double()const;
};

#endif // STONEWT1_H_INCLUDED
