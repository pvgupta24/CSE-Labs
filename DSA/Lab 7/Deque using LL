//Deque using LL

#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;

}node;

node *head=NULL;

void print(){
	node *curr=head;
	printf("--------------------------------\nHead->");
	while(curr!=NULL){
		printf("%d<-->",curr->data);
		curr=curr->next;
	}
	printf("NULL\n--------------------------------\n");
	
}
void push_back(int data){

	node * temp = (node *)malloc(sizeof(node));
	temp->data=data;	
	temp->next=NULL;

	if(head==NULL)
	{		
		temp->data=data;
		temp->prev=NULL;
		head=temp;
	}
	else{
		node *curr=head;
		while(curr->next!=NULL)
			curr=curr->next;
		curr->next=temp;
		temp->prev=curr;

	}
	
}

void push_front(int data){
	node * temp = (node *)malloc(sizeof(node));
	temp->data=data;

	if(head==NULL)
	{		
		temp->data=data;
		temp->next=NULL;
		temp->prev=NULL;
		
	}
	else{

		temp->next=head;
		temp->prev=NULL;
	}
	head=temp;
}

void pop_back(){
		node *curr=head;
		if(head==NULL){
			printf("Deque already empty\n");
			return;
		}

		while(curr->next!=NULL)
			curr=curr->next;

		node *temp=curr->prev;
		free(curr);
		temp->next=NULL;
}

void pop_front(){
		node *curr=head;
		if(head==NULL){
			printf("Deque already empty\n");
			return;
		}

		node *temp=curr->next;
		free(curr);
		temp->prev=NULL;
		head=temp;
}

int main(){

	printf("Doubly ended Queue using LL\n");
	int c,data;

	again:
	printf("\n1. Push_Back         2. Push_Front        3.Pop_Back 		 4.Pop_Front 		  5.Exit\n");
	scanf("%d",&c);
	switch(c){
		case 1:	printf("Enter data\n");
				scanf("%d",&data);
				push_back(data);
				break;
		case 2:	printf("Enter data\n");
				scanf("%d",&data);
				push_front(data);
				break;
		case 3:	pop_back();
				break;
		case 4:	pop_front();
				break;
		case 5:	exit(0);
				break;
	}
	print();
	goto again;
	return 0;
}
