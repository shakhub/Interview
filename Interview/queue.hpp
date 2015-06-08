//error codes
#define ERROR_QUEUE_EMPTY -1
#define ERROR_QUEUE_FULL -2
#if 0
typedef struct Queue
{
	int front, rear, size, capacity;
	int *array;
}Queue;

typedef struct Qnode
{
	int data;
	struct Qnode *next;
}Qnode;
typedef struct QueueLL
{
	Qnode *front, *rear;
}QueueLL;

Queue *createQueue(int capacity);
int isEmptyQueue(Queue *);
int isFullQueue(Queue *);
void enqueue(Queue *, int);
void insertFrontQueue(Queue *, int );
int dequeue(Queue *);
int removeRearQueue(Queue *);
Qnode *createQNode(int);
QueueLL *createQueueLL(void);
void enqueueLL(QueueLL *, int);
Qnode *dequeueLL(QueueLL *);
#else
class Queue
{
private:
	int front;
	int rear;
	int size;
	int capacity;
	int *array;
public:
	Queue();
	Queue(int capacity);
	~Queue();
	bool isEmpty(){return size == 0;};
	bool isFull(){return size == capacity;};
	void enqueue(int data);
	void append(int data);// add at the front
	int dequeue();
	int dequeue_rear();
	void print();
};
#endif
void runQueue(void);