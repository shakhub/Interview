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
	Node<T>(const T value)
		:next(NULL),data(value)
	{}
	Node<T>(const T value,Node *next)
		:next(next),data(value)
	{}
	T getData(void) { return data;}		
	Node<T>* getNext(void) { return next;}	
	void setData(const T value) {data = value;}
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
	T search(const T value); // returns the location of the value if found
	void deleteList();
	void push(const T value);
	void push(const T value,Node<T> *node);// push after given node
	void push_at_tail(const T value);
	T pop();
	T pop_tail();
	T get_node_at_loc(const unsigned int location);
	void delete_node(const T value);
	void rotate_list(int k);
	void sort();
	void print_list();

	void reverse();// reverse the linked list

};

void runLinkedList(void);
void tempFunct();

#endif// __LINKEDLIST_H