#include<stdio.h>
#include<stdlib.h>
#include "myqueue.h"

struct graphnode
{
	int vertex;
	struct graphnode *next;
}*list[10],*nn=NULL,*t=NULL;

int graph[10][10];

void dfs(int vertex,int n)
{
	static int visited[10];
	int w,i;
	if(!visited[vertex]) 
	{
		visited[vertex]=1;
		printf("\nV%d\n",vertex+1);
	}
	for(i=0;i<n;i++)
		if(graph[vertex][i]==1)
			if(visited[i] ==0)
				dfs(i,n);	
}

void bfs(int vertex,int n)
{
	static int visited[10];
	int found,i;
	IQUEUE q;
	initq(&q);
	visited[vertex]=1;
	addq(&q,vertex);
	while(!isEmptyq(&q))
	{
		vertex=delq(&q);
		printf("V%d\t",vertex+1);		
		for(i=0;i<n;i++)
			if(graph[vertex][i]==1)
				if(visited[i] ==0)
				{
					addq(&q,i);
					visited[i]=1;
				}
	}
}

int main()
{
	int n,i,j,*outdeg,*indeg;
	int count=0;
	
	printf("\nHow many vertices : ");
	scanf("%d",&n);
	outdeg=calloc(n,sizeof(int));
	indeg=calloc(n,sizeof(int));
	for(i=0;i<n;i++)
	{
		graph[i][i]=0;
		for(j=0;j<n;j++)
		{
			if(i!=j)
			{
			printf("Is there edge between V%d & V%d?(1 for yes,0 for no):",i+1,j+1);
			scanf("%d",&graph[i][j]);
			}
		}
	}
	printf("adjacency matrix = \n");
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
			printf("%d\t",graph[i][j]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			outdeg[i]+=graph[i][j];
			indeg[i]+=graph[j][i];
		}
	}
	printf("\n\nvertex\tIndeg\tOutdeg\tTotal degree");
	for(i=0;i<n;i++)
		printf("\nV%d\t%d\t%d\t%d",i+1,outdeg[i],indeg[i],outdeg[i]+indeg[i]);	
		
	printf("\ndfs yields \n");
	dfs(0,n);
	printf("\nBFS \n");
	bfs(0,n);
	
	for(i=0;i<n;i++)
	{
		list[i]=malloc(sizeof(struct graphnode));
		list[i]->vertex=i+1;
		list[i]->next=NULL;
		for(j=0;j<n;j++)
		{
			if(graph[i][j]==1)
			{
				nn=(struct graphnode*)malloc(sizeof(struct graphnode));
				nn->vertex=j+1;
				nn->next=NULL;
				for(t=list[i];t->next!=NULL;t=t->next);
				t->next=nn;
			}
		}
	}
	printf("\nAdjacency list:\n");
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(t=list[i];t!=NULL;t=t->next)
			printf("%d->",t->vertex);
		printf("NULL\n");
	}
	printf("\noutdegree\n");
	for(i=0;i<n;i++)
	{	count=0;
		printf("\nV%d:",i+1);
		for(t=list[i]->next;t!=NULL;t=t->next,count++);
			printf("%d",count);
	}
	for(i=0;i<n;i++)
	{
		count=0;
		for(j=0;j<n;j++)
		{
			for(t=list[j]->next;t!=NULL;t=t->next)
			{
				if(t->vertex==i+1)
					count++;
			}
		}
		printf("\nIndegree(v%d)=%d\n",i+1,count);
	}


	return 0;
}
