
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


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

        printf("No. of nodes = %d\n",no);

        int height;
        printf("Enter height\n");
        scanf("%d",&height);
        printf("No. of nodes = %d",(int)(pow(2,(height+1)))-1);

        return 0;
    }