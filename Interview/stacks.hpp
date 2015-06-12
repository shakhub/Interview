//error codes
#ifndef __STACKS_H
#define __STACKS_H

#define ERROR_STACK_EMPTY -1
#define ERROR_STACK_FULL -2

template <class T>
class Stack
{
private:
	unsigned int capacity;
	int top;
	T *array;
public:
	Stack()
	{
		capacity = 0;
		top = -1;
	};// default constructor;
	Stack(int capacity)// constructor with capacity
	{
		this->capacity = capacity;
		top = -1;
		array = new T[capacity];
	};
	~Stack() {delete[] array;};//destructor
	bool isEmpty(){return top==-1;};
	bool isFull(){return top==capacity-1;};
	void push(T data) // insert at top 
	{
		if(isFull()) return;
		array[++top] = data;
	};
	void append(T data) // insert at bottom 
	{
		T temp;
		if(isEmpty())
			push(data);
		else
		{
			temp = pop();
			append(data);
			push(temp);
		}
	};
	T pop()
	{
		if(isEmpty()) return ERROR_STACK_EMPTY;
		return array[top--];
	};
	void reverse()
	{
		T temp;
		if(!isEmpty())
		{
			temp = pop();
			reverse();
			append(temp);
		}
	};
	void print();
};
void runStack();
#endif // __STACKS_H