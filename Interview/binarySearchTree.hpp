#ifndef __BINARYSEARCHTREE_H
#define __BINARYSEARCHTREE_H


typedef struct binaryTree node;

#if 0
struct binaryTree
{
	int data;
	struct binaryTree *left;
	struct binaryTree *right;
};

node *createNode(int );
void insertNode(node **, int );
int searchBinaryTree(node **, int );
int findMAX(node **);
node *findMIN(node **);
int findHeight(node **);
void breathFirstSeachTravel(node **);
void dfsPreorder(node **);
void dfsInorder(node **);
void dfsPostorder(node **);
#else
class NodeTree
{
	friend class BinaryTree;
private:
	int data;
	NodeTree *left;
	NodeTree *right;
public:
	NodeTree()
		:left(NULL),right(NULL)
	{}
	NodeTree(int value)
		:data(value),left(NULL),right(NULL)
	{}
	int getData(){return data;}
	NodeTree* getLeft(){return left;}
	NodeTree* getRight(){return right;}
};
class BinaryTree
{
private:
	NodeTree *root;
	int height(NodeTree *node);
	void preorder(NodeTree *node);
	void postorder(NodeTree *node);
	void inorder(NodeTree *node);
	bool isBST(NodeTree *node);
	
public:
	BinaryTree();
	BinaryTree(int value);
	~BinaryTree();

	bool leaf(NodeTree *node){return (node->left==NULL && node->right==NULL);}
	NodeTree* get_root(){return root;}
	void insert(int data);
	int delete_node(int data);
	void deleteTree();
	bool search(int data); // search tree (bst)
	NodeTree *search_node(int data); // search with return node
	int max();
	int min();
	NodeTree* max_node();
	NodeTree* min_node();
	
	void get_height();
	void get_dfs_travel(char *order);
	NodeTree* get_inorder_successor(int data);
	void bfs_travel();
	
	
	void check_bst();// is tree a bst?
};
#endif
void runBinaryTree(void);


#endif //__BINARYSEARCHTREE_H