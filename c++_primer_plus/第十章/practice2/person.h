//practice2
#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

class Person
{
private:
    static const int LIMIT = 25;
    std::string lname;
    char fname[LIMIT];
public:
    Person()
    {
        lname = ' ';
        fname[0] = '\0';

    };
    Person(const std::string & ln, const char * fn = "Heyyou");
    void Show() const;
    void FormalShow() const;
};


#endif // PERSON_H_INCLUDED
