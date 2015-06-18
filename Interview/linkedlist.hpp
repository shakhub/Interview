#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

//forward declaration
template<class T> class LinkedList;

template <class T>
class Node
{
	friend class LinkedList<T>;
private:
	T data;
	Node<T> *next;
public:
	//constructor
	Node<T>(void)
		:next(NULL)
	{}
	//constructor with argument
	Node<T>(T value)
		:next(NULL),data(value)
	{}
	Node<T>(T value,Node *next)
		:next(next),data(value)
	{}
	T getData(void) { return data;}		
	Node<T>* getNext(void) { return next;}		
};

template <class T>
class LinkedList
{
private:
	Node<T> *head;
	Node<T> *tail;
public:
	LinkedList (); //constructor
	LinkedList (T value);//constructor
	~LinkedList(void);//distructor

	Node<T> * gethead(void) {return head;}

	bool isEmpty()
	{
		if(head == NULL) 
		{
			return true;
		}
		return false;
	}
	unsigned int length();
	T search(T value); // returns the location of the value if found
	void deleteList();
	void push(T value);
	void push(T value,Node<T> *node);// push after given node
	void push_at_tail(T value);
	T pop();
	T pop_tail();
	T get_node_at_loc(unsigned int location);
	void delete_node(T value);
	void rotate_list(int k);
	void print_list();

	void reverse();// reverse the linked list

};

void runLinkedList(void);
void tempFunct();

#endif// __LINKEDLIST_H