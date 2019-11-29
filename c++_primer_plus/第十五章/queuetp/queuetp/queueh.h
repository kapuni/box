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
	bool enqueue(const Item &item);       //��β����
	bool dequeue(Item &item);             //��ͷ����
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
	Node * front;       //����ͷָ��
	Node * rear;        //����βָ��
	int items;          //Ŀǰ������
	const int qsize;   //��������
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
	while (front != 0)           //������Ŀǰ����
	{ 
		temp = front;            //����������ĵ�ַ
		front = front->next;     //ָ����һ��
		delete temp;              //ɾ��ǰһ����ַ
	}
}

//Add item to queue
template <class Item>
bool QueueTP<Item>::enqueue(const Item & item)
{
	if (isfull())
		return false;
	Node * add = new Node(item);  //����Node
	items++;
	if (front == 0)
		front = add;         //������пգ��ŵ�����ͷ
	else
		rear->next = add;   //�����ŵ����к���
	rear = add;
	return true;
}

template <class Item>
bool QueueTP<Item>::dequeue(Item & item)
{
	if (front == 0)
		return false;
	item = front->item;     //ʵ���Ƶ�����ͷ��ַ
	items--;          
	Node * temp = front;    //�����һ��ʵ����λ��
	front = front->next;    //ָ����һ��ʵ��
	delete temp;
	if (items == 0)
		rear = 0;
	return true;
}
#endif // !QUEUETP_H_

