//practice2.cpp -- 构建candybar结构，尽量使用const，设置默认值
#include<iostream>
#include<stdlib.h>

using namespace std;
struct CandyBar
{
    char* brand;
    double weight;
    int calorie;
};

void showCandyBar(const CandyBar &candy);
void setCandyBar(CandyBar&, char * brand = "Millennium Munch", double weight = 2.85, int calorie = 350);
int main()
{
    CandyBar candy1;
    CandyBar candy2;
    setCandyBar(candy1);
    showCandyBar(candy1);
    setCandyBar(candy2, "I love you", 3.5,1);
    showCandyBar(candy2);
    system("pause");
    return 0;
}

void setCandyBar(CandyBar &candy,char * brand, double weight, int calorie)
{
    candy.brand = brand;
    candy.weight = weight;
    candy.calorie = calorie;
}

void showCandyBar(const CandyBar &candy)
{
    cout << "brand: " << candy.brand << endl;
    cout << "weight: " << candy.weight << endl;
    cout << "calorie: " << candy.calorie << endl;

}
