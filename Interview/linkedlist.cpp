#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include"linkedlist.hpp"
using namespace std;

#if 0
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
#else // c++ code

LinkedList::LinkedList()
{
	//constructor
	head = tail = NULL;
}
LinkedList::LinkedList(int value)
{
	//constructor
	head = new Node(value);
	tail = head;
}
LinkedList::~LinkedList()
{
	deleteList();
}
void LinkedList::deleteList()
{
	if(isEmpty()) {cout<< "Empty list: Nothing to delete"<<endl; return;}
	Node *curr = head;
	Node *temp;

	while(curr!=NULL)
	{
		temp = curr;
		curr = curr->next;
		delete temp;
	}
	head = tail = NULL;
	cout << "List deleted"<<endl;
}
void LinkedList::push(int value)
{
	//add a node to the head of a linked list
	if (head == NULL)
		tail = head = new Node(value);

	Node * newNode = new Node(value);
	newNode->next = head;
	head = newNode; //update the head node

}
void LinkedList::push(Node *node,int value)
{
	//push after given node with the given data
	if(node!=NULL)
		node->next = new Node(value,node->next);

}
void LinkedList::push_at_tail(int value)
{
	if(head == NULL)
		tail = head = new Node();

	tail->next = new Node(value);
	tail = tail->next;
	
}
int LinkedList::length()
{
	if(isEmpty()) {cout << " Empty list "<<endl;return 0;}
	Node *curr = head;
	int len=0;
	while(curr!= NULL)
	{
		curr = curr->next;
		len++;		
	}
	cout << "Length of list : "<<len<<endl;
	return len;
}
int LinkedList::search(int value)
{
	if(isEmpty()){cout << " Empty list "<<endl; return -1;}
	Node *curr = head;
	int loc=1;
	while(curr!=NULL)
	{
		if(curr->data == value)
		{
			cout<< "Data "<<value<<" found at location :"<<loc<<endl;
			return loc;
		}
		loc++;
		curr = curr->next;
	}
	cout<< "Data "<< value<<" not found in the list"<<endl;
	return -1;

}
int LinkedList::pop()
{
	//removes node at the head;
	int data;
	if(isEmpty()){cout << "Cannot pop : Empty list"<<endl; return -1;}
	
	if(tail == head) // only one node in the list
	{

	}
	Node *temp = head;
	data = temp->data;
	head = head->next;
	delete temp;
	return data;

}
int LinkedList::pop_tail()
{
	//removes node at the tail;
	Node *prev=NULL,*curr=NULL;
	int data;
	if(isEmpty()){cout << "Cannot pop : Empty list"<<endl; return -1;}
	if(tail == head) // only one node in the list
	{

	}
	curr = head;
	while(curr->next!=NULL)
	{
		prev = curr;
		curr= curr->next;
	}
	prev->next = NULL;
	tail = prev;
	data = curr->data;
	delete curr;
	return data;
}
int LinkedList::get_node_at_loc(int idx)
{
	// gets the data stored at location idx from the head
	if(isEmpty()){cout << "Empty list: Nothing to get."<<endl; return -1;}
	
	if(idx > length())
	{
		cout<<"Invalid index: List is smaller than the index"<<endl;
		return -1;
	}

	Node *curr = head;
	int count=1;
	while(count!=idx && curr!=NULL)
	{
		curr = curr->next;
		count++;
	}
	
	cout << "Data at location "<<idx<<": "<<curr->data<<endl;
	return curr->data;
}
void LinkedList::delete_node(int value)
{
	Node *prev=NULL,*temp=NULL;
	if(head->data == value)
	{
		temp = head;
		head = head->next;
		delete temp;
		return;
	}
	prev = head;
	temp = head->next;
	while(temp!=NULL)
	{
		if(temp->data == value)
		{
			prev->next = temp->next;
			if(temp == tail)
			{
				tail = prev;
			}
			delete temp;
			break;
		}
		prev = temp;
		temp = temp->next;
	}

}
void LinkedList::print_list()
{
	Node *curr = head;

	if(isEmpty()){cout << "Empty list"<<endl; return;}
	while(curr!=NULL)
	{
		cout<< curr->data<<" ";
		curr=curr->next;
	}
	cout<<endl;
}
void LinkedList::reverse()
{
	if(head == NULL)
	{
		cout << "Empty list : Cannot reverse"<<endl;
		return;
	}
	Node *curr,*next,*prev = NULL;

	curr = head;
	tail = curr;
	if(curr == NULL) return;
	while(curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
	tail->next = NULL; //  not necessary just for safety
	cout << "Reverse list " << endl;

}
void LinkedList::rotate_list(int k)
{
	/*
	Rotate the link list counter-clock wise by k times.
	Eg: 10->4->34->5->36->9 rotated by 3 should be
	    5->36->9->10->4->34
		For this we need to store (k+1)th node, last node and kth node
	*/
	if (isEmpty()) { cout << "Empty list: Nothing to rotate" << endl; return; }
	k %= length(); // make sure that k is less than the length of the list
	int count = 1;
	Node *curr = head;
	
	while (count != k && curr!=NULL)
	{
		count++;
		curr = curr->next;
	}
	

	tail->next = head;
	head = curr->next;
	tail = curr;
	tail->next = NULL;

	cout << "List rotate counter-clock wise by " << k << endl;
	
}
void runLinkedList()
{
	LinkedList list(24);
	list.push(9);
	list.push(36);
	list.push(5);
	list.push(34);
	list.push(4);
	list.push(10);

	list.print_list();	
	list.rotate_list(10);
	list.print_list();
	list.reverse();
	list.print_list();
	
}
#endif