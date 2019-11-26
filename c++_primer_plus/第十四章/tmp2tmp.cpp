//tmp2tmp.cpp -- template friend to a template class
#include<iostream>
using std::cout ;
using std::endl;

//template prototypes
template <typename T> void counts();
template <typename T> void reports(T &);

//template class
template <typename TT>
class HasFriendT
{
private:
    TT item;
    static int ct;
public:
    HasFriendT(const TT & i): item(i) {ct++;}
    ~HasFriendT() {ct--;}
    friend void counts<TT>();
    friend void reports <>(HasFriendT<TT> & ); //template parameter
};

template <typename T>
int HasFriendT<T>::ct = 0;

//template friend function definition
template <typename T>
void counts()
{
    cout << "template size :" << sizeof(HasFriendT<T> )<< endl;
    cout << "template counts() :" << HasFriendT<T>::ct << endl;
}

template <typename T>
void report(T & hf)
{
    cout << hf.item << endl;
}

int main()
{
    counts<int>();
    HasFriendT<int> hfil(10);
    HasFriendT<int> hfi2(20);
    HasFriendT<double> hfdb(10.5);

    reports(hfi1);             //generate report(HasFriendT<int> &)
    reports(hfi2);
    reports(hfdb);             //generate report(HasFriendT<double> &)

    cout << "counts<int>() output:\n";
    counts<int>();
    cout << "counts<double> () output:\n";
    counts<double>();

    return 0;

         }
