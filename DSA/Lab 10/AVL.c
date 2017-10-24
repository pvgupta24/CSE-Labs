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
int max(int a,int b){
    return a > b ? a:b; 
}
int getHeight(node *head){
    if(head==NULL)
        return 0;

    return 1+max(getHeight(head->left),getHeight(head->right));
}
int balFactor(node *head){
    if(head==NULL)
        return 0;
    return getHeight(head->left)-getHeight(head->right);
}

node *leftRotate(node *head){
    node *a = head->right;
    head->right=a->left;
    a->left=head;
    return a;
}

node *rightRotate(node *head){
    node *a = head->left;
    head->left=a->right;
    a->right=head;
    return a;
}

node *insert(node *head,int data){
    if(head==NULL)
        return newNode(data);

    else if(data < head->data)
        head->left=insert(head->left,data);
    else if(data > head->data)
        head->right=insert(head->right,data);

    //Assuming elements are unequal
    else
        return head;

    int bal = balFactor(head);        
    if(bal>1){
        //LL
        if(data < head->left->data){
            return rightRotate(head);
        }
        //LR
        else{
            head->left=leftRotate(head->left);
            return rightRotate(head);
        }
    }
    else if(bal<-1){
        //RR
        if(data > head->right->data){
            return leftRotate(head);
        }
        //RL
        else{
            head->right=rightRotate(head->right);
            return leftRotate(head);
        }
    }
    return head;
    
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
int getMax(node *head){
	if(head==NULL)
		return INT_MAX;
	node *curr=head;
	while(curr->right!=NULL)
		curr=curr->right;
	return curr->data;
}

int getMin(node *head){
	if(head==NULL)
		return INT_MIN;
	node *curr=head;
	while(curr->left!=NULL)
		curr=curr->left;
	return curr->data;
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
/*
void balance(node *head){
    if(head==NULL)  return;
    
}
node *delNode,*delPar;
//int delFound=0;

int delSearch(node *head, int data){
    if(head==NULL)
        return 0;

    if(data < head->data){
        if (data == head->left->data){
            delNode = head->left;
            delPar = head; 
            return 1;//1 means found at left of parent
        }
        else{
            return delSearch(head->left,data);
        }
    }
    else if (data > head->data){
        if (data == head->right->data){
            delNode = head->right;
            delPar = head; 
            return 2;//2 means found at right of parent
        }
        else{
            return delSearch(head->right,data);            
        }
    }
    else {
        return 3;//data equals head's data
    }
}

void swapData(node *a,node *b){
    int temp = a->data;
    a->data=b->data;
    b->data=temp;
}
void remove(node *delPar,node *a,int found){
    if(a->next==NULL){
        
    }
    while(a->left->left!=NULL){
        swapData(a,a->left);
        a=a->left;
    }
}
node *delete(node *head,int data){
    // SOMEBODY DO THISSSSSSSSSSSSSSS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    int found=delSearch(head,data);
    switch(found){
        case 0: printf("Key not found in tree\n");
                break;
        case 1: swapData(delPar,delNode);
                remove(delPar,delNode,found);
                break;
        case 2: swapData(delPar,delNode);
                remove(delPar,delNode,found);
                break;
        case 3:
                break;
    }
    return head;
}
*/
int main(){
    node *head=NULL;
    
    printf("AVL Tree\n");
    int c,data,min,max,found;

    again:
    printf("\n1. Insert Node   2. Delete Node   3. Search   4. GetMax   5. GetMin   6. Find Height\n7. In-Order   8. Pre-Order   9. Post-Order    Others to exit...\n");
    scanf("%d",&c);

    switch(c){
        case 1:	printf("Enter data\n");
                scanf("%d",&data);
                head=insert(head,data);
                break;

        case 2: printf("Enter data to delete\n");
                scanf("%d",&data);
                //head = delete(head,data);
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

        case 5: min = getMin(head);
                if(min==INT_MIN)
                    printf("Empty Tree\n");
                else
                    printf("Min is %d\n",min);
                break;
        case 6: printf("The height of AVL tree is %d\n",getHeight(head));
                break;
        case 7: in(head);
                break;
        case 8: pre(head);
                break;
        case 9: post(head);
                break;
        default: return 0;
                
    }
    level=0;
    print(head);
    goto again;
    return 0;
}
