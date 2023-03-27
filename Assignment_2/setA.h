#define bottom -1
#define max 25

typedef struct treenode
{
	int data;
	struct treenode *left,*right;
}TREE;


typedef struct queue
{
	TREE * value[max];
	int front,rear;
}IQUEUE;

void init(TREE **);
void insert(TREE **, int);
void inorder(TREE *);
void level(TREE *);

void initQ(IQUEUE *);
int isEmptyQ(IQUEUE *);
void addq(IQUEUE *,TREE *);
TREE *delq(IQUEUE *);
