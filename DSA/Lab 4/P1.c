#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* prev;
    struct node* next;
}node;

node *insert(node *head,int data,int pos);
node *delete(node *head,int pos);
void  print(node *head);
 
int main(){
    node *head=NULL;
    int choice;
    int data,pos;


    printf("Double Linked List");
    again:
    printf("\n1. Insert\n2. Delete\nOthers to exit\n\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Enter data\n");
            scanf("%d",&data);
            printf("Enter pos\n");
            scanf("%d",&pos);
            head=insert(head,data,pos);
                    
            break;
        case 2:
            printf("Enter pos\n");
            scanf("%d",&pos);
            head=delete(head,pos);
            break;
    
        default:
            return 0;
    }
    print(head);
goto again;
    return 0;
}

void  print(node *head){
    node *curr=head;    
    printf("--------------------------------\nHead->");
    while(curr!=NULL){
        printf("%d<-->",curr->data);
        curr=curr->next;
    }
    printf("NULL\n--------------------------------\n");

}


node *insert(node *head,int data,int pos){

    node *curr=head;
    node *temp=(node *)malloc(sizeof(node));
    temp->data=data;

    if(pos==0){
        temp->next=head;
        temp->prev=NULL;
        return temp;
    }

    int i=0;
    while(curr!=NULL&&i<pos-1){
        curr=curr->next;
    }
    if(curr==NULL)
    {
        printf("Position exceeding the length. Try again\n");
        return head;
    }
    
    temp->next=curr->next;
    temp->prev=curr;
    curr->next=temp;    

    return head;
}


node *delete(node *head,int pos){

    node *curr=head,*temp;
    if(pos==0){
        if(curr==NULL)
            {
                printf("No element to delete\n");
                return curr;
            }

        temp=curr->next;

        if(temp==NULL){
            free(curr);
            return NULL;
        }

        free(curr);
        temp->prev=NULL;
        return temp;
    }

    int i=0;
    while(curr!=NULL&&i<pos-1){
        curr=curr->next;
    }

    if(curr==NULL)
    {
        printf("Position exceeding the length. Try again\n");
        return head;
    }

    if(curr->next==NULL){
        return;
    }
    
    temp=curr->next;  
    curr->next=temp->next;
    (temp->next)->prev=curr;
    free(temp);
    return head;
}