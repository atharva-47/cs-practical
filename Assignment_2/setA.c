#include<stdio.h>
#include "setAa.c"

int main()
{
	int ch,data,con;
	TREE *t,*t1;
	init(&t);
	do
	{
		printf("\n0.Exit\n1.Insert\n2.Level wise display");
		printf("\nEnter ur choice :");
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
				inorder(t);
				break;
			case 2: level(t);break;
		}
	}while(ch!=0);
}
