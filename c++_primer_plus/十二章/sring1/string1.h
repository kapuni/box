//string1.h -- fixed and augmented string class definition
#include <iostream>
using std::ostream;
using std::istream;

#ifndef STRINGBAD_H_INCLUDED
#define STRINGBAD_H_INCLUDED

class String
{
private:

    int len;
    static int num_strings;

public:
    static const int CINLIM = 80;
    char * str;
    //constructors and other methods
    String (const char * s);  //constructor
    String();                  //default constructor
    String(const String &);    //copy constructor
    ~String();                 //destructor
    int length(){ return len;}
    //overloading operator methods
    String & operator=(const String &);
    String & operator=(const char *);
    char & operator[](int i);
    const char & operator[](int i) const;
    //overloaded operator friends
    friend bool operator< (const String &st1, const String &st2);
    friend bool operator< (const String &st1, const String &st2);
    friend bool operator== (const String &st1, const String &st2);
    friend std::ostream & operator<<(std::ostream & os, const String & st);
    friend std::istream & operator>>(std::istream & is, String & st);
    //static function
    static int HowMany();
};


#endif // STRINGBAD_H_INCLUDED
