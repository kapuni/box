#include<iostream>
#include<cstring>
#include "abc2.h"

using namespace std;

//abstract base class
ABC::ABC(const char * l, int r)
{
    label = new char[strlen(l) + 1];
    strcpy(label, l);
    rating = r;
}

ABC::ABC(const ABC & rs)
{
    label = new char[strlen(rs.label) + 1];
    strcpy(label, rs.label);
    rating = rs.rating;
}

ABC & ABC::operator=(const ABC & rs)
{
    if (this == &rs)
        return *this;
    delete [] label;
    label = new char[strlen(rs.label) + 1];
    strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}

ABC::~ABC()
{
    delete [] label;
}

void ABC::View()
{
    cout << "Label: " << label << endl;
    cout << "Rating: " << rating << endl;
}

std::ostream& operator<<(std::ostream& os, const ABC& rs)
{
    os << "Label: " << rs.label << endl;
    os << "Rating: " << rs.rating << endl;
    return os;
}

//basedma class
baseDMA::baseDMA(const char * l, int r) : ABC(l, r)
{

}

baseDMA::baseDMA(const baseDMA & rs) : ABC(rs)
{
}

void baseDMA::View()
{
    ABC::View();
}

//lacksbase class
lacksDMA::lacksDMA(const char * c, const char * l, int r) : ABC(l, r)
{
    std::strcpy(color, c);
    color[COL_LEN - 1] = '\0';
}

lacksDMA::lacksDMA(const char * c, const ABC & rs) : ABC(rs)
{
    std::strcpy(color, c);
    color[COL_LEN - 1] = '\0';

}

std::ostream& operator<<(std::ostream& os, const lacksDMA & ls)
{
    os << (const ABC&)ls;
    os << "Color: " << ls.color << endl;
    return os;
}

void lacksDMA::View()
{
    ABC::View();
    cout << "Color: " << color << endl;
}


//hasbase class
hasDMA::hasDMA(const char * s, const char * l, int r) :ABC(l, r)
{
    style = new char[strlen(s) + 1];
    strcpy(style, s);
}

hasDMA::hasDMA(const char * s, const ABC & rs) : ABC(rs)
{
    style = new char[strlen(s) + 1];
    strcpy(style, s);
}

hasDMA::~hasDMA()
{
    delete [] style;
}

void hasDMA::View()
{
    ABC::View();
    cout << "Style: " << style << endl;
}

hasDMA & hasDMA::operator=(const hasDMA & hs)
{
    if (this == &hs)
        return *this;
    delete [] style;
    ABC::operator=(hs);
    style = new char[strlen(hs.style) + 1];
    strcpy(style, hs.style);
    return *this;
}


std::ostream& operator<<(std::ostream& os, const hasDMA & hs)
{
    os << (const ABC&)hs;
    os << "Color: " << hs.style << endl;
    return os;
}
