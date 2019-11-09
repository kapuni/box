#ifndef GOLF1_H_INCLUDED
#define GOLF1_H_INCLUDED


class Golf
{
private:
    std::string fullname;
    int handicap;
public:
    Golf(const std::string name, int hc = 0);
    int setgolf();
    void sethandicap(const int hc);
    void showgolf() const;
};


#endif // GOLF1_H_INCLUDED
