#if 0
typedef struct LinkedList
{
	int data;
	struct LinkedList *next;
}LinkedList;

LinkedList *createList(int );
void pushToLinkList(LinkedList **, int );
void pushToLinkListAt(LinkedList *, int );
void pushToLinkListAtEnd(LinkedList **, int );
int popLinkList(LinkedList **);
int removeLastNodeLinkList(LinkedList **);
void deleteNode(LinkedList **, int );
void printList(LinkedList **);

#else
class Node
{
	friend class LinkedList;
private:
	int data;
	Node *next;
public:
	//constructor
	Node(void)
		:next(NULL)
	{}
	//constructor with argument
	Node(int value)
		:next(NULL),data(value)
	{}
	Node(int value,Node *next)
		:next(next),data(value)
	{}
	int getData(void) { return data;}		
	Node* getNext(void) { return next;}		
};

class LinkedList
{
private:
	Node *head;
	Node *tail;
public:
	LinkedList (void); //constructor
	LinkedList (int value);//constructor
	~LinkedList(void);//distructor
	bool isEmpty()
	{
		if(head == NULL) 
		{
			return true;
		}
		return false;
	}
	unsigned int length();
	int search(int value); // returns the location of the value if found
	void deleteList();
	void push(int value);
	void push(Node *node,int value);// push after given node
	void push_at_tail(int value);
	int pop();
	int pop_tail();
	int get_node_at_loc(int location);
	void delete_node(int value);
	void rotate_list(int k);
	void print_list();

	void reverse();// reverse the linked list

};
#endif
void runLinkedList(void);
