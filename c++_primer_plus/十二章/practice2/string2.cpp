//类实现文件，
#include <cstring>
#include <cctype>
#include "string2.h"
using std::cout;
using std::cin;

int String::num_strings = 0;//初始化为0，并且指出了类型
//初始化应该在方法文件中，不在类声明文件

int String::HowMany()//静态方法
{
    return num_strings;
}

String::String(const char * s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
}

String::String()
{
    len = 4;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String::String(const String & st)
{
    num_strings++;
    len = st.len;
    str = new char [len + 1];
    std::strcpy(str, st.str);
}

String::~String()
{
    --num_strings;
    delete [] str;
}

String & String::operator=(const String & st)
{
    if (this == &st)
        return *this;
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

String & String::operator=(const char * s)
{
    delete [] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

char & String::operator[](int i)
{
    return str[i];
}

const char & String::operator[](int i) const
{
    return str[i];
}

bool operator<(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2)
{
    return st2 < st1;
}

bool operator==(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

ostream & operator<<(ostream & os, const String &st)
{
    os << st.str;
    return os;
}

istream & operator>>(istream & is, String &st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;//输入字符不为空时
    while(is && is.get() != '\n')
        continue;
    return is;
}

//新增函数的实现
void String::stringlow()
{
    for (int i = 0; i < len;i++)
    {
        if(isupper((str[i])))
            str[i]= tolower(str[i]);
    }
}

void String::stringup()
{
    for (int i = 0; i < len;i++)
    {
        if(islower((str[i])))
            str[i]= toupper(str[i]);
    }
}

int String::has(char c)
{
    int count = 0;
    for (int i = 0; i < len;i++)
    {
        if( str[i]== c)
            count++;
    }
    return count;
}

String operator+(const String & st1, const String & st2)
{
    String s;
    s.len = st1.len + st2.len;
    s.str = new char [s.len + 1];
    for (int i = 0; i < st1.len; i++)
    {
        s.str[i] = st1.str[i];
    }

    for (int i = st1.len; i < s.len; i++)
    {
        s.str[i] = st2.str[i-st1.len];
    }
    s.str[s.len] = NULL;
    return s;
}
/*---------加法重载的第二种方式，较为简单-------------
String operator+(const String &st1, const String &st2)
{
    String s;
    s.len = st1.len + st2.len;
    s.str = new char[s.len + 1];
    strcpy(s.str, st1.str);
    strcat(s.str, st2.str);
    return s;
}*/
