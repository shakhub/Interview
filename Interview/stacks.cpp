
#include<stdio.h>
#include<stdlib.h>
#include "stacks.hpp"

#define __STACKS

// stack using array
Stack *createStack(int capacity)
{
	Stack *stack = (Stack*)malloc(sizeof(Stack));
	stack->top = -1;
	stack->capacity = capacity;
	stack->array = (int*)malloc(capacity*sizeof(int));
	return stack;
}
int isStackEmpty(Stack *stack)
{
	return stack->top == -1;
}
int isStackFull(Stack *stack)
{
	return stack->top == stack->capacity - 1;
}
void pushToStack(Stack *stack, int data) 
{
	if (isStackFull(stack)) return;
	stack->array[++stack->top] = data;
}

int popFromStack(Stack *stack)
{
	if (isStackEmpty(stack)) return ERROR_STACK_EMPTY;
	return stack->array[stack->top--];
}
//stack using linked lists
StackLL *createStackLL(int data)
{
	StackLL *stack = (StackLL *)malloc(sizeof(StackLL));
	stack->data = data;
	stack->next = NULL;
	return stack;
}
int isStackLLEmpty(StackLL *stack)
{
	return stack == NULL;
}
void pushToStackLL(StackLL **stack, int data)
{
	StackLL *newNode = createStackLL(data);
	newNode->next = *stack; // the new node will point to where the head was pointing
	*stack = newNode; // the head will point to the new node
}
int popFromStackLL(StackLL **stack)
{
	int pop;
	StackLL *temp = *stack;
	if (isStackLLEmpty(*stack)) return ERROR_STACK_EMPTY;
	pop = temp->data;
	*stack = (*stack)->next;
	free(temp);
	return pop;

}

//algorithms
void printStack(Stack *stack)
{
	while (!isStackEmpty(stack))
		printf("%d\n", popFromStack(stack));
}
void insertFromBottom(Stack *stack, int data)
{
	int temp;
	if (isStackEmpty(stack))
		pushToStack(stack, data);
	else
	{
		temp = popFromStack(stack);
		insertFromBottom(stack, data);
		pushToStack(stack, temp);

	}
}
void reverseStack(Stack *stack)
{
	int temp;
	if (!isStackEmpty(stack))
	{
		temp = popFromStack(stack);
		reverseStack(stack);
		insertFromBottom(stack, temp);
	}
}

//main calling function
void runStack(void)
{
	Stack *s = createStack(4);
	pushToStack(s, 4);
	pushToStack(s, 3);
	pushToStack(s, 2);
	pushToStack(s, 1);


	reverseStack(s);
	printStack(s);
	system("PAUSE");
}