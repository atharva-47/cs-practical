#include<stdio.h>
#include<stdlib.h>

int main()
{
	int **mat;
	int n,i,j;
	printf("\nHow many vertices : ");
	scanf("%d",&n);
	mat = (int **)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		mat[i]=malloc(n*sizeof(int));
		for(j=0;j<n;j++)
		{
			mat[i][i]=0;
			if(i!=j)
			{
				printf("Is there edge between V%d & V%d?(1 for yes,0 for no):",i+1,j+1);
				scanf("%d",&mat[i][j]);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
			printf("%d\t",mat[i][j]);
	}	
	for(i=0;i<n;i++)
		free(mat[i]);		
	free(mat);
	return 0;
}
