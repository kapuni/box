#include <iostream>
#include <cstring>
#include "port.h"

//port class
Port::Port(const char * br, const char *st,int b)
{
    brand = new char [strlen(br) + 1];
    strcpy(brand, br);
    strcpy(style, st);
    bottles = b;
}

Port::Port(const Port& p)
{
    brand = new char (strlen(p.brand) + 1);
    strcpy(brand, p.brand);
    strcpy(style, p.style);
    bottles = p.bottles;
}

Port& Port::operator=(const Port & p)
{
    if(&p == this)
        return (*this);
    delete [] brand;
    strcpy(brand, p.brand);
    strcpy(style, p.style);
    bottles = p.bottles;
}

Port & Port::operator+=(int b)
{
    bottles += b;
    return *this;
}

Port& Port::operator-=(int b)
{
    if(bottles >=b)
        bottles -=b;
    if(bottles < b)
        std::cout << "You don't have enough bottles.";
    return *this;//·µ»ØÖµ
}

void Port::Show()const
{
    std::cout << "Brand: " << brand << endl;
    std::cout << "Kind: " << style << endl;
    std::cout << "Bottles: " << bottles <<endl;
}

ostream & operator <<(ostream & os, const Port & p)
{
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}


//VintagePort class
VintagePort::VintagePort() :Port()
{
    nickname = new char[1];
    nickname[0] = '\0';
    year = 0;
}

VintagePort::VintagePort(const char *br,const char*st, int b,const char *nn,int y) :Port(br,st,b)
{
    nickname = new char [strlen(nn) + 1];
    strcpy(nickname, nn);
    year = y;
}

VintagePort::VintagePort(const VintagePort &vp) :Port(vp)
{
    nickname = new char [strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
}

VintagePort & VintagePort::operator=(const VintagePort & vp)
{
    if(&vp == this)
        return (*this);
    Port::operator=(vp);
    delete [] nickname;
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
}

void VintagePort::Show()const
{
    Port::Show();
    std::cout<< "Nickname: " << nickname << std::endl;
    std::cout << "Year: " << year << endl;
}

ostream & operator<<(ostream & os, const VintagePort & vp)
{
    os << (const Port&) vp;
    os << ", " << vp.nickname << ", " <<vp.year;
    return os;
}
