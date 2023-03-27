#include<stdio.h>
#include<stdlib.h>
#include"setA.h"

int cnt;
void init(TREE **root)
{
	*root=NULL;
}

void initQ(IQUEUE *q)
{
	(*q).rear=(*q).front=bottom;	
}

int isEmptyQ(IQUEUE *q)
{
	return ((*q).front==(*q).rear? 1 : 0);
}

void addq(IQUEUE *q,TREE * x)
{
	(*q).value[++(*q).rear]=x;
}

TREE *delq(IQUEUE *q)
{
	return((*q).value[++(*q).front]);
}

void insert(TREE **root, int x)
{
	TREE *temp;

	TREE *newnode = malloc(sizeof(TREE));
	newnode->data=x;
	newnode->left=newnode->right=NULL;
	cnt++;
	if(*root==NULL)
		*root=newnode;
	else
	{
		temp=*root;
		while(1)
		{
		if(x < temp->data) 
		{
			if(temp->left==NULL) {temp->left=newnode;break;}
			else temp=temp->left;
		}
		else if(x > temp->data)
		{
			if(temp->right==NULL) {temp->right=newnode;break;}	
			else temp=temp->right;
		}
		}
	}
}

void inorder(TREE *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}
}

void level(TREE *root)
{
	printf("Level wise display :\n");
	TREE *temp=root,*dummy=NULL;
	int level=0;
	IQUEUE q;
	initQ(&q);
	addq(&q,temp);
	addq(&q,dummy);
	printf("\nLevel %d: \t",level);
	do
	{
		temp=delq(&q);
		if(temp!=dummy)
			printf("%d\t",temp->data);
		if(temp==dummy)
		{
			if(!isEmptyQ(&q))
			{
				level++;
				printf("\nLevel %d: \n",level);
				addq(&q,dummy);
			}
		}
		else 
		{
			if(temp->left) addq(&q,temp->left);
			if(temp->right) addq(&q,temp->right);
		}
	}while(!isEmptyQ(&q));
}

