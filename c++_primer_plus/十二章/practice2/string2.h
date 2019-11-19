//头文件
#ifndef STRING2_H_
#define STRING2_H_
#include <iostream>
using std::ostream;
using std::istream;

class String
{
private:
    char * str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;//输入限制
public:
    String(const char * s);
    String();
    String(const String &);
    ~String();
    int length () const { return len; }

//新增函数
    void stringlow();
    void stringup();
    int has(char c);
    friend String operator+(const String & st1, const String & st2) ;

//运算符重载
    String & operator=(const String & st);
    String & operator=(const char * s);
    char & operator[](int i);
    const char & operator[](int i) const;


//友元运算符重载
    friend bool operator<(const String &st1, const String &st2);
    friend bool operator>(const String &st1, const String &st2);
    friend bool operator==(const String &st1, const String &st2);
    friend ostream & operator<<(ostream & os, const String &st);
    friend istream & operator>>(istream & is, String &st);

    static int HowMany();//静态成员函数
};

#endif
