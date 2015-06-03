typedef struct binaryTree node;

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
void runBinaryTree(void);