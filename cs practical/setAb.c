#include<stdio.h>
#include<stdlib.h>
#include"setA-b.h"

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

int countleaf(TREE *root)
{
	static int cnt;
	if(root!=NULL)
	{
		if(root->left ==NULL && root->right==NULL) cnt++;
		countleaf(root->left);
		countleaf(root->right);
	}
	return cnt;
}

int countnonleaf(TREE *root)
{
	static int cnt;
	if(root!=NULL)
	{
		printf("\ncnt=%d",cnt);
		cnt++;
		if(root->left ==NULL && root->right==NULL) cnt--;
		countnonleaf(root->left);
		countnonleaf(root->right);
		
	}
	return cnt;
}


