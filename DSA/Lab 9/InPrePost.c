#include<stdio.h>
#include<stdlib.h>

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
		//printf("NULL");
		return;
	}
	printf("%d(",head->data );
	print(head->left);
	printf(" , ");
	print(head->right);
	printf(")");
}

void pre(node *root){
	if(root==NULL)
		return;
	printf("%d ",root->data);
	pre(root->left);
	pre(root->right);

}

void post(node *root){
	if(root==NULL)
		return;
	post(root->left);
	post(root->right);
	printf("%d ",root->data);


}

void in(node *root){
	if(root==NULL)
		return;
	in(root->left);
	printf("%d ",root->data);
	in(root->right);

}

int main(){

	node* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("Pre-Order\n");
    pre(root);
    printf("\n");

    printf("Post-Order\n");
    post(root);
    printf("\n");

    printf("In-Order\n");
    in(root);
    printf("\n");

	return 0;
}
