//temptemoover.cpp -- template overloading
#include<iostream>
//template A
template <typename T>
void ShowArray(T arr[] , int m);

//template B
template <typename T>
void ShowArray(T * arr[], int n);

struct debts
{
    char name[50];
    double amount;

};

int main()
{
    using namespace std;
    int things[6] = {13, 21, 103, 301, 310, 130};
    struct debts mr_E[3] =
    {
        {
            "Ima Wolfe", 2400.0
        },
        {
            "Ura Foxe", 1300.0
        },
        {
            "Iby  Stout", 1800.0
        }
    };
    double * pd[3];

    for (int i = 0; i< 3; i++)
        pd[i] = &mr_E[i].amount;

    cout << "Listing Mr.R's counts of thongs:\n";
    //use template A
    ShowArray(things, 6);

    cout << "Listing Mr.E's debts: \n";
    //use template B
    ShowArray(pd, 3);

    return 0;

}

template <typename T>
void ShowArray (T arr[], int n)
{
    using namespace std;
    cout << "template A\n";
    for (int i = 0; i< n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

template <typename T>
void ShowArray (T *arr[], int n)
{
    using namespace std;
    cout << "template B\n";
    for (int i = 0; i< n; i++)
        cout << *arr[i] << " ";
    cout << endl;
}
