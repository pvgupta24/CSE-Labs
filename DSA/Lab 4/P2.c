#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node *addToEmpty(int data);
node *insert(node *last,int data,int pos);
node *delete(node *last,int pos);
void  print(node *last);
 
int main(){
    node *last=NULL;
    int choice;
    int data,pos;


    printf("Circular Linked List");
    again:
    printf("\n1. Insert\n2. Delete\nOthers to exit\n\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Enter data\n");
            scanf("%d",&data);
            printf("Enter pos\n");
            scanf("%d",&pos);
            last=insert(last,data,pos);
                    
            break;
        case 2:
            printf("Enter pos\n");
            scanf("%d",&pos);
            last=delete(last,pos);
            break;
    
        default:
            return 0;
    }
    print(last);
goto again;
    return 0;
}

void print(node *last){
    node *curr=last;    
    if(curr==NULL){
        printf("No elements\n");
        return;
    }
    
    printf("--------------------------------\nHEAD-->");
    do{
        curr=curr->next;
        printf("%d-->",curr->data);  

    }while(curr!=last);

    printf("HEAD\n--------------------------------\n");

}

node *addToEmpty(int data){
    node *temp=(node *)malloc(sizeof(node));
    temp->data=data;
    temp->next=temp;    
    return temp;
}



node *insert(node *last,int data,int pos){

    node *curr=last;

    node *temp=(node *)malloc(sizeof(node));
    temp->data=data;
    if(curr==NULL)
        return addToEmpty(data);
    
    int i=0;
    while(i<pos){
        curr=curr->next;
        ++i;
    }
    int flag=0;
    if(pos==1 && last->next==last)
        flag=1;
    
    temp->next=curr->next;
    curr->next=temp;
    
    if(flag)
        return temp;
    return last;
}


node *delete(node *last,int pos){

    node *curr=last,*temp;    
        if(curr==NULL){
            printf("No elements to delete\n");
            return NULL;
        }                
        
        int i=0;
        while(i<pos){
            curr=curr->next;
            ++i;
        }
        //delete curr->next
        

       

        if(curr->next==last){
            curr->next=last->next;
            free(last);
            return curr;
        }

        temp=curr->next;
        curr->next=temp->next; 
        free(temp);
        return last;


   /* node *curr=last,*temp;
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
        return last;
    }
    
    temp=curr->next;

    


    curr->next=temp->next;
    (temp->next)->prev=curr;
    free(temp);*/
}