#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include <iostream>
#include <string>
using std::string;

class Person
{
private:
    string firstname;
    string lastname;
protected:
    virtual void Data() const;
    virtual void Get();
public:
    Person():firstname("null"), lastname("null") {};
    Person(string f,string l)
    :firstname(f),lastname(l) {};
    virtual ~Person() = 0;
    virtual void Set() = 0;
    virtual void Show() const = 0;
};

class Gunslinger : virtual public Person
{
private:
    double time; //拔枪时间
    int num;     //刻痕数
protected:
    void Data() const; //派生类的虚函数virtual可以不写
    void Get();
public:
    Gunslinger() : Person(), time(0.0), num(0){}
    Gunslinger(string f, string l, double t, int n)
        : Person(f, l), time(t), num(n) {}
    Gunslinger(Person & p, double t, int n)
        :Person(p), time(t), num(n) {};
    double Drawtime(){return time;}
    void Set();
    void Show() const;

};

class PokerPlayer : virtual public Person
{
private:
    int card;
    //这里简化了扑克牌，直接用1-52表示
protected:
    void Data() const;
    void Get();
public:
    PokerPlayer() : Person(), card(1){};
    PokerPlayer(string f, string l, int c)
        : Person(f, l), card(c) {};
    PokerPlayer(Person & p, int c)
        :Person(p), card(c) {};
    int Drawcard(){return card;}
    void Set();
    void Show() const;
};

class BadDude : public Gunslinger, public PokerPlayer
{
protected:
    void Data() const;
    void Get();
public:
    BadDude() {};
    BadDude(string f, string l, double t = 0.0, int n = 0, int c = 1)
        : Person(f, l), Gunslinger(f, l, t, n), PokerPlayer(f, l, c){};
    BadDude(Person & p,  double t, int n, int c)
        : Person(p), Gunslinger(p, t, n), PokerPlayer(p, c){};
    BadDude(Gunslinger & gs, int c)
        : Person(gs), Gunslinger(gs), PokerPlayer(gs, c){};
    BadDude(PokerPlayer & pp, double t , int n)
        : Person(pp), Gunslinger(pp, t, n), PokerPlayer(pp){};
    double GDraw(){return Drawtime();}
    int CDraw(){return Drawcard();}
    void Set();
    void Show() const;
};

#endif // PERSON_H_INCLUDED
