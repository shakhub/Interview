#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include"queue.hpp"

#define __QUEUE
using namespace std;

template <class T>
void Queue<T>::print()
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
	Queue<double> q(10);
	q.enqueue(3.1);
	q.enqueue(4.2);
	q.enqueue(5.3);
	q.enqueue(6.4);
	q.enqueue(7.5);
	q.enqueue(8.6);
	
	q.print();
	q.append(45);
	q.print();
	cout << q.dequeue()<<endl;
	q.print();

}