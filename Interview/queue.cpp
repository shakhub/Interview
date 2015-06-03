#include<stdio.h>
#include<stdlib.h>
#include"queue.hpp"

/*Queue using arrays*/

//create a queue
Queue *createQueue(int capacity)
{
	Queue *queue = (Queue*)malloc(sizeof(Queue));

	queue->capacity = capacity;
	queue->front = queue->rear = -1;
	queue->size = 0;
	queue->array = (int*)malloc(capacity*sizeof(int));
	
	return queue;
}
int isEmptyQueue(Queue *queue)
{
	return (queue->size == 0);
}
int isFullQueue(Queue *queue)
{
	return (queue->size == queue->capacity);
}
void enqueue(Queue *queue, int data)
{
	// to add an element into a queue
	if (isFullQueue(queue)) return;
	queue->front = (queue->front == -1) ? 0 : queue->front;
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = data;
	queue->size = queue->size + 1;

}
void insertFrontQueue(Queue *queue, int data)
{
	// this is for double ended queue (dequeue)
	if(isFullQueue(queue)) return;
	queue->front = (queue->front == -1) ? 0 : queue->front;
	queue->front = (queue->front - 1) % queue->capacity;
	queue->array[queue->front] = data;
	queue->size = queue->size + 1;

}
int dequeue(Queue *queue)
{
	// to remove an element from the queue
	int data;
	if (isEmptyQueue(queue)) return ERROR_QUEUE_EMPTY;
	data = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size = queue->size - 1;

	return data;
}
int removeRearQueue(Queue *queue)
{
	// this is for double ended queue
	int data;
	if (isEmptyQueue(queue)) return ERROR_QUEUE_EMPTY;
	data = queue->array[queue->rear];
	queue->rear = (queue->rear - 1) % queue->capacity;
	queue->size = queue->size - 1;

	return data;
}
/*Queue using linked list*/

Qnode *createQNode(int data)
{
	//create a node for the queue 

	Qnode *qnode = (Qnode*)malloc(sizeof(Qnode));
	qnode->data = data;
	qnode->next = NULL;

	return qnode;
}
QueueLL *createQueueLL(void)
{
	//create a queue
	QueueLL *queue = (QueueLL*)malloc(sizeof(QueueLL));
	queue->front = queue->rear = NULL;

	return queue;
}
void enqueueLL(QueueLL *queue, int data)
{
	// to add an element into the queue
	// This adds the new node at the end of the list.
	Qnode *qnode = createQNode(data);
	if (queue->rear == NULL)
	{
		queue->front = queue->rear = qnode;
		return;
	}
	queue->rear->next = qnode;
	queue->rear = qnode; // replace the new node as the rear node in thw queue
}
void insertFrontQueueLL(QueueLL *queue, int data)
{
	// this is for the double ended queue 
	// This adds the new node at the front of the queue.
	Qnode *qnode = createQNode(data);
	if (queue->front == NULL)
	{
		queue->front = queue->rear = qnode;
		return;
	}

	queue->front->next = qnode;
	queue->front = qnode;
}
Qnode *dequeueLL(QueueLL *queue)
{
	// to remove an element from the queue
	// This removes the node at the head, ie at the front of the queue.
	Qnode *temp;

	if (queue == NULL) return NULL;
	temp = queue->front;
	queue->front = queue->front->next;

	if (queue->front == NULL)
		queue->rear = NULL;

	return temp;
}
/*
Qnode *removeRearQueueLL(QueueLL *queue)
{
	// this is for the double ended queue
	// this removes the node at the end of the list , ie at the rear of the queue
	
}
*/
void runqueue(void)
{
	int i = 0;
	Queue *q = createQueue(6);
	enqueue(q, 3);
	enqueue(q, 4);
	enqueue(q, 5);
	enqueue(q, 6);
	enqueue(q, 7);
	printf("%d\n", removeRearQueue(q));
	printf("%d\n", removeRearQueue(q));
	insertFrontQueue(q, 20);
	printf("%d\n", dequeue(q));
}