//Finding loop in LL and no. of elements

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

int isLoop(node *head);
int main(){
printf("Loop in Linked List\n");
    
node *head=NULL;

node *a=(node *)malloc(sizeof(node));
a->data=1;
head=a;
a->next=NULL;

node *b=(node *)malloc(sizeof(node));
b->data=2;
a->next=b;
b->next=NULL;

node *c=(node *)malloc(sizeof(node));
c->data=3;
b->next=c;
c->next=NULL;

node *d=(node *)malloc(sizeof(node));
d->data=1;
//c->next=d;
d->next=b;


int x= isLoop(head);
if(x==-1)
    printf("No Loop\n");
else
    printf("Loop present.\n %d elements in LL   \n",x);

}
int isLoop(node *head){

    node *walk=head,*hop=head;
    int count=0,loop=0;
    while(walk != NULL && hop !=NULL && (walk=walk->next) !=NULL && (hop->next)!=NULL && (hop=hop->next->next)!=NULL){
        
        if(walk == hop){
            loop=1;
            break;
        }
        ++count;
    }
    if(loop){
        node *temp =walk;
        while((walk=walk->next) != temp){
            ++count;
        }
    }
    else
        count=-1;
    return count;
}

int size(node *head){

}