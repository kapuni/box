//sale.h -- exceptions and inheritance
#include <stdexcept>
#include <string>

class Sales
{
public:
	enum {MONTHS = 12};
	class bad_index :public  std::logic_error
	{
	public:
		explicit bad_index(int ix, const std::string & s = "Index error in Sales obkect\n");
		int bi_val() const { return bi; }
		virtual ~bad_index() throw(){}

	private:
		int bi;
	};
	explicit Sales(int yy = 0);
	Sales(int yy, const double * gr, int n);
	virtual ~Sales() {}
	int Year()const { return year; }
	virtual double operator[] (int i) const;
	virtual double & operator[](int i);
private:
	double gross[MONTHS];
	int year;

};

class LabeledSales : public Sales
{
public:
	class nbad_index : public Sales::bad_index
	{
	public:
		nbad_index(const std::string & lb, int ix, const std::string & s = "Index error in LabeledSales object\n");
		const std::string & label_val()const { return lb1; }
		virtual ~nbad_index() throw() {}

	private:
		std::string lb1;
	};
	explicit LabeledSales(const std::string & lb = "none", int yy = 0);

	LabeledSales(const std::string & lb, int yy, const double * gr, int n);

	virtual ~LabeledSales() {}
	const std::string & Label() const { return label; }
	virtual double operator[](int i) const;
	virtual double & operator[](int i);
private:
	std::string label;

};
