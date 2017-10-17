#include<stdio.h>
#include<stdlib.h>
#define in(n) scanf("%d",&n)
#define pf(n) printf("%d ",n)

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

node *create(node *head,int data){

	if (head==NULL){
		head = newNode(data);
	}
	else if(data<=head->data){
		head->left = create(head->left,data);
	}
	else{
		head->right = create(head->right,data);
	}
	return head;
}

int sorted[100];
int i=0;
int push(int n){
	sorted[i++]=n;
}
void inOrder(node *root){
	if(root==NULL)
		return;
	inOrder(root->left);
	push(root->data);
	inOrder(root->right);
}

int main(){
	printf("Enter n & n elements of array\n");
	int n,i;
	in(n);
	int a[n];
	node *head=NULL;

	for(int i=0;i<n;++i){
		in(a[i]);
		head=create(head,a[i]);
	}
	
	inOrder(head);
	for (int i = 0; i < n; ++i)
		pf(sorted[i]);
	printf("\n");
	return 0;
}