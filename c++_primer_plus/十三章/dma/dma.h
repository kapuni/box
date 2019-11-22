//dma.h -- inheritance and dynamic memory allocation
#ifndef DMA_H_INCLUDED
#define DMA_H_INCLUDED
#include <iostream>
//Base class using dma
class baseDMA
{
private:
    char * label;
    int rating;
public:
    baseDMA(const char * l="null", int r=0);
    baseDMA(const baseDMA & rs);
    virtual ~baseDMA();
    baseDMA & operator=(const baseDMA & rs);
    friend std::ostream & operator<< (std::ostream & os, const baseDMA &rs);

};

//派生类
//使用隐式复制构造函数和赋值操作符
class lacksDMA: public baseDMA
{
private:
    enum{COL_LEN=40};
    char color[COL_LEN];
public:
    lacksDMA(const char * c= "blank", const char *l = "null", int r = 0);
    lacksDMA(const char * c, const baseDMA &rs);
    friend std::ostream & operator<< (std::ostream & os,const lacksDMA & rs);
};

//
class hasDMA: public baseDMA
{
    char * style;
public:
    hasDMA(const char *s="none", const char *l="null",int r=0);
    hasDMA(const char * s , const baseDMA & rs);
    hasDMA(const hasDMA & hs);
    ~hasDMA();
    hasDMA & operator= (const hasDMA & rs);
    friend std::ostream & operator << (std::ostream & os, const hasDMA & rs);
};

#endif // DMA_H_INCLUDED
