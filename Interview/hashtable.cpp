#include<iostream>
#include"hashtable.h"
#include"linkedlist.hpp"

using namespace std;
#define HASHTABLE
#define HASHTABLE_SIZE 100
LinkedList list1(10);
LinkedList list2(8);
HashTable::HashTable(int arrSize)
{
	//constructor
	size = arrSize;
	table = new int[size];
	fill(table,table+size,0);

}
void HashTable::hash(int *array,int size)
{
	//build the table using the hash function below
	// The value is the location <-- one to one mapping
	for(int i=0;i<size;i++)
	{
		int key = array[i];
		if(table[key]==0)
		{
			//check if the location is used or not
			table[key] = key;
		}
		else
		{
			cout<<"Collision has occured"<<endl;
		}
	}

}
void HashTable::hash()
{
	int cnt = list1.length();
	while(cnt)
	{
		int key = list1.get_node_at_loc(cnt);
		if(table[key]==0)
		{
			//check if the location is used or not
			table[key] = key;
		}
		else
		{
			cout<<"Collision has occured"<<endl;
		}
		cnt--;
	}
}
bool HashTable::isPresent(int key)
{
	return table[key] == key;
}
int HashTable::hashValue(int key)
{
	return key;
}
void subsetArray(void)
{
	const int sizeArr1 = 6;
	const int sizeArr2 = 4;
	int a[sizeArr1] = {10, 5, 2, 23, 19};
	int b[sizeArr2] = {19, 5, 3};
	unsigned count=0;

	HashTable h(HASHTABLE_SIZE);
	h.hash(a,sizeArr1);
	for(int i=0;i<sizeArr2;i++)
		if(h.isPresent(b[i]))
			count++;
	if(count==sizeArr2)
		cout<<"Array is a subset of this array"<<endl;
	else
		cout<<"Not a subset"<<endl;
}
static void findUnion(LinkedList *head1,LinkedList *head2,HashTable *h)
{
	/*
	LinkedList *list1 = *head1;
	LinkedList *list2 = *head2;
	LinkedList *unionList = createList(NULL); // use getLength from linkedlist

	while(list1!=NULL){
		pushToLinkList(&unionList,list1->data);
		list1=list1->next;
	}
	while(list2!=NULL)
	{
		int data = list2->data;
		if(!h->isPresent(data))
			pushToLinkList(&unionList,data);
		list2=list2->next;
	}
	printList(&unionList);
	*/
	int cnt1 = head1->length(), cnt2 = head2->length();
	LinkedList unionList(0); // use getLength from linkedlist

	while (cnt1){
		unionList.push_at_tail(head1->get_node_at_loc(cnt1));
		cnt1--;
	}
	while (cnt2)
	{
		int data = head2->get_node_at_loc(cnt2);
		if (!h->isPresent(data))
			unionList.push_at_tail(data);
		cnt2--;
	}
	unionList.print_list();


}
static void findIntersection(LinkedList *head1,LinkedList *head2,HashTable *h)
{
	/*
	LinkedList *list1 = *head1;
	LinkedList *list2 = *head2;
	LinkedList *interList = createList(NULL); // use getLength from linkedlist

	while(list2!=NULL)
	{
		int data = list2->data;
		if(h->isPresent(data))
			pushToLinkList(&interList,data);
		list2=list2->next;
	}
	printList(&interList);
	*/
	LinkedList interList(0);
	int cnt = head2->length();
	while (cnt)
	{
		int data = head2->get_node_at_loc(cnt);
		if (h->isPresent(data))
			interList.push(data);
		cnt--;
	}
	interList.print_list();
}
static void uiLinkedList(void)
{
	//Given two linked lists, create union and intersection lists
	// that contain union and intersection fo the elements in the
	// given lists. Order of elements in output doesn't matter.
	
	//list1 = createList(10);
	//list2 = createList(8);

	HashTable h(HASHTABLE_SIZE);
	/*
	pushToLinkList(&list1, 15);
	pushToLinkList(&list1, 4);
	pushToLinkList(&list1, 20);

	pushToLinkList(&list2, 4);
	pushToLinkList(&list2, 2);
	pushToLinkList(&list2, 10);
	*/
	list1.push(15);
	list1.push(4);
	list1.push(20);

	list2.push(4);
	list2.push(2);
	list2.push(10);

	h.hash();
	h.setSize(4);
	//findUnion(&list1,&list2,&h);
	//findIntersection(&list1,&list2,&h);
	findUnion(&list1, &list2, &h);
	findIntersection(&list1, &list2, &h);

}
void runHashFunct()
{
	//subsetArray();//Find if an array is subset of another array
	uiLinkedList();// union and interserction of LL
}