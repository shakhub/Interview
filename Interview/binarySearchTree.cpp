#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include "binarySearchTree.hpp"
#include "queue.hpp"
#include "stacks.hpp"
#include "linkedlist.hpp"

#define MAXROOT(x,y) ((x)>(y)?(x):(y))
using namespace std;
int isbst = 1;
node *createNode(int data)
{
	node *newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
void insertNode(node **root, int data)
{
	/*This is to create a BST not a general binary tree*/
	if (*root == NULL)
	{
		*root = createNode(data);
		return;
	}
	if (data <= (*root)->data)
	{
		insertNode(&((*root)->left), data);
	}
	else
	{
		insertNode(&((*root)->right), data);
	}
}
int searchBinaryTree(node **root, int data)
{
	if (*root == NULL) return 0;
	if ((*root)->data == data) return 1;
	if (data <= (*root)->data)
	{
		return searchBinaryTree(&((*root)->left), data);
	}
	else
	{
		return searchBinaryTree(&((*root)->right), data);
	}
}
node *searchNode(node **rootPtr, int data)
{
	//returns the found node
	if (*rootPtr == NULL) return NULL;
	if ((*rootPtr)->data == data) return *rootPtr;
	if (data <= (*rootPtr)->data)
	{
		return searchNode(&((*rootPtr)->left), data);
	}
	else
	{
		return searchNode(&((*rootPtr)->right), data);
	}

}
int findMAX(node **rootPtr)
{
	// This function is only good on BST
	if (*rootPtr == NULL) return -1;
	if ((*rootPtr)->right == NULL) return (*rootPtr)->data;
	return findMAX(&(*rootPtr)->right);

}
node *findMIN(node **rootPtr)
{
	//This function is only good on BST
	
	while ((*rootPtr)->left != NULL)
		(*rootPtr) = (*rootPtr)->left;

	return (*rootPtr);

}
int findHeight(node **rootPtr)
{
	if (*rootPtr == NULL) return -1;
	return MAXROOT(findHeight(&((*rootPtr)->left)), findHeight(&((*rootPtr)->right))) + 1;
}
void breathFirstSeachTravel(node **rootPtr)
{
	QueueLL *q = createQueueLL();
	if (*rootPtr == NULL) return;
	enqueueLL(q, (int)(*rootPtr));
	while (q->front != NULL && q->rear != NULL)
	{
		node *current = (node*) (dequeueLL(q)->data); // store the address of the dequeued node 
		printf("%d\n",current->data);
		if (current->left !=NULL) enqueueLL(q, (int)(current)->left); // enqueue the address of the left child
		if (current->right != NULL) enqueueLL(q, (int)(current)->right); // enqueue the address of the right child

	}	
	
}
void bfsSpiralTravel(node *rootPtr)
{
		
	// try to implement using double ended queues
	// this algorithm uses two stacks in an iterative approach
	// one stack is used for left to right printing and the other for right to left
	Stack *s1, *s2;

	s1 = createStack(10);
	s2 = createStack(10);

	pushToStack(s1, (int)rootPtr);

	while (!isStackEmpty(s1) || !isStackEmpty(s2))
	{
		while (!isStackEmpty(s1))
		{
			node * current = (node*)popFromStack(s1);
			printf("%d ", current->data);
			if (current->right != NULL) pushToStack(s2, (int)current->right);
			if (current->left != NULL) pushToStack(s2, (int)current->left);
		}
		while (!isStackEmpty(s2))
		{
			node * current = (node*)popFromStack(s2);
			printf("%d ", current->data);
			if (current->left != NULL) pushToStack(s1, (int)current->left);
			if (current->right != NULL) pushToStack(s1, (int)current->right);
		}
	}

}
void dfsPreorder(node **rootPtr)
{
	// Order of traversal <root><left><right>
	if (*rootPtr == NULL) return;
	printf("%d\n", (*rootPtr)->data);
	if ((*rootPtr)->left != NULL) dfsPreorder(&(*rootPtr)->left);
	if ((*rootPtr)->right != NULL) dfsPreorder(&(*rootPtr)->right);
}
void dfsInorder(node **rootPtr)
{
	// Order of traversal <left><root><right>
	if (*rootPtr == NULL) return;
	if ((*rootPtr)->left != NULL) dfsInorder(&(*rootPtr)->left);
	printf("%d ", (*rootPtr)->data);
	if ((*rootPtr)->right != NULL) dfsInorder(&(*rootPtr)->right);
}
void dfsInorderIterative(node *rootPtr)
{
	Stack *stack = createStack(20);
	node *current = rootPtr;
	int done = 0;
	if (current == NULL) return;

	while (!done)
	{
		if (current != NULL)
		{
			pushToStack(stack, (int)current);
			current = current->left;
		}

		else
		{
			if (!isStackEmpty(stack))
			{
				current = (node *)popFromStack(stack);
				printf("%d ", current->data);
				current = current->right;

			}
			else
				done = 1;
		}
	}

}
void isBST(node **rootPtr)
{
	// Order of traversal <left><root><right>
	// using inorder traversal to check if tree is bst
	//inorder traversal will give an sorted output
	static int data=0;
	if (*rootPtr == NULL) return ;
	if ((*rootPtr)->left != NULL) isBST(&(*rootPtr)->left);
	if (data > (*rootPtr)->data)
	{
		isbst = 0;
		return;
	}
	data =  (*rootPtr)->data;
	if ((*rootPtr)->right != NULL) isBST(&(*rootPtr)->right);
}
void dfsPostorder(node **rootPtr)
{
	// Order of traversal <left><root><right>
	if (*rootPtr == NULL) return;
	if ((*rootPtr)->left != NULL) dfsPostorder(&(*rootPtr)->left);
	if ((*rootPtr)->right != NULL) dfsPostorder(&(*rootPtr)->right);
	printf("%d\n", (*rootPtr)->data);
}
/*
node * deleteNodeTree(node **rootPtr, int data)
{	
	if (*rootPtr == NULL) return *rootPtr;
	else if (data < (*rootPtr)->data) (*rootPtr)->left = deleteNodeTree(&((*rootPtr)->left), data);
	else if (data > (*rootPtr)->data) (*rootPtr)->right = deleteNodeTree(&((*rootPtr)->right), data);
	else
	{
		//case 1 - leaf node
		if ((*rootPtr)->left == NULL && (*rootPtr)->right == NULL)
		{
			free((*rootPtr));
			(*rootPtr) = NULL;
			
		}
		//case 2 - one child is present
		else if ((*rootPtr)->left != NULL && (*rootPtr)->right == NULL)
		{
			node *temp = (*rootPtr);
			(*rootPtr) = (*rootPtr)->left;
			free(temp);
			
		}
		else if ((*rootPtr)->right != NULL && (*rootPtr)->left == NULL)
		{
			node *temp = (*rootPtr);
			(*rootPtr) = (*rootPtr)->right;
			free(temp);
		}
		else
		{
			//case 3 - both child present
			node *temp = findMIN(&((*rootPtr)->right));
			(*rootPtr)->data = temp->data;
			(*rootPtr)->right = deleteNodeTree((*rootPtr)->right, (*rootPtr)->data);
			
		}
	}
	return (*rootPtr);
	
}
*/
void mirrorTree(node *rootPtr)
{
	if (rootPtr == NULL) return;
	else
	{
		mirrorTree(rootPtr->left);
		mirrorTree(rootPtr->right);
		
		node *temp = NULL;
		temp = rootPtr->left;
		rootPtr->left = rootPtr->right;
		rootPtr->right = temp;
	}
}
void printRootToLeaf(node *rootPtr, LinkedList *list)
{
	/*This function prints all the nodes from
	root to leaf for all the paths in one line per path
	This algorithm uses linkedlist */
	int i = 0;
	if (rootPtr == NULL) return;
	if (rootPtr->left == NULL && rootPtr->right == NULL)
	{
		/*
		pushToLinkList(&(list), rootPtr->data);//O(1)
		printList(&(list));//O(n)
		popLinkList(&(list));//O(1)
		*/
		list->push(rootPtr->data);
		list->print_list();
		list->pop();
		
		printf("\n");
		return;

	}
	else
	{
		//pushToLinkList(&(list), rootPtr->data);//O(1)
		list->push(rootPtr->data);
		printRootToLeaf(rootPtr->left, (list));
		printRootToLeaf(rootPtr->right,(list));
		list->pop();
	}
}
int isChildrenSumProperty(node *rootPtr)
{
	/* Use this as the input to check the algorithm
	root = createNode(10);
	root->left = createNode(8);
	root->right = createNode(2);
	root->left->left = createNode(3);
	root->left->right = createNode(5);
	root->right->right = createNode(2);
	*/
	int left, right;
	if (rootPtr == NULL || (rootPtr->left == NULL && rootPtr->right == NULL))
		return 1;
	left = (rootPtr->left == NULL) ? 0 : rootPtr->left->data;
	right = (rootPtr->right == NULL) ? 0 : rootPtr->right->data;

	if (rootPtr->data == (left + right) && (isChildrenSumProperty(rootPtr->left) && (isChildrenSumProperty(rootPtr->right))))
		return 1;
	else
		return 0;
}
void incrementHelperFunction(node *rootPtr, int data)
{
	if (rootPtr->left != NULL)
	{
		rootPtr->left->data = rootPtr->left->data + data;
		incrementHelperFunction(rootPtr->left, data);
	}

	if (rootPtr->right != NULL)
	{
		rootPtr->right->data = rootPtr->right->data + data;
		incrementHelperFunction(rootPtr->right, data);
	}
}
void convertTreetoChildSumProp(node *rootPtr)
{
	/*This converts the existing tree to one which conforms 
	with the child sum property
	*/
	int left, right,diff;
	if (rootPtr == NULL || (rootPtr->left &&
		rootPtr->right == NULL)) 
		return;
	convertTreetoChildSumProp(rootPtr->left);
	convertTreetoChildSumProp(rootPtr->right);

	left = (rootPtr->left == NULL) ? (0) : (rootPtr->left->data);
	right = (rootPtr->right == NULL) ? (0) : (rootPtr->right->data);

	diff = rootPtr->data - (left + right);

	if (diff < 0)
		rootPtr->data = rootPtr->data - diff;
	if (diff > 0)
	{
		// Change one of the child to make 
		// hold of the property. Also need to make
		// sure that the subtree also holds this property
		incrementHelperFunction(rootPtr, diff);

	}


}
void runBinaryTree(void)
{
	QueueLL *q = createQueueLL();
	LinkedList list;
	//LinkedList *list = createList(0);
	node *root;
	root = NULL;
	//                                          6  
	//                                         / \
	//                                        /   \
	//                                       /     \
	//                                      /       \ 
	//                                     4         10         
	//                                    / \       /  \
	//                                   /   \     /    \       
	//                                  2     5   7     11
	//                                 / \         \
	//                                /   \         \
	//                               1     3         9  
	//                                              /
	//                                             /
	//                                            8     
	//                                                        
	//
	
	insertNode(&root, 6);
	insertNode(&root, 4);
	insertNode(&root, 10);
	insertNode(&root, 2);
	insertNode(&root, 5);
	insertNode(&root, 7);
	insertNode(&root, 11);
	insertNode(&root, 1);
	insertNode(&root, 3);
	insertNode(&root, 9);
	insertNode(&root, 8);

	dfsInorder(&root);	
	cout << endl;
	printRootToLeaf(root, &list);

	
}


