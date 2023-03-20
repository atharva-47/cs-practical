typedef struct treenode
{
	int data;
	struct treenode *left,*right;
}TREE;


void init(TREE **);
void insert(TREE **, int);
void inorder(TREE *);
TREE *copy(TREE *root);
int comparebst(TREE *, TREE *);
void mirror(TREE *root);
