#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include "stacks.hpp"

#define __STACKS


template <class T>
void Stack<T>::print()
{
	if(isEmpty())
	{
		std::cout << " Error : Stack is empty.Nothing to print"<<std::endl;
		return ;
	}
	std::cout << "Stack :";
	for(int i=0;i<=top;i++)
		std::cout<< array[i] <<" ";
	std::cout<<std::endl;
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
	
	std::cout<<s.topofstack()<<std::endl;
	s.print();
}