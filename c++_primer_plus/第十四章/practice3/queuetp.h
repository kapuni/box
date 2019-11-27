#ifndef QUEUETP_H_INCLUDED
#define QUEUETP_H_INCLUDED

template <class T>
class QueueTp
{
private:
    const int Q_size = 10;
    T * data;
    int top;

public:
    QueueTp() {data= new T[Q_size]; top=0;}
    QueueTp(int q) {data = new T[2 *q]; top = 0;}
    ~QueueTp() {delete[] data;}

    bool isempty() {return top==0;}
    bool isfull() {return top==Q_size;}
    bool Push(T item);
    bool Pop();
    T &front()const;
    T &rear() const;
};

template <class T>
bool QueueTp<T>::Push(T item)
{
    if(isfull())
        return false;

    for(int i = top; i> 0;--i)
    {
        data[i] = data[i-1];
    }
    data[0] = item;
    ++top;
    return true;
}

template <class T>
bool QueueTp<T> ::Pop()
{
    if(isempty())
        return false;

    --top;
    return true;
}

template <class T>
T &QueueTp<T> ::front() const
{
    return data[top - 1];

}

template <class T>
T &QueueTp<T> ::rear()const
{
    return data[0];
}

#endif // QUEUETP_H_INCLUDED
