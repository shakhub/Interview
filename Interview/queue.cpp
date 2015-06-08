#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include"queue.hpp"

#define _QUEUE
using namespace std;

Queue::Queue()
{
	front = rear =-1;
	size = 0;
	capacity = 0;
}
Queue::Queue(int capacity)
{
	front = rear =-1;
	size = 0;
	this->capacity = capacity;
	array = new int[capacity];
}
Queue::~Queue()
{
	front = rear = 0;
	size = 0;
	capacity = 0;
	delete[] array;
}
void Queue::enqueue(int data)
{
	if(isFull())
	{
		cout << "Error: Queue is full" << endl;
		return;
	}
	front = (front==-1)? 0 : front; 
	rear = (rear+1)%capacity;
	size++;
	array[rear] = data;
}
void Queue::append(int data)
{
	if(isFull())
	{
		cout << "Error: Queue is full" << endl;
		return;
	}
	
	front = (front==-1)? 0 : front;
	front = front>0? front-1:capacity-front-1; 
	size++;
	array[front] = data;

}
int Queue::dequeue()
{
	int data;
	if(isEmpty())
	{
		cout << "Error: Queue is empty."<<endl;
		return ERROR_QUEUE_EMPTY;
	}
	size--;
	data = array[front];
	front = (front+1)%capacity;
	return data;
}
int Queue::dequeue_rear()
{
	int data;
	if(isEmpty())
	{
		cout << "Error: Queue is empty."<<endl;
		return ERROR_QUEUE_EMPTY;
	}
	size--;
	data = array[rear];
	rear = (rear-1)%capacity;
	return data;
}

void Queue::print()
{
	if(isEmpty())
	{
		cout << "Error: Queue is empty."<<endl;
		return ;
	}
	cout<< "Queue :";
	for(int i = 0;i<size;i++)
	{

		cout << array[(i+front)%capacity]<< " " ;
	}
	cout<<endl;
}


void runQueue(void)
{

	Queue q(10);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	q.enqueue(7);
	q.enqueue(8);
	
	q.print();
	q.append(45);
	q.print();
	cout << q.dequeue()<<endl;
	q.print();
}