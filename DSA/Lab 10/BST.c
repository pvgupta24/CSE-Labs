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
int path[100];
int level=0;
int push(int n){
	path[level++]=n;
}
int search(node *head, int data){
	if(head==NULL)
		return 0;
	push(head->data);
	if(head->data==data)
		return 1;
	if(data<head->data)
		return search(head->left, data);
	else
		return search(head->right, data);
}

node *deleteTree(node *head){
	if(head==NULL)
		return NULL;

	deleteTree(head->left);
	deleteTree(head->right);
	free(head);
	return NULL;
}

node *delete(node *head, int data){
	if(head==NULL){
		printf("Nor found\n");		
	}

	if(head->data==data){
		head = deleteTree(head);
	}
	
	else if(data<head->data)
		head->left = delete(head->left, data);
	
	else
		head->right = delete(head->right, data);

	return head;
}

int getMax(node *head){
	if(head==NULL)
		return INT_MAX;
	node *curr=head;
	while(curr->right!=NULL)
		curr=curr->right;
	return curr->data;
}

node *getMin(node *head){
	if(head==NULL)
		return NULL;
	node *curr=head;
	while(curr->left!=NULL)
		curr=curr->left;
	return curr;
}

node *bstDelete(node *root,int data){
    if(root==NULL)
        return NULL;
    else if(data<root->data){
        root->left= bstDelete(root->left,data);
        return root;
    }//correct
    else if(data>root->data){
        root->right= bstDelete(root->right,data);
        return root;
    }

    //Found here
    if(root->left==NULL && root->right==NULL){
        //Leaf remove it and attach NULL
        free(root);
        return NULL;
    }
    //Has only right
    if(root->left==NULL){
        node *temp=root->right;
        free(root);
        return temp;
    }
    if(root->right==NULL){
        node *temp=root->left;
        free(root);
        return temp;
    }
    //has both child
    node *minNode=getMin(root->right);
    //minNode wont have left child
    root->data=minNode->data;
    root->right=bstDelete(root->right,minNode->data);
    return root;    
}

int main(){

	node *head=NULL,*minNode;

	printf("Binary Search Tree using LL\n");
	int c,data,min,max,found;

	again:
	printf("\n1. Insert Node         2. Delete Node		   3. Search 		4. GetMax 		5. GetMin\n");
	scanf("%d",&c);

	switch(c){
		case 1:	printf("Enter data\n");
				scanf("%d",&data);
				head=create(head,data);
				break;

		case 2:	printf("Enter data to delete\n");
				scanf("%d",&data);
				head = bstDelete(head,data);
				break;		

		case 3: printf("Enter data to search\n");
				scanf("%d",&data);
				found = search(head,data);
				if(found){
					printf("Found in BST\nRoot");
					for(int i=0;i<level;++i)
						printf("-->%d",path[i]);
					printf("\n");
				}
				else{
					printf("Not found in BST\n");
				}
				break;

		case 4: max = getMax(head);
				if(max==INT_MAX)
					printf("Empty Tree\n");
				else
					printf("Max is %d\n",max);
				break;

		case 5: minNode = getMin(head);
				if(minNode==NULL)
					printf("Empty Tree\n");
				else
					printf("Min is %d\n",minNode->data);
				break;
	}
	level=0;
	print(head);
	goto again;
return 0;
}