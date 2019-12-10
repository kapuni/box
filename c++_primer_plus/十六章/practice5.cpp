#include <iostream>
#include <algorithm>
#include <list>


template <class T>
int reduce(T ar[], int n);

using namespace std;
int main()
{
    //long part
	long ar[10] = { 11, 3, 5, 9, 7, 4, 3, 5, 11, 3};
	std::cout << "The data: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << ar[i] << " ";
    }

	int count = reduce(ar, 10);
	std::cout << "\n元素数目: " << count << std::endl;
	std::cout << "After sort and unique: " ;
	for (int i = 0; i < count; ++i)      //返回i+1
		std::cout << ar[i] << ' ';
	std::cout << std::endl << endl;


	//string part
	std::string s1[5] = { "tree", "ice" , "tree", "apple","banana"};
	std::cout << "The string: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << s1[i] << " ";
    }

	int counts = reduce(s1, 5);
	//std::cout << "\n元素数目: " << counts << std::endl;
	std::cout << "\nAfter sort and unique: " ;
	for (int i = 0; i < counts; ++i)      //返回i+1
		cout << s1[i] << ' ';
	std::cout << std::endl;


	return 0;
}
/*
template <class T>
int reduce(T ar[], int n)
{
    std::list<T> list;
    for (int i = 0; i < n; ++i)
		list.push_back(ar[i]);
	list.sort();
	list.unique();

	int count = 0;
	for (std::list<T>::iterator it = list.begin(); it != list.end(); ++it)
		ar[count++] = (*it);
	return count;
}
*/
template <class T>
int reduce(T str[], int n)
{
    sort(str, str + n);
    T* p = unique(str, str + n);
    return (int)(p - str);
}
