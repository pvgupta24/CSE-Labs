#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define LOOP(i,n) for(i=0;i<n;++i)
#define IN(i) scanf("%d",&i)


typedef struct node
{
	int data;//Node no.
    int rank;//Weight of edge
    
	//Lower rank higher 
	struct node *next;

}node;


node *newNode(int data,int rank){
	node *temp=(node *)malloc(sizeof(node));
    temp->data=data;
    temp->rank=rank;
	temp->next=NULL;
	return temp;
}

node *PQ=NULL;

node *enqueue(node *head, int data, int rank){
	node *temp = newNode(data,rank);

	if(head==NULL)
		return temp;
	
    node *curr=head,*prev=curr;
    
    int i = curr->rank;
    
	if(i > rank){
		temp->next=head;
		return temp;//At the start
	}
	while(i<=rank && curr->next !=NULL ){
		prev = curr;
		curr = curr->next;
		i = curr->rank;
	}
	if(i<=rank){
		temp->next=curr->next;
		curr->next=temp;
	}
	else{
		temp->next=prev->next;
        prev->next=temp;    
	}
	return head;
    
}

node *deque(node *head){
    if(head==NULL){
        printf("P.Q already empty\n");
        return head;
    }
    node *temp=head->next;
    //printf("(%d,%d) dequed\n",head->data,head->rank );
    temp = head;
    PQ = head->next;
    return temp;
}

int SIZE;
node **adj;
int *visited;
int sum=0;

void insertConnection(int a,int b,int weight){
    node *new = newNode(b,weight);
    node *curr = adj[a];
    while(curr->next !=NULL){
        if(curr->data == b)
            return;
        curr=curr->next;
    }
    curr-> next = new;
}
void createList(){
    int n;
    printf("Enter No. of nodes\n");
    IN(n);
    SIZE = n;
    adj = (node **)malloc(n * sizeof(node*));
    visited = (int *)calloc(n,sizeof(int));//0 initially

    int i,a,b,wt;

    LOOP(i,n)
        adj[i]=newNode(i,0);

    while(1){
        printf("Enter connections fromNode toNode (1 to n) , weight and 0 to stop\n");
        IN(a);
        if(a==0)
            break;
        IN(b);
        --a;
        --b;
        IN(wt);

        //Undirected

        insertConnection(a,b,wt);
        insertConnection(b,a,wt);      

    }

}
void printList(){
    int i;
    node *temp;
    LOOP(i,SIZE){
        temp = adj[i];
        while(temp!=NULL){
            printf("(%d,%d,%d) --> ", i+1 , temp->data+1 , temp->rank);
            temp=temp->next;
        }
        printf("NULL\n");           
    }
}

void prim(){
    PQ=enqueue(PQ,0,0);
    node *curr,*y;
    while(PQ!=NULL){
        curr = deque(PQ);
        if(visited[curr->data])
            continue;
        visited[curr->data]=1;
        sum+=curr->rank;
        printf("%d , %d\n",curr->data+1,curr->rank);
        y = (adj[curr->data])->next;
        while(y!=NULL)
        {
            PQ=enqueue(PQ,y->data,y->rank);
            y=y->next;
        }
    }
}


int main(){
    printf("MST using Prim\n---\n");
    createList();
    printList();    
    printf("\nTree\n===================\n");
    prim();
    printf("Sum of weights = %d\n\n",sum);

    return 0;
}
