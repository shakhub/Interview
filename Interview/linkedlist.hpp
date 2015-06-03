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