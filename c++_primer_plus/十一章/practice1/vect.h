//vect.h -- Vetor class with << mode state
//practice2
#ifndef VECT_H_INCLUDED
#define VECT_H_INCLUDED
#include <iostream>
#include <cmath>
namespace VECTOR
{
    class Vector
    {
    private:
        double x;           //horizontal value
        double y;           //vertical value

        char mode;          //'r' = rectangular, 'p' = polar
        //private methods for setting values
        void set_mag();
        void set_ang();
        void set_x(double mag, double ang);
        void set_y(double mag, double ang);
    public:
        Vector();
        Vector (double n1, double n2, char form = 'r');
        void set(double n1, double n2, char form = 'r');
        ~Vector();
        double xval()const {return x; }
        double yval()const {return y; }
        double magval()const
        {
            double mag;
            mag = sqrt(x * x + y* y);
            return mag;
        }
        double angval()const
        {
            double ang;
            if (x == 0.0 && y == 0.0)
                ang = 0.0;
            else
                ang = atan2(y, x);
            return ang;
        }
        void polar_mode();
        void rect_mode();
    //operator overloading
        Vector operator+ (const Vector & b)const;
        Vector operator- (const Vector & b)const;
        Vector operator- ()const;
        Vector operator* (double n )const;
        //friends
        friend Vector operator* (double n, const Vector & a);
        friend std::ostream & operator << (std::ostream & os, const Vector & v);

    };
}


#endif // VECT_H_INCLUDED
