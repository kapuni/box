//studentc.h -- defining a student class using containment
#ifndef STUDENTC_H_INCLUDED
#define STUDENTC_H_INCLUDED

#include <iostream>
#include <string>
#include <valarray>
class Student
{
private:
    typedef std::valarray<double> ArrayDb;  //重命名td::valarray<double>
    std::string name;   //包含对象
    ArrayDb scores;     //包含duix
    //private method for scores output
    std::ostream & arr_out(std::ostream & os) const;
public:
    Student() : name("Null Student"), scores() {}
    Student(const std::string & s) :name(s), scores() {}
    explicit Student(int n) :name("Nully"), scores(n) {}
    Student(const std::string & s, int n) : name(s), scores(n) {}
    Student(const std::string & s, const ArrayDb & a)
    :name(s), scores(a) {}
    Student(const char *str, const double * pd, int n)
    :name(str), scores(pd, n) {}
    ~Student() {}
    double Average() const;
    const std::string  & Name() const;
    double & operator[] (int i);
    double operator[](int i) const;
    //friend input
    friend std::istream & operator>>(std::istream & is, Student & stu); //1 word
    friend std::istream & getline(std::istream & is, Student & stu); //1 line
    //output
    friend std::ostream & operator<< (std::ostream & os, const Student & stu);
};


#endif // STUDENTC_H_INCLUDED
