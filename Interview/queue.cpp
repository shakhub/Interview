#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include"queue.hpp"

#define __QUEUE

template <class T>
void Queue<T>::print()
{
	if(isEmpty())
	{
		std::cout << "Error: Queue is empty."<<std::endl;
		return ;
	}
	std::cout<< "Queue :";
	for(int i = 0;i<size;i++)
	{

		std::cout << array[(i+front)%capacity]<< " " ;
	}
	std::cout<<std::endl;
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
	std::cout << q.dequeue()<<std::endl;
	q.print();

}