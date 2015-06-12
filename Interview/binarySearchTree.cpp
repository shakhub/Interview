#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <string>
#include "binarySearchTree.hpp"
#include "queue.hpp"
#include "stacks.hpp"
#include "linkedlist.hpp"

#define __BINARYSEARCHTREE

#define MAXROOT(x,y) ((x)>(y)?(x):(y))
using namespace std;

#if 0
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
	Queue q(100);
	if(*rootPtr == NULL) return;
	q.enqueue((int)(*rootPtr));
	while(!q.isEmpty())
	{
		node *current = (node*) (q.dequeue()); // store the address of the dequeued node 
		cout<< current->data << " ";
		if (current->left !=NULL) q.enqueue( (int)(current)->left); // enqueue the address of the left child
		if (current->right != NULL) q.enqueue((int)(current)->right); // enqueue the address of the right child
		
	}
}
void bfsSpiralTravel(node *rootPtr)
{
		
	// try to implement using double ended queues
	// this algorithm uses two stacks in an iterative approach
	// one stack is used for left to right printing and the other for right to left
	
	Stack s1(10),s2(10);
	s1.push((int)rootPtr);
	while (!s1.isEmpty() || !s2.isEmpty())
	{
		while (!s1.isEmpty())
		{
			node * current = (node*)s1.pop();
			printf("%d ", current->data);
			if (current->right != NULL) s2.push((int)current->right);
			if (current->left != NULL) s2.push((int)current->left);
		}
		while (!s2.isEmpty())
		{
			node * current = (node*)s2.pop();
			printf("%d ", current->data);
			if (current->left != NULL) s1.push( (int)current->left);
			if (current->right != NULL) s1.push((int)current->right);
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
	Stack stack(20);
	node *current = rootPtr;
	int done = 0;
	if (current == NULL) return;

	while (!done)
	{
		if (current != NULL)
		{
			stack.push((int)current);
			current = current->left;
		}

		else
		{
			if (!stack.isEmpty())
			{
				current = (node *)stack.pop();
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
#else
BinaryTree::BinaryTree()
{
	root = NULL;
}
BinaryTree::BinaryTree(int data)
{
	root = new NodeTree(data);
}
/*
BinaryTree::~BinaryTree()
{
	deleteTree();
}
*/
bool BinaryTree::isBST(NodeTree *node)
{
	// Order of traversal <left><root><right>
	// using inorder traversal to check if tree is bst
	//inorder traversal will give an sorted output
	static int data = 0;
	if (node == NULL)
		return true;
	if(node->left!=NULL) isBST(node->left);
	if(data > node->data)
		return false;
	data = node->data;	
	if(node->right!=NULL) isBST(node->right);

}
/*
void BinaryTree::deleteTree()
{

}
*/
void BinaryTree::insert(int data)
{
	/*
	insert method creates a BST and not a general binary tree.
	*/
	if(root == NULL)
	{
		root = new NodeTree(data);
		return;
	}
	NodeTree *node = root;
	
	while(node!=NULL)
	{
		if(data <= node->data)
		{
			if(node->left!=NULL)
				node = node->left;
			else
			{
				node->left = new NodeTree(data);
				return;
			}
		}
		else
		{
			if(node->right!=NULL)
				node = node->right;
			else
			{
				node->right = new NodeTree(data);
				return;
			}
		}
	}
	

}
NodeTree* BinaryTree::get_inorder_successor(int data)
{
	NodeTree *curr = search_node(data);

	if (curr == NULL) return NULL;
	if (data == max())
	{
		cout << "No successor for this node : Max node in tree"<<endl;
		return curr;
	}
	//case 1: node has right sub tree
	if(curr->right != NULL)
	{
		//find the max node in the right sub tree, which will be the 
		// inorder successor
		NodeTree * temp = curr->right;
		while(temp->left!=NULL)
			temp = temp->left;
		return temp;
	}
	//case 2: node has no right sub tree
	if (curr->right == NULL)
	{
		//Find the nearest parent, of whose the given node
		// is in its left sub tree.
		NodeTree *parent = root;
		NodeTree *successor = NULL;

		while(parent!=curr)
		{
			if(data < parent->data)
			{
				successor = parent;
				parent = parent->left;
			}
			else
			{
				parent = parent ->right;
			}
		}
		return successor;
	}
	return NULL;
}
/*
int BinaryTree::delete_node(int data)
{
	
	3 cases arise when deleting a node :
	  1. has no child   - simply delete the node 
	  2. has 1 child    - replace the current node with the child and delete the node
	  3. has 2 children - find the inorder successor and replace it. Delete the node
	
	NodeTree * curr = search_node(data);
	int ret;
	//has no child
	if(leaf(curr))
	{
		ret = curr->data;
		delete curr;
		curr = NULL;
		return ret;
	}
	//has one child
	if(curr->left == NULL)
	{
		ret = curr->right->data;
		delete curr;
		return ret;
	}
	if(curr->right == NULL)
	{
		ret = curr->left->data;
		delete curr;
		return ret;
	}
	//has both children

}
*/
bool BinaryTree::search(int data)
{
	/*
	Idea is to use the BST property.
	The left child always has data value less than the parent 
	and the right child.
	*/
	NodeTree *node = root;
	if (node == NULL)
	{
		cout << "Error: Empty tree"<<endl;
			return false;
	}
	while(data != node->data && node!=NULL)
	{
		if(data <= node->data)
			node = node->left;
		else
			node = node->right;
	}
	if(data == node->data)
		return true;
	return false;
}
NodeTree* BinaryTree::search_node(int data)
{
	/*
	Idea is to use the BST property.
	The left child always has data value less than the parent 
	and the right child.
	*/
	NodeTree *node = root;
	if (node == NULL)
	{
		cout << "Error: Empty tree"<<endl;
			return NULL;
	}
	while(data != node->data && node!=NULL)
	{
		if(data <= node->data)
			node = node->left;
		else
			node = node->right;
	}
	if(data == node->data)
		return node;
	return NULL;
}
int BinaryTree::max()
{
	/*
	The right most child in the BST will be the 
	max value in the tree -- property of BST
	*/
	NodeTree *node = root;

	if(node == NULL)
		return -1;
	while(node->right!=NULL)
	{
		node = node->right;
	}
	cout << "Max value in the tree ="<<node->data<<endl;
	return node->data;
}
int BinaryTree::min()
{
	/*
	The right most child in the BST will be the 
	max value in the tree -- property of BST
	*/
	NodeTree *node = root;

	if(node == NULL)
		return -1;
	while(node->left!=NULL)
	{
		node = node->left;
	}
	cout << "Min value in the tree ="<<node->data<<endl;
	return node->data;
}
NodeTree* BinaryTree::max_node()
{
	/*
	The right most child in the BST will be the 
	max value in the tree -- property of BST
	*/
	NodeTree *node = root;

	if(node == NULL)
		return NULL;
	while(node->right!=NULL)
	{
		node = node->right;
	}
	return node;
}
NodeTree* BinaryTree::min_node()
{
	/*
	The left most child in the BST/subtree will be the 
	min value in the tree/subtree -- property of BST
	*/
	NodeTree *node = root;

	if(node == NULL)
		return NULL;
	while(node->left!=NULL)
	{
		node = node->left;
	}
	return node;
}
int BinaryTree::height(NodeTree *node)
{
	if (node == NULL)	return -1;
	return std::max(height(node->left),height(node->right))+1;
}
void BinaryTree::get_height()
{
	cout << "Height of tree = "<<height(root)<<endl;
}
void BinaryTree::preorder(NodeTree* node)
{
	if (node == NULL) return;
	cout << node->data<< " ";
	preorder(node->left);
	preorder(node->right);
}
void BinaryTree::inorder(NodeTree* node)
{
	if (node == NULL) return;
	
	inorder(node->left);
	cout << node->data<< " ";
	inorder(node->right);
}
void BinaryTree::postorder(NodeTree* node)
{
	if (node == NULL) return;
	
	postorder(node->left);
	postorder(node->right);
	cout << node->data << " ";
}
void BinaryTree::get_dfs_travel(char *order)
{
	if(order == "preorder")
	{
		cout<<endl;
		cout << "Pre-order :";
		preorder(root);
		cout<<endl;
	}
	if(order == "inorder")
	{
		cout<<endl;
		cout << "In-order :";
		inorder(root);
		cout<<endl;
	}

	if(order == "postorder")
	{
		cout<<endl;
		cout << "Post-order :";		
		postorder(root);
		cout<<endl;
	}

}
void BinaryTree::check_bst()
{
	cout<<endl;
	if(isBST(root)){
		cout << "Tree is BST"<<endl;
		return;
	}
	
	cout << "Not BST"<<endl;
}
void BinaryTree::bfs_travel()
{	
	if(root == NULL) return;
	NodeTree *node = root;
	Queue<int> q(100);
	q.enqueue((int)node);
	while(!q.isEmpty())
	{
		NodeTree *node = (NodeTree*) q.dequeue();
		cout << node->data << " ";
		if(node->left!=NULL) q.enqueue((int)(node->left));
		if(node->right!=NULL) q.enqueue((int)(node->right));
	}

}
static void print_root_leaf(NodeTree *node, LinkedList *list)
{	
	if(node == NULL) return;
	NodeTree * left = node->getLeft();
	NodeTree * right = node->getRight();

	if(left == NULL && right == NULL)
	{
		list->push(node->getData());
		list->print_list();
		list->pop();
	}
	else
	{
		list->push(node->getData());
		if( left!=NULL) print_root_leaf(left,list);
		if( right!=NULL) print_root_leaf(right,list);
		list->pop();
	}
}
#endif

void runBinaryTree(void)
{
	//node *root;
	//root = NULL;
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
	
	/*
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
	breathFirstSeachTravel(&root);
	cout<<endl;
	*/
	
	BinaryTree tree;	
	
	tree.insert(6);
	tree.insert(4);
	tree.insert(10);
	tree.insert(2);
	tree.insert(5);
	tree.insert(7);
	tree.insert(11);
	tree.insert(1);
	tree.insert(3);
	tree.insert(9);
	tree.insert(8);
	//tree.delete_node(3);
	tree.bfs_travel();
	
}


