#include <iostream>
#include <cstring>
#include "cow.h"

Cow::Cow()
{
    name[0] = '\0';
    hobby = new char[1];
    hobby[0] = '\0';
    weight = 0;
}

Cow::Cow(const char * nm, const char * ho, double wt)
{
    strcpy(name, nm);
    int len;
    len = std::strlen(ho);
    hobby = new char[len + 1];
    strcpy(hobby, ho);
    weight = wt;
}

Cow::Cow(const Cow &c)
{
    std::strcpy(name, c.name);
    int len;
    len = std::strlen(c.hobby);
    hobby = new char[len + 1];
    weight = c.weight;
}

Cow::~Cow()
{
    delete []hobby;
}

Cow &Cow::operator=(const Cow & c)
{
    int len;
    if(this == &c)
        return *this;
    delete[] hobby;
    weight = c.weight;
    len = std::strlen(c.name);
    hobby = new char[len + 1];
    std::strcpy(hobby, c.hobby);
    std::strcpy(name, c.name);
    return *this;
}

void Cow::ShowCow() const
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Hobby: " << hobby << std::endl;
    std::cout << "Weight: " << weight << std::endl;
    std::cout << std::endl;
}
