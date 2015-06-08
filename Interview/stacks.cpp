#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include "stacks.hpp"

#define __STACKS
using namespace std;
Stack::Stack()
{
	//constructor
	capacity = 0;
	top = -1;
}
Stack::Stack(int capacity)
{
	this->capacity = capacity;
	top = -1;
	array = new int[capacity];
}
Stack::~Stack()
{
	delete[] array;
}

void Stack::push(int data)
{
	if(isFull()) 
	{
		cout << " Error : Stack is full. Push unsuccessful"<<endl;
		return;
	}
	array[++top] = data;
}
void Stack::append(int data)
{
	int temp;
	if(isEmpty())
		push(data);
	else
	{
		temp = pop();
		append(data);
		push(temp);
	}

}
void Stack::print()
{
	if(isEmpty())
	{
		cout << " Error : Stack is empty.Nothing to print"<<endl;
		return ;
	}
	cout << "Stack :";
	for(int i=0;i<=top;i++)
		cout<< array[i] <<" ";
	cout<<endl;
}
int Stack::pop()
{
	if(isEmpty()) 
	{
		cout << " Error : Stack is empty.Pop unsuccessful"<<endl;
		return ERROR_STACK_EMPTY;
	}
	//cout << "Pop value :" << array[top]<<endl;
	return array[top--];
}
void Stack::reverse()
{
	int temp;
	if(!isEmpty())
	{
		temp = pop();
		reverse();
		append(temp);
	}
}

//main calling function
void runStack(void)
{
	Stack s(40);
	s.push(3);
	s.push(4);
	s.push(6);
	s.push(78);
	s.push(34);
	s.print();
	s.pop();
	s.print();
	s.reverse();
	s.print();
}