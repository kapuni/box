
//use_sales.cpp
#include "sales.h"
#include <iostream>

int main()
{
	double vals1[12] =
	{
		1220, 1100, 1122, 2212, 1232, 2334,
		2884, 2393, 3302, 2922, 3002, 3544
	};

	double vals2[12] =
	{
		12, 11, 22, 21, 32, 34,
		28, 29, 33, 29, 32, 35
	};

	Sales sales1(2011, vals1, 12);
	LabeledSales sales2("Blogstar", 2012, vals2, 12);

	std::cout << "First try block:\n";
	try
	{
		int i;
		std::cout << "Year = " << sales1.Year() << std::endl;
		for (i = 0; i < 12; ++i)
		{
			std::cout << sales1[i] << ' ';
			if (i % 6 == 5)
				std::cout << std::endl;
		}
		std::cout << "Year = " << sales2.Year() << std::endl;
		std::cout << "Label = " << sales2.Label() << std::endl;
		for (i = 0; i <= 12; ++i)
		{
			std::cout << sales2[i] << ' ';
			if (i % 6 == 5)
				std::cout << std::endl;
		}
		std::cout << "End of try block 1.\n";
	}
	catch (std::logic_error &le)
	{
		std::cout << le.what();
		if (LabeledSales::nbad_index *ni = dynamic_cast<LabeledSales::nbad_index *>(&le))
		{
			std::cout << "Company: " << ni->label_val() << std::endl;
			std::cout << "bad index: " << ni->bi_val() << std::endl;
		}
		else if (Sales::bad_index *bi = dynamic_cast<Sales::bad_index *>(&le))
			std::cout << "bad index: " << bi->bi_val() << std::endl;
	}

	std::cout << "\nNext try block:\n";
	try
	{
		sales2[2] = 37.5;
		sales1[20] = 23345;
		std::cout << "End of try block 2.\n";
	}
	catch (std::logic_error &le)
	{
		std::cout << le.what();
		if (LabeledSales::nbad_index *ni = dynamic_cast<LabeledSales::nbad_index *>(&le))
		{
			std::cout << "Company: " << ni->label_val() << std::endl;
			std::cout << "bad index: " << ni->bi_val() << std::endl;
		}
		else if (Sales::bad_index *bi = dynamic_cast<Sales::bad_index *>(&le))
			std::cout << "bad index: " << bi->bi_val() << std::endl;
	}

	return 0;

}