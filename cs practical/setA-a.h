#define bottom -1
#define max 25

typedef struct treenode
{
	int data;
	struct treenode *left,*right;
}TREE;

void init(TREE **);
void insert(TREE **, int);
void inorder(TREE *);
void preorder(TREE *);
void postorder(TREE *);
TREE *search(TREE *,int);
TREE* delNode(TREE *,int);
TREE *minValueNode(TREE *);
