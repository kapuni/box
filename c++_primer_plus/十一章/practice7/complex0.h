#ifndef COMPLEX0_H_
#define COMPLEX0_H_

#include <iostream>

class Complex
{
private:
    double real;
    double ima;
public:
    Complex();
    Complex(double x, double y);
    ~Complex();
    friend Complex operator+(const Complex & c1, const Complex & c2);
    friend Complex operator-(const Complex & c1, const Complex & c2);
    friend Complex operator*(const Complex & c1, const Complex & c2);
    friend Complex operator*(double n, const Complex & c);

    friend Complex operator~(const Complex & c);
    friend std::ostream & operator<<(std::ostream & os, const Complex & c);
    friend std::istream & operator>>(std::istream & os,  Complex & c);
};

#endif
