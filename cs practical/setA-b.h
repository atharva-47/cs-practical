typedef struct treenode
{
	int data;
	struct treenode *left,*right;
}TREE;


void init(TREE **);
void insert(TREE **, int);
int countleaf(TREE *);
int countnonleaf(TREE *);

