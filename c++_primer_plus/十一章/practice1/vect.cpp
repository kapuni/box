//vect.cpp -- methods for Vector class
//practice2
#include <iostream>

#include <cmath>
#include "vect.h"
using std::sin;
using std::cos;
using std::atan2;
using std::cout;

namespace VECTOR
{
    const double Rad_to_deg = 57.2957795130823;

    //private methods
    //calculates magnitude from x and y
    void Vector::set_mag()
    {
        double mag;
        mag = sqrt(x * x +y * y);
    }
    void Vector::set_ang()
    {
        double ang;
        if  (x==0.0 && y==0.0)
            ang = 0.0;
        else
            ang = atan2(y, x);

    }
    //set x from polar coordinate
    void Vector::set_x(double mag, double ang)
    {
        x = mag * cos(ang);
    }

    //set y from polar coordinate
    void Vector::set_y(double mag, double ang)
    {
        y = mag * sin(ang);
    }

    //public methods
    Vector::Vector()
    {
        double mag;
        double ang;
        x = y =mag = ang = 0.0;
        mode = 'r';
    }

    //construct vector from rectangular coordinates if form is r
    //(the default) or else from polar coordinates if form is p
    Vector::Vector(double n1, double n2, char form)
    {
        double mag, ang;
        mode = form;
        if(form == 'r')
        {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if (form == 'p')
        {

            mag = n1;
            ang = n2 / Rad_to_deg;
            set_x(mag, ang);
            set_y(mag, ang);
        }
        else
        {

            cout << "Incorrect 3 rd argument to Vector()-- ";
            cout << "vector set to 0\n";
            x= y = mag = ang =0.0;
            mode = 'r';
        }
    }

    //set vector from rectangular coordinates if form is r
    //(the default) or else from polar coordinates if form is p
    void Vector::set (double n1, double n2, char form)
    {
        double mag, ang;
        mode = form;
        if(form =='r')
        {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if (form == 'p')
        {
            mag = n1;
            ang = n2 / Rad_to_deg;
            set_x(mag, ang);
            set_y(mag, ang);

        }
        else
        {
            cout << "Incorrect 3rd argument to Vector()-- ";
            cout << "vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = 'r';
        }
    }
    Vector::~Vector()
    {

    }
    void Vector::polar_mode()
    {
        mode = 'p';
    }

    void Vector::rect_mode()
    {
        mode = 'r';
    }

    //operator overloading
    // add two  Vectors
    Vector Vector::operator+(const Vector & b) const
    {
        return Vector(x + b.x, y+ b.y);
    }

    //subtract Vector b from a
    Vector Vector::operator-(const Vector & b)const
    {
        return Vector(x - b.x, y - b.y);
    }
    //¸ººÅ
    Vector Vector::operator-()const
    {
        return Vector(-x, -y);
    }

    //³ËºÅ
    Vector Vector::operator*(double n)const
    {
        return Vector(n*x, n* y);
    }

    //friend methods
    //multiply n by Vector a
    Vector operator* (double n, const Vector & a)
    {
        return a * n;
    }

    ////display rectangular coordinates if form is r
    //else display polar coordinates if form is p
    std::ostream & operator<< (std::ostream & os, const Vector & v)
    {
        if (v.mode == 'r')
            os << " (x, y) = (" << v.x << ", " << v.y << ") ";
        else if(v.mode == 'p')
        {
            os << "(m, a) = (" << v.magval() << ", "
            << v.angval() * Rad_to_deg << ") ";

        }
        else
            os << "Vector object mode is invalid";
        return os;
    }
}
