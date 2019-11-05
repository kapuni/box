//practice3.cpp
#include<iostream>
#include<cstring>
#include<new>

struct chaff
{
    char dross[20];
    int slag;
};

const int BUF = 512;
const int N = 2;
char buffer[BUF];
const char ch[] = "hello";

int main()
{
    using namespace std;
    chaff *pd1, *pd2;
    int i;
    cout << "Calling new and placement new: \n";
    pd1 = new chaff;
    pd2 = new (buffer) chaff;
    for (i = 0; i < N; i++)
    {
        pd2[i].slag = pd1[i].slag = 1000 + 20 * i;
        strcpy(pd1[i].dross, ch);
        strcpy(pd2[i].dross, ch);
    }

    cout << "Buffer address:\n" << "  heap: " << pd1 << " static: " << (void*) buffer << endl;
    cout << "BUffer contents:\n";
    for (i = 0; i< N; i++)
    {
        cout << pd1[i].dross << " at " << &pd1[i].dross << endl;
        cout << pd1[i].slag << " at " << &pd1[i].slag << endl;

        cout << "          "
             << pd2[i].dross << " at " << &pd2[i].dross << endl;

        cout << "          "
        << pd2[i].slag << " at " << &pd2[i].slag << endl;

    }

    cout << "\nCalling new and placement new a second time:\n";
    chaff *pd3, *pd4;
    pd3 = new chaff;
    pd4 = new (buffer) chaff;
    for(i = 0; i< N; i++)
    {
        pd4[i].slag = pd3[i].slag = 1000 + 40 * i;
        strcpy(pd1[i].dross, ch);
        strcpy(pd2[i].dross, ch);
    }
    cout << "Buffer address: \n" << " heap:" << pd1 << " static:" << (void*)buffer << endl;

    cout << "Buffer contents:\n";
    for (i = 0; i< N; i++)
    {
        cout << pd3[i].dross << " at " << &pd3[i].dross << "; \n";
        cout << pd3[i].slag << " at " << &pd3[i].slag << endl;

        cout << pd4[i].dross << " at " << &pd4[i].dross << endl;
        cout << pd4[i].slag << " at " << &pd4[i].slag << endl;


    }

    cout << "\nCalling new and placement new a third time:\n";
    delete [] pd1;
    pd1 = new chaff;
    pd2 = new (buffer + N * sizeof(chaff)) chaff;

    for (i = 0; i< N; i++)
    {
        cout << pd1[i].dross << " at " << &pd1[i].dross << "; \n";
        cout << pd1[i].slag << " at " << &pd1[i].slag << endl;

        cout << pd2[i].dross << " at " << &pd2[i].dross << endl;
        cout << pd2[i].slag << " at " << &pd2[i].slag << endl;

    }
    delete []pd1;
    delete[]pd3;

    return 0;

}
