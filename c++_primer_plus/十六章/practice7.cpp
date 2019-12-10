//从m个随机数中取出 n个不重复的数字
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

vector<int> Lotto(int m, int n);
void show(int n) { cout << n << " ";}

int main()
{
    srand((int)time(0));
    cout << "Display the random number:" << endl;
    vector<int> winner;
    winner = Lotto(51, 6);
    for_each(winner.begin(), winner.end(), show);

    return 0;
}

vector<int> Lotto(int m, int n)
{
    vector<int> temp;
    for (int i= 1; i<= m; i++)
        temp.push_back(i);
    random_shuffle(temp.begin(), temp.end());  //随机排列
    vector<int>::iterator last;
    last = (temp.begin(), temp.begin() + n);
    temp.erase(last, temp.end()); //取前六位
    //另外可以 ：temp.resize(n);
    return temp;
}
