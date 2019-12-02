#ifndef LOC_H_
#define LOC_H_
#include<stdexcept>
#include<string>

class bad_hmean : public std::logic_error
{
public:
	bad_hmean(const std::string & s = "hmean(), invalid argument" ):logic_error(s) {}
};


class bad_gmean : public std::logic_error
{
public:
	bad_gmean(const std::string &s = "gmean(), auguments shouble be >= 0") : logic_error(s) {}
};


#endif // LOC_H_

