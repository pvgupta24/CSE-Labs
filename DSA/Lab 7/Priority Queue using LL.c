//Priority Queue using LL

#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int data;
	int rank;
	//Lower rank higher 
	struct node *next;

}node;

node *head=NULL;

node *insert(node *head, int data, int rank){
	node *temp=(node *)malloc(sizeof(node));
	temp->data=data;
	temp->rank=rank;

	if(head==NULL){
		temp->next=NULL;
		return temp;
	}
	node *curr=head,*prev=curr;
	int i=curr->rank;
	if(i>rank){
		temp->next=head;
		return temp;
	}
	while(i<=rank && curr->next !=NULL ){
		prev=curr;
		curr=curr->next;
		i=curr->rank;
	}
	if(i<=rank){
		temp->next=curr->next;
		curr->next=temp;
	}
	else{
		temp->next=prev->next;
	prev->next=temp;
	}
	



	/*for(i=curr->rank;i<=rank && (curr->next)!=NULL && curr->next->next!=NULL;){
		prev=curr;

		curr=curr->next;
		i=curr->rank;
	};
	
	//temp->next=curr->next;
	//curr->next=temp;

	temp->next=prev->next;
	prev->next=temp;
*/
	
	return head;

}
node *delete(node *head){


	if(head==NULL){
		printf("P.Q already empty\n");
		return head;
	}
	node *temp=head->next;
	printf("(%d,%d) dequed\n",head->data,head->rank );
	free(head);

	return temp;
}
void print(node *head){
	node *curr=head;
	printf("--------------------------------\nHead->");
	while(curr!=NULL){
		printf("(%d,%d)-->",curr->data,curr->rank);
		curr=curr->next;
	}
	printf("NULL\n--------------------------------\n");
	
}
int main(){

	node *head=NULL;

	printf("Priority Queue using LL\n");
	int c,data,rank;

	again:
	printf("\n1. Enque         2. Deque		  3.Exit\n");
	scanf("%d",&c);
	switch(c){
		case 1:	printf("Enter data & priority(rank)\n");
				scanf("%d%d",&data,&rank);
				head=insert(head,data,rank);
				break;

		case 2:	head=delete(head);
				break;		

		case 3:	exit(0);
	}
	print(head);
	goto again;


	return 0;
}
