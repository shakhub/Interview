#include<iostream>
#include"hashtable.h"
#include"linkedlist.hpp"

using namespace std;
#define HASHTABLE
#define HASHTABLE_SIZE 100
LinkedList list1;
LinkedList list2;
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
	unsigned int cnt1 = head1->length(), cnt2 = head2->length();
	LinkedList unionList; // use getLength from linkedlist

	while (cnt1>0){
		unionList.push_at_tail(head1->get_node_at_loc(cnt1));
		cnt1--;
	}
	while (cnt2>0)
	{
		int data = head2->get_node_at_loc(cnt2);
		if (!h->isPresent(data))
			unionList.push_at_tail(data);
		cnt2--;
	}
	cout << "Union of the lists "<<endl;
	unionList.print_list();
	cout<<endl;
}
static void findIntersection(LinkedList *head1,LinkedList *head2,HashTable *h)
{
	LinkedList interList;
	unsigned int cnt = head2->length();
	while (cnt>0)
	{
		int data = head2->get_node_at_loc(cnt);
		if (h->isPresent(data))
			interList.push(data);
		cnt--;
	}
	cout << "Intersection of the lists "<<endl;
	interList.print_list();
	cout<<endl;
}
static void uiLinkedList(void)
{
	//Given two linked lists, create union and intersection lists
	// that contain union and intersection fo the elements in the
	// given lists. Order of elements in output doesn't matter.
	
	HashTable h(HASHTABLE_SIZE);
	list1.push(10);
	list1.push(15);
	list1.push(4);
	list1.push(20);

	list2.push(8);
	list2.push(4);
	list2.push(2);
	list2.push(10);

	h.hash();
	h.setSize(10); //  set the table size more than the number of data in the table
	cout << "List 1 : ";
	list1.print_list();
	cout<<endl;
	cout << "List 2 : ";
	list2.print_list();
	cout<<endl;

	findUnion(&list1, &list2, &h);
	findIntersection(&list1, &list2, &h);

}
void runHashFunct()
{
	//subsetArray();//Find if an array is subset of another array
	uiLinkedList();// union and interserction of LL
}