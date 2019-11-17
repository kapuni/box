//comolex.cpp -- The functions' definition

#include <iostream>
#include "complex0.h"
using namespace std;

Complex::Complex()
{
    real = ima= 0.0;
}

Complex::Complex(double x, double y)
{
    real = x;
    ima = y;
}

Complex::~Complex()
{

}

Complex operator+(const Complex &c1, const Complex &c2)
{
    Complex sum;
    sum.real = c1.real + c2.real;
    sum.ima = c1.ima + c2.ima;
    return sum;
}

Complex operator-(const Complex & c1, const Complex & c2)
{
    Complex diff;
    diff.real = c1.real - c2.real;
    diff.ima = c1.ima - c2.ima;
    return diff;
}
Complex operator*(const Complex & c1, const Complex & c2)
{
    Complex mult;
    mult.real = c1.real * c2.real - c1.ima * c2.ima;
    mult.ima = c1.ima * c2.ima + c1.real * c2.real;

    return mult;
}

Complex operator*(double n, const Complex & c)
{
    Complex mult;
    mult.real = n * c.real;
    mult.ima = n * c.ima;
    return mult;
}


Complex operator~(const Complex & c)
{
    Complex conj;
    conj.real = c.real;
    conj.ima = -c.ima;
    return conj;
}

std::ostream & operator<<(std::ostream & os, const Complex & c)
{
    os << "(" << c.real << "," << c.ima << "i)";
    return os;
}

std::istream & operator>>(std::istream & is, Complex & c)
{
    cout << "real: ";
    is >> c.real;
    if (!is)
        return is;
    cout << "imaginary: ";
    is >> c.ima;
    return is;
}

