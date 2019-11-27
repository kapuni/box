#ifndef WINE_H_INCLUDED
#define WINE_H_INCLUDED

#include<iostream>
#include<string>
#include <valarray>

typedef std::valarray<int> ArrayInt;
typedef std::pair<ArrayInt, ArrayInt> PairArray;

class Wine
{
private:
    std::string label;
    PairArray number;
    int yearnumber;
public:
    Wine(const char * l, int y, const int yr[], const int bot[]);
    Wine (const char * l, int y);

    void GetBottle();
    void Show();
    const std::string & Label();
    int sum();
};

#endif // WINE_H_INCLUDED
