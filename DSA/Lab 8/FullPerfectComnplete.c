#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;

}node;

node *newNode(int data)
{
    node *new = (node*)malloc(sizeof(node));

    new->data = data;
    new->right = NULL;
    new->left = NULL;
    return new;
}
int count(node *root){
    if (root==NULL)
        return 0;
    return 1 + count(root->left) + count(root->right);

}

int isFull(node *root){
    if (root == NULL)
        return 1;

    if (root->left == NULL && root->right == NULL)
        return 1;

    if ((root->left) && (root->right))
        return (isFull(root->left) & isFull(root->right));

    return 0;
}

int isComplete(node *root,int i,int nodes){
	if(root == NULL)
        return 1;
    if(i>nodes)
        return 0;
    return (isComplete(root->left,2*i+1,nodes))&(isComplete(root->right,2*i+2,nodes));
}

int findDepth(node *root){
    int d = 0;
    node *n = root;
    while (n != NULL)
    {
       d++;
       n = n->left;
    }
    return d;
}

int rec(node* root, int d, int height)
{
    if (root == NULL)
        return 1;
 
    if (root->left == NULL && root->right == NULL)
        return (d == height+1);
 
    if (root->left == NULL || root->right == NULL)
        return 0;
 
    // Left and right subtrees must be perfect.
    return rec(root->left, d, height+1) &
           rec(root->right, d, height+1);
}
 
int isPerfect(node *root)
{
   int d = findDepth(root);
   return rec(root, d, 0);
}

int main(){

	node* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(6);
 
    int no = count(root);
 
    if (isComplete(root, 0, no))
        printf("The Binary Tree is complete\n");
    else
        printf("The Binary Tree is not complete\n");


    if (isFull(root))
        printf("The Binary Tree is full\n");
    else
        printf("The Binary Tree is not full\n");

    
        if (isPerfect(root))
        printf("The Binary Tree is perfect\n");
    else
        printf("The Binary Tree is not perfect\n");

	return 0;
}
