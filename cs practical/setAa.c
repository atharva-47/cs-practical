#include<stdio.h>
#include<stdlib.h>
#include"setA-a.h"

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
			if(temp->right==NULL) {temp->right=newnode;break;}	
			else temp=temp->right;
		}
		}
	}
}

TREE *search(TREE *root,int data)
{
	if(root==NULL || root->data==data)
		return root;
	if(root->data < data)
		return search(root->right,data);
	return search(root->left,data);
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

void preorder(TREE *root)
{
	if(root!=NULL) 
	{
		printf("%d\t",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(TREE *root)
{
	if(root!=NULL) 
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\t",root->data);
	}
}

TREE * minValueNode(TREE *root)
{
	TREE *current=root;
	while(current && current->left!=NULL)
		current = current->left;
	return current;
}

TREE* delNode(TREE *root,int data)
{
	if(data < root->data)
		root->left = delNode(root->left,data);
	else if(data > root->data)
		root->right = delNode(root->right,data);
	else 
	{
		if(root->left == NULL && root->right == NULL)
		{
			free(root);
			return NULL;
		}
		else if(root->left == NULL)
		{
			TREE *temp = root->right;
			free(root);
			return temp;			
		}
		else if(root->right == NULL)
		{
			TREE *temp = root->left;
			free(root);
			return temp;			
		}
		TREE *temp = minValueNode(root->right);
		root->data=temp->data;
		root->right = delNode(root->right,temp->data);
	}
	return root;
}

