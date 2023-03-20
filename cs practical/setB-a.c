#include<stdio.h>
#include "setB.c"

int main()
{
	int ch,data,con;
	TREE *t,*t1;
	init(&t);
	do
	{
		printf("\n0.Exit\n1.Insert\n2.Copy tree\n3.Compare\n");
		printf("Enter ur choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0: exit(0);
			case 1: do
				{
					printf("Data : ");
					scanf("%d",&data);
					insert(&t,data);
					printf("\nContinue?(1/0): ");
					scanf("%d",&con);
				}while(con!=0);
				break;
			case 2: t1=copy(t);inorder(t1);break;
			case 3: mirror(t1);
				if(comparebst(t,t1)) 
					printf("\nequal trees\n");
				else printf("\ntrees not equal\n");
				break;
		}
	}while(ch!=0);
}
