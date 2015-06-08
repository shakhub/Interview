//error codes
#ifndef __STACKS_H
#define __STACKS_H

#define ERROR_STACK_EMPTY -1
#define ERROR_STACK_FULL -2

class Stack
{
private:
	unsigned int capacity;
	int top;
	int *array;
public:
	Stack();// default constructor;
	Stack(int cap); // constructor with capacity
	~Stack();//destructor
	bool isEmpty(){return top==-1;};
	bool isFull(){return top==capacity-1;};
	void push(int data); // insert at top 
	void append(int data); // insert at bottom 
	int pop();
	void reverse();
	void print();


};
void runStack();
#endif // __STACKS_H