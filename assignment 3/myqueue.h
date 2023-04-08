#define empty 0
#define max 10

typedef struct queue
{
	int value[max];
	int front,rear;
}IQUEUE;

void initq(IQUEUE *q)
{
	(*q).rear=(*q).front=empty;	
}

int isEmptyq(IQUEUE *q)
{
	return ((*q).front==(*q).rear? 1 : 0);
}

void addq(IQUEUE *q,int x)
{
	(*q).value[(*q).rear++]=x;
}

int delq(IQUEUE *q)
{
	return((*q).value[(*q).front++]);
}



