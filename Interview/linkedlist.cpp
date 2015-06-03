#include<stdlib.h>
#include<stdio.h>
#include"linkedlist.hpp"

LinkedList *createList(int data)
{
	LinkedList *head = (LinkedList *)malloc(sizeof(LinkedList));
	head->data = data;
	head->next = NULL;
	return head;
}
void pushToLinkList(LinkedList **node, int data)
{
	//add a node to the head of a linked list
	LinkedList *newNode = createList(data);
	newNode->next = *node; // new node will point to where the head used to point
	*node = newNode;//move the head to point to the new node
}
void pushToLinkListAt(LinkedList *prev_node, int data)
{
	//add a node after a given node

	LinkedList *newNode = createList(data);
	newNode->next = prev_node->next; // new node will point to where the prev node used to point
	prev_node->next = newNode;
}
void pushToLinkListAtEnd(LinkedList **node, int data)
{
	//add a node at the end of the linked list
	LinkedList *newNode = createList(data);
	LinkedList *lastNode = *node;

	if (*node == NULL)
	{
		*node = newNode;
		return;
	}
	while (lastNode->next != NULL)
	{
		lastNode = lastNode->next;
	}
	lastNode->next = newNode;

}
int popLinkList(LinkedList **node)
{
	//remove the node at the head
	int popVal;
	LinkedList *firstNode = *node;
	if (*node == NULL) return -1;
	popVal = (firstNode)->data;
	*node = firstNode->next;
	free(firstNode);
	return popVal;
}
int removeLastNodeLinkList(LinkedList **node)
{
	// remove the last node in the linked list
	LinkedList *curr = *node;
	LinkedList *temp;
	int popVal;

	if (curr == NULL) return -1;
	while ((curr->next->next) != NULL)
	{
		curr = curr->next;
	}
	temp = curr->next;
	popVal = temp->data;
	curr->next = curr->next->next;
	free(temp);
	return popVal;
}
void deleteNode(LinkedList **node, int data)
{
	//delete a node with the specified data 
	LinkedList *currNode = *node;
	LinkedList *prevNode = NULL;

	if (*node == NULL) return;
	if ((*node)->data == data && (*node) != NULL)
	{
		*node = currNode->next;
		free(currNode);
		return;
	}
	while (currNode->data != data && currNode!=NULL)
	{
		prevNode = currNode;
		currNode = currNode->next;
	}
	if (currNode == NULL) return;
	prevNode->next = currNode->next;
	free(currNode);
}
void printList(LinkedList **node)
{
	LinkedList *currNode = *node;
	if (currNode == NULL) return;
	printf("\n");
	while (currNode != NULL)
	{
		printf("%d ", currNode->data);
		currNode = currNode->next;
	}
	printf("\n");
}

void runLinkedList(void)
{
	LinkedList *list = createList(6);
	pushToLinkList(&list,10);
	pushToLinkList(&list, 13);
	pushToLinkList(&list, 3);
	pushToLinkList(&list, 5);
	pushToLinkList(&list, 9);
	printList(&list);
}