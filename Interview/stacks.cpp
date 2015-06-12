#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include "stacks.hpp"

#define __STACKS
using namespace std;

template <class T>
void Stack<T>::print()
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

//main calling function
void runStack(void)
{
	Stack<double> s(40);
	s.push(3.23);
	s.push(4.34);
	s.push(6.23);
	s.push(78.23);
	s.push(34.5);
	s.print();
	s.pop();
	s.print();
	s.reverse();
	s.print();
}