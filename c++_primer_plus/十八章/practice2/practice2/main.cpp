#include <iostream>
#include "cpmv.h"

int main()
{
	using std::cout;
	Cpmv temp;
	cout << "Object 0:\n";
	temp.Display();

	Cpmv temp1("number one", "number two");
	cout << "Object 1:\n";
	temp1.Display();

	Cpmv temp2(temp);
	cout << "Object 2:\n";
	temp2.Display();

	cout << "Object 3 = Object 1:\n";
	Cpmv temp3;
	temp3 = temp1;
	cout << "Object 3:\n";
	temp3.Display();
	cout << "Object 1:\n";
	temp1.Display();

	cout << "Object 4 = move(Obejct 3):\n";
	Cpmv temp4;
	temp4 = std::move(temp3);
	cout << "Object 4:\n";
	temp4.Display();
	cout << "Object 3:\n";
	temp3.Display();

	cout << "Obejct 5 = Object 3 + Obejct 4:\n";
	Cpmv temp5 = temp3 + temp4;
	cout << "Obejct 5:\n";
	temp5.Display();
	return 0;
}
