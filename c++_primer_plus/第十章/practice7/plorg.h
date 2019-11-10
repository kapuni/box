#ifndef PLORG_H_INCLUDED
#define PLORG_H_INCLUDED


using namespace std;
class Plorg
{
private:
	string name;         //char name[20];
	int CI;
public:
	Plorg(string name="Plorga" , int CI = 50);      //默认构造参数
	                                            //Plorg(char name[20]="Plorga" , int CI = 50);
	void update(const int & n);
	void show() const;



#endif // PLORG_H_INCLUDED
