//tabtnn1.h -- simple inheritance
#ifndef TABTENN1_H_INCLUDED
#define TABTENN1_H_INCLUDED
//simple base class
class TableTennisPlayer
{
private:
    enum{LIM = 20};
    char firstname[LIM];
    char lastname[LIM];
    bool hasTable;
public:
    TableTennisPlayer(const char * fn = "none",
                      const char * ln = "none", bool ht = false);
    void Name()const;
    bool HasTable()const {return hasTable;};
    void ResetTable (bool v) {hasTable = v;};
};
// simple derived class
class RatedPlayer: public TableTennisPlayer
{
private:
    unsigned int rating;
public:
    RatedPlayer (unsigned int r = 0, const char * fn = "none",
                 const char * ln = "none", bool ht =false);
    RatedPlayer (unsigned int r, const TableTennisPlayer & tp);
    unsigned int Rating() {return rating;}
    void ResetTable(unsigned int r) {rating = r;}
};
#endif // TABTENN1_H_INCLUDED
