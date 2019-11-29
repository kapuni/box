//queuetp.h -- queue template with a nested class
#ifndef QUEUETP_H_
#define QUEUETP_H_

template  <class Item>
class QueueTP
{
public:
	QueueTP(int qs=Q_SIZE);
	~QueueTP();
	bool isempty()const { return items == 0; }
	bool isfull()const { return items == qsize; }
	int queuecount()const { return items; }
	bool enqueue(const Item &item);       //队尾加人
	bool dequeue(Item &item);             //队头出人
private:
	enum{Q_SIZE= 10};
	//Node is a nested class definition
	class Node
	{
	public:
		Item item;
		Node * next;

		Node(const Item & i):item(i), next(0) {}
	};
	Node * front;       //队列头指针
	Node * rear;        //队列尾指针
	int items;          //目前队列数
	const int qsize;   //最大队列数
	QueueTP(const QueueTP & q) : qsize(0){}
	QueueTP & operator=(const QueueTP & q) { return *this; }

};

//QueueTp methods
template <class Item>
QueueTP<Item>::QueueTP(int qs) : qsize(qs)
{
	front = rear = 0;
	items = 0;
}

template <class Item>
QueueTP<Item>::~QueueTP() 
{
	Node * temp;
	while (front != 0)           //当队列目前不空
	{ 
		temp = front;            //保存队列数的地址
		front = front->next;     //指向下一个
		delete temp;              //删除前一个地址
	}
}

//Add item to queue
template <class Item>
bool QueueTP<Item>::enqueue(const Item & item)
{
	if (isfull())
		return false;
	Node * add = new Node(item);  //创建Node
	items++;
	if (front == 0)
		front = add;         //如果队列空，放到队列头
	else
		rear->next = add;   //其他放到队列后面
	rear = add;
	return true;
}

template <class Item>
bool QueueTP<Item>::dequeue(Item & item)
{
	if (front == 0)
		return false;
	item = front->item;     //实例移到队列头地址
	items--;          
	Node * temp = front;    //保存第一个实例的位置
	front = front->next;    //指向下一个实例
	delete temp;
	if (items == 0)
		rear = 0;
	return true;
}
#endif // !QUEUETP_H_

