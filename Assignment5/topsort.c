#include<stdio.h>
#define MAX 10

int n,adj[MAX][MAX];
int front = -1,rear = -1,queue[MAX];

void insert_queue(int node)
{
	queue[++rear]=node;
}

int delete_queue()
{
	return queue[++front];
}

int indegree(int node) 
{
	int i,in_deg = 0;
	for (i = 0;i < n;i++)
	   if(adj[i][node] == 1)
	    in_deg++;
	return in_deg;
}

void create_graph() 
{
   	int i,j,max_edges,origin,destin;
   	printf("\n Enter number of vertices:");
   	scanf("%d",&n);
   	printf("\nno.of vertices= %d\n",n);
    for (i = 0;i < n;i++) 
   		for (j = 0;j<n;j++) 
   			adj[i][j]=0;

    max_edges = n * (n - 1);
    printf("\nmax edges = %d\n",max_edges);
    for (i = 1;i <= max_edges;i++) 
    {
    	printf("\n Enter edge %d (00 to quit):",i);
    	scanf("%d%d",&origin,&destin);
    	if((origin == 0) && (destin == 0)) 
    		break;
    	else
    	   adj[origin-1][destin-1] = 1;
    }
    return;
}

void display() 
{
   	int i,j;
   	for (i = 0;i < n;i++) 
   	{
   		printf("\n");
    	for (j = 0;j<n;j++) 
    	{
    		printf("%d\t",adj[i][j]);
    	}
    }
}

int main()
{
	int i,j = 0,k;
  	int topsort[MAX],indeg[MAX];

   	create_graph();

   	printf("The adjacency matrix is:\n");
   	display();

   	for (i=0;i<n;i++)
   	{
   		indeg[i]=indegree(i);
  		if(indeg[i]==0)
    		   insert_queue(i);
    }
    while(front<=rear) 
    {
    	k=delete_queue();
    	topsort[j++]=k+1;
    	for (i=0;i<n;i++) 
    	{
    		if(adj[k][i]==1) 
    		{
    			adj[k][i]=0;
    			indeg[i]=indeg[i]-1;
    			if(indeg[i]==0)
    			     insert_queue(i);
    		}
    	}
    }
    printf("\n\nNodes after topological sorting are:\t");
    for (i=0;i<n;i++)
      printf("V%d\t",topsort[i]);
    printf("\n");
    return 0;
}


