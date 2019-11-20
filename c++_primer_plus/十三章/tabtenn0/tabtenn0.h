//tabtenn0.h -- a table-tennis base class
#ifndef TABTENN0_H_INCLUDED
#define TABTENN0_H_INCLUDED
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


#endif // TABTENN0_H_INCLUDED
