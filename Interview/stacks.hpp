//error codes
#define ERROR_STACK_EMPTY -1
#define ERROR_STACK_FULL -2
//stacks using arrays
typedef struct Stack
{
	int capacity;
	int top;
	int *array;
}Stack;

// stacks using linked list
typedef struct StackLL
{
	int data;
	struct StackLL *next;
}StackLL;

Stack *createStack(int );
int isStackEmpty(Stack *);
int isStackFull(Stack *);
void pushToStack(Stack *, int );
int popFromStack(Stack *);
