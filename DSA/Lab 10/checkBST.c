#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;

}node;

node *newNode(int data){
	node *temp=(node *)malloc(sizeof(node));
	temp->data=data;
	temp->left=temp->right=NULL;

	return temp;
}

void print(node *head){
	if(head==NULL)
	{
		return;
	}
	printf("%d(",head->data );
	print(head->left);
	printf(" , ");
	print(head->right);
	printf(")");
}

int checkBST(node *head,int min,int max){
	if(head==NULL)
		return 1;
	if(head->data<min || head->data>max)
		return 0;
	return checkBST(head->left,min,head->data-1) & checkBST(head->right,head->data+1,max);
}

int isBST(node *head){
	return checkBST(head,INT_MIN,INT_MAX);
}

int main(){
	node *head=newNode(4);
	head->left=newNode(2);
	head->right=newNode(5);
	head->left->right=newNode(3);
	print(head);
	printf("\n");
	printf("The tree is %s BST\n", isBST(head) ? "a":"not a");
	return 0;
}