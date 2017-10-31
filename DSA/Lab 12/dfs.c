#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define LOOP(i,n) for(i=0;i<n;++i)
#define IN(i) scanf("%d",&i)

typedef struct node{
	int data;
	struct node *next;
}node;

node *newNode(int data){
	node *temp=(node *)malloc(sizeof(node));
	temp->data=data;
	temp->next=NULL;

	return temp;
}

node **adj;
int SIZE;
int *visited;

void insertConnection(int a,int b){
    node *new =newNode(b);
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
    visited = (int *)calloc(n,sizeof(int));
    int i,a,b;
    LOOP(i,n)
        adj[i]=newNode(i);

    while(1){
        printf("Enter connections fromNode toNode (0 to n) and 0 to stop\n");
        IN(a);
        if(a==0)
            break;
        IN(b);
        --a;
        --b;
        insertConnection(a,b);
    }
}
void printList(){
    int i;
    node *temp;
    LOOP(i,SIZE){
        temp = adj[i];
        while(temp!=NULL){
            printf("%d --> ", temp->data);
            temp=temp->next;
        }
        printf("NULL\n");           
    }

}

void dfs(node *a){
    if(visited[a->data])
        return;
    visited[a->data]=1;
    printf("%d =====> ",a->data+1);
    node *temp=adj[a->data]->next;
    while(temp!=NULL){
        dfs(adj[temp->data]);
        temp=temp->next;
    }
}
void depthSearch(){
    int i;
    LOOP(i,SIZE){
        if(!visited[i])
            dfs(adj[i]);
    }
    printf("DONE\n");
}

int main(){
    printf("DFS\n---\n");
    createList();
    printList();
    printf("Depth Search is : \n");
    depthSearch();
    return 0;
}
