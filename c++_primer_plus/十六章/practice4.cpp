#include <iostream>
#include <algorithm>
#include <list>
/*
int reduce(long ar[], int n);
using namespace std;

int main()
{
    long ar[10] = {11, 3, 5, 9, 7, 4, 3, 5, 11, 3};
    cout << "The data: ";
    for (int i = 0; i < 10; ++i) {
        cout << ar[i] << " ";
    }
    cout << endl;
    cout << "After sort and unique: ";
    int n = reduce(ar,10);
    for (int i = 0;i<n ; ++i)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
    return 0;
}

int reduce(long ar[], int n)
{
    sort(ar, ar+n);
    long *p = unique(ar,ar+n);
    return (int)(p - ar);     //地址间隔
}
*/



int reduce(long ar[], int n);

int main()
{

	long ar[10] = { 11, 3, 5, 9, 7, 4, 3, 5, 11, 3};
	std::cout << "The data: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << ar[i] << " ";
    }

	int count = reduce(ar, 10);
	std::cout << "\n元素数目: " << count << std::endl;
	for (int i = 0; i < count; ++i)      //返回i+1
		std::cout << ar[i] << ' ';
	std::cout << std::endl;

	return 0;
}

int reduce(long ar[], int n)
{
	std::list<long> list;
	for (int i = 0; i < n; ++i)
		list.push_back(ar[i]);
	list.sort();
	list.unique();

	int count = 0;
	for (std::list<long>::iterator it = list.begin(); it != list.end(); ++it)
		ar[count++] = (*it);
	return count;
}

