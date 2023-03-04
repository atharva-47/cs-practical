// Implement Binary Search tree(BST) 
#include<stdio.h>
#include "setAa.c"

int main()
{
	int ch,data,con;
	TREE *t,*t1;
	init(&t);
	do
	{
															printf("\n0.Exit\n1.Insert\n2.Inoreder\n3.Preorder\n4.Postorder\n5.Delete");
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
				break;
			case 2:	if(t==NULL) 
				printf("Tree doesn't exist\n");
				else {
				printf("\nRecursive inorder yields \n");
				inorder(t);
				}
				break;
			case 3:	if(t==NULL) 
				printf("Tree doesn't exist\n");
				else {
				printf("\nRecursive preorder yields \n");
				preorder(t);
				}
				break;
			case 4:	if(t==NULL) 
				printf("Tree doesn't exist\n");
				else {
				printf("\nRecursive postorder yields \n");
				postorder(t);
				}
				break;
			case 5:	if(t==NULL)
				printf("Tree doesn't exist\n");
				else {
				printf("Enter data to be deleted :");
				scanf("%d",&data);
				TREE *found=NULL;
				found = search(t,data);
				if(found==NULL)
					printf("Data not present in tree\n");
				else
				t=delNode(t,data);
				}
				break;
		}
	}while(ch!=0);
}

