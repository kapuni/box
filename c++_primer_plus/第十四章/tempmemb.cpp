//tempmemb.cpp -- template members
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class beta
{
private:
    template <typename V>    //模板类
    class hold
    {
    private:
        V val;
    public:
        hold(V v=0):val(v){}
        void show()const {cout<< val << endl;}
        V Value()const {return val;}
    };
    hold<T> q;
    hold<T> n;
public:
    beta(T t, int i): q(t), n(i) {}
    template<typename U>    //模板函数
    U blab(U u, T t) { return(n.Value() + q.Value() * u/ t);}
    void Show()const {q.show(); n.show();}
};

int main()
{
    beta<double> guy(3.5, 3);
    guy.Show();
    cout << guy.blab(10,2.3) << endl;
    cout << "Done\n";
    return 0;
}
