#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

void print(node *head);
node* insert(node *head,int data,int pos);
node* delete(node *head,int pos);
node* delN(node *head,int pos);
node* nFromLast(node *head,int pos);
node* sort(node *head);
node *rev(node *head);

int main(){



	node *head=NULL;
	
	printf("Linked List\n\n");
	int option=0;
	int data,pos;
	repeat:
	printf("\nSelect Option\n1. Insert\n2. Delete\n3. Sort\n4. Reverse\n5. Delete nth node\n6. Delete nth From Last\n");
	scanf("%d",&option);
	
	switch(option){
		case 1:
			//Insert
			printf("\nEnter data: ");
			scanf("%d",&data);
			printf("Enter position: ");
			scanf("%d",&pos);
			head=insert(head,data,pos);			
			break;		
		case 2:
			//Delete
			printf("Enter position to delete : ");
			scanf("%d",&pos);
			head = delete(head,pos);
		case 3:
			//Sortnode* delN(node *head,int pos);
			head = sort(head);node *rev(node *head);
			break;
		case 4:
			//Reverse
			head = rev(head);
			break;
		case 5:
			//Delete nth
			printf("Enter n : ");
			scanf("%d",&pos);
			head = delN(head,pos);
			break;
		case 6:
			//Delete nth from last
			printf("Enter n : ");
			scanf("%d",&pos);
			head = nFromLast(head,pos);
			break;
		default:
			printf("Select a valid option\n");
			
	}
	print(head);
	goto repeat;	
	return 0;		
}
void print(node *head){
	printf("Head -> ");
	node *curr=head;
	while(curr!=NULL){
		printf("%d -> ",curr->data);
		curr=curr->next;
	}
	printf("NULL\n");
}

node* insert(node *head,int data,int pos){
	node *new=(node*)malloc(sizeof(node));
	new->data=data;
	
	if(head==NULL||pos==0){
		new->next=head;
		head=new;
		return head;
	}
	
	int i;
	node *curr=head;	
	for(i=0;curr!=NULL && i<pos ;++i){
		if(i!=pos-1)
				curr=curr->next;
	}
		
	if(i==pos)
	{				
		new->next=curr->next;
		curr->next=new;
				
	}
	else
	{
	printf("Could Not Insert. \n");
	}node *rev(node *head);
	return head;
}

node *delete(node *head,int pos){
	int i;
	node *curr=head;
	node *temp;	
	if(pos==0){
		temp=head->next;
		head->next=temp->next;
		free(temp);
		return head;	
		}
	for(i=0;curr!=NULL && i<pos ;++i){
		if(i!=pos-1)
				curr=curr->next;
	}
		
	if(i==pos)
	{				
		temp=curr->next;
		curr->next=temp->next;
		free(temp);				
	}
	else
	{
	printf("Could Not Delete. \n");
	}
	return head;
}


node* delN(node *head,int pos){
	int i;
	node *curr=head;
	node *temp;	
	for(i=0;curr!=NULL && i<pos ;++i,curr=curr->next);
		
	if(i==pos)
	{	
	
		if(curr->next == NULL)
			printf("Cannot delete last node\n");
		else{
			temp=curr->next;
			int data=curr->data;
			curr->data=temp->data;
			temp->data=data;					
			
			curr->next=temp->next;
			free(temp);
		}			
						
	}
	else
	{
	printf("Could Not Delete. \n");
	}
	return head;
}


node* nFromLast(node *head,int pos){
	int i;
	node *curr=head,*b=head;
	node *temp;	
	
	
	for(i=0;curr->next!=NULL;++i){
		if(i>=pos)
			b=b->next;		
		
		curr=curr->next;
	}
	
		temp=b->next;
		b->next=temp->next;
		free(temp);		
	
	return head;
}




node* sort(node *head){
	node *a,*b;
	int temp;
	
	for(a=head;a->next!=NULL;a=a->next){
		for(b=a->next;b!=NULL;b=b->next){
			if(b->data < a->data){
				temp=a->data;
				a->data=b->data;
				b->data=temp;
			}
		}
	}
	
	return head;
}

node *rev(node *head){

	if(head==NULL||head->next==NULL)
		return head;

	node *a=NULL,*b=head,*temp;
	
	while(b!=NULL){
	temp=b->next;
	b->next=a;
	a=b;
	b=temp;
	}

	return a;
}
