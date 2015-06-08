#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include"linkedlist.hpp"
using namespace std;

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
	//cout << "List deleted"<<endl;
}
void LinkedList::push(int value)
{
	//add a node to the head of a linked list
	if (head == NULL)
	{
		tail = head = new Node(value);
		return;
	}

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
	{
		tail = head = new Node(value);
		return;
	}

	tail->next = new Node(value);
	tail = tail->next;
	
}
unsigned int LinkedList::length()
{
	if(isEmpty()) {cout << " Empty list "<<endl;return 0;}
	Node *curr = head;
	unsigned int len=0;
	while(curr!= NULL)
	{
		curr = curr->next;
		len++;		
	}
	//cout << "Length of list : "<<len<<endl;
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
int LinkedList::get_node_at_loc(unsigned int idx)
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
	if (curr == NULL)
	{
		return -1;
	}
	
	//cout << "Data at location "<<idx<<": "<<curr->data<<endl;
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
	//LinkedList list(24);
	LinkedList list;
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
