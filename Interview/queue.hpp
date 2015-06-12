#ifndef __QUEUE_H
#define __QUEUE_H


//error codes
#define ERROR_QUEUE_EMPTY -1
#define ERROR_QUEUE_FULL -2

template <class T>
class Queue
{
private:
	int front;
	int rear;
	int size;
	int capacity;
	T *array;
public:
	Queue() 
	{
		front = rear =-1;
		size = 0;
		capacity = 0;

	};
	Queue(int capacity) 
	{
		front = rear =-1;
		size = 0;
		this->capacity = capacity;
		array = new T[capacity];
	};
	~Queue()
	{
		front = rear = 0;
		size = 0;
		capacity = 0;
		delete[] array;
	};
	bool isEmpty(){return size == 0;};
	bool isFull(){return size == capacity;};
	void enqueue(T const &data)
	{
		if(isFull()) return;		
		front = (front==-1)? 0 : front; 
		rear = (rear+1)%capacity;
		size++;
		array[rear] = data;
	};
	void append(T const &data)// add at the front
	{
		if(isFull()) return;

		front = (front==-1)? 0 : front;
		front = front>0? front-1:capacity-front-1; 
		size++;
		array[front] = data;
	};

	T dequeue()
	{
		T data;
		if(isEmpty())	return ERROR_QUEUE_EMPTY;
		size--;
		data = array[front];
		front = (front+1)%capacity;
		return data;
	};
	T dequeue_rear()
	{
		T data;
		if(isEmpty())	return ERROR_QUEUE_EMPTY;
		size--;
		data = array[rear];
		rear = (rear-1)%capacity;
		return data;
	};
	void print();
};
#ifdef __QUEUE

#else
void runQueue(void);
#endif

#endif //__QUEUE_H