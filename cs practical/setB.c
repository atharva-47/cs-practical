#include<stdio.h>
#include<stdlib.h>
#include"setB.h"

int cnt;
void init(TREE **root)
{
	*root=NULL;
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
			if(temp->right==NULL) 
				{temp->right=newnode;break;}	
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

TREE *copy(TREE *root)
{
	TREE *newnode;
	if(root!=NULL)
	{
		newnode = malloc(sizeof(TREE));
		newnode->left = copy(root->left);
		newnode->right = copy(root->right);
		newnode->data = root->data;
		return newnode;
	}
	return NULL;
}

void mirror(TREE *root)
{
	TREE *temp=root,*temp1;
	if(temp)
	{
		if(temp->left) mirror(temp->left);
		if(temp->right) mirror(temp->right);
	}
	temp1=temp->left;
	temp->left=temp->right;
	temp->right=temp1;
}


int comparebst(TREE *root1, TREE *root2)
{
	static int equal =0;
	if(root1==NULL && root2==NULL)
		return 1;
	else if(root1!=NULL && root2!=NULL)
		if(root1->data == root2->data)
		{
			if(comparebst(root1->left,root2->left))
				equal = comparebst(root1->right,root2->right);
		}
		else equal=0;
	return equal;
		
}

