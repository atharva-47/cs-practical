#include<stdio.h>
#include<stdlib.h>

struct graphnode
{
	int vertex;
	struct graphnode *next;
}*list[5];

int main()
{
	int n,i,j,**graph,count;
	struct graphnode *t,*nn;
	printf("\nHow many vertices : ");
	scanf("%d",&n);
	graph=malloc(n * sizeof(int));
	for(i=0;i<n;i++)
	{
		graph[i]=malloc(n*sizeof(int));
		for(j=0;j<n;j++)
		{
			if(i!=j)
			{
			printf("Is there edge between V%d & V%d?(1 for yes,0 for no):",i+1,j+1);
			scanf("%d",&graph[i][j]);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
			printf("%d\t",graph[i][j]);
	}
	for(i=0;i<n;i++)
	{
		list[i]=malloc(sizeof(struct graphnode));
		list[i]->vertex=i+1;
		list[i]->next=NULL;
		for(j=0;j<n;j++)
		{
			if(graph[i][j]==1)
			{
				nn=malloc(sizeof(struct graphnode));
				nn->vertex=j+1;
				nn->next=NULL;
				for(t=list[i];t->next!=NULL;t=t->next);
				t->next=nn;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(t=list[i];t!=NULL;t=t->next)
			printf("%d\t",t->vertex);
		printf("\n");
	}
	for(count=0,i=0;i<n;i++)
	{
		count=0;
		for(t=list[i]->next;t!=NULL;t=t->next,count++);
		printf("%d",count);
	}
	for(count=0,i=0;i<n;i++)
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
		printf("Indegree(v%d)=%d\n",i+1,count);
	}
	return 0;
}

