//Assignment1 set A-b)
//Program to count total nodes and leaf nodes in the binary search tree

#include<stdio.h>
#include "setAb.c"

int main()
{
	int ch,data,con;
	TREE *t,*t1;
	init(&t);
	do
	{
		printf("\n0.Exit\n1.Insert\n2.Count leaf nodes\n3.Count non-leaf nodes\n");
		printf("Enter ur choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:	exit(0);
			case 1:	do
				{
					printf("Data : ");
					scanf("%d",&data);
					insert(&t,data);
					printf("\nContinue?(1/0): ");
					scanf("%d",&con);
				}while(con!=0);
				break;
			case 2: printf("No. of leafnodes = %d\n",countleaf(t));break;
			case 3: printf("No. of non-leafnodes = %d\n",countnonleaf(t));break;
		}			
	}while(ch!=0);
}

