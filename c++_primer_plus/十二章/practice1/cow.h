#ifndef COW_H_INCLUDED
#define COW_H_INCLUDED

class Cow
{
private:
    char name[20];
    char * hobby;
    double weight;
public:
    Cow();
    Cow(const char * nm, const char* ho, double wt);
    Cow(const Cow & c);
    ~Cow();
    Cow & operator=(const Cow & c);
    void ShowCow()const;
};

#endif // COW_H_INCLUDED
