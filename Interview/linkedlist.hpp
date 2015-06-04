
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
void runLinkedList(void);


/*
class LinkedList
{
	LinkedList *next;
	int data;
public:
	LinkedList (); //constructor
	LinkedList (int value =0):next(NULL),data(value){}; //constructor
	LinkedList * createNode(int data);
	void push(int data);
	void push(LinkedList *node);
	void push_at_end(int data);
	int pop();
	int pop_at_end();
	void delete_node(int data);
	void print_list();


};
*/