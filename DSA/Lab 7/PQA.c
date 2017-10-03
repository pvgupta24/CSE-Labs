#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int q[SIZE];
int rank[SIZE];

int f=-1,r=-1;

void enque(int data,int ran){
	if(f==-1)
	{
        q[0]=data;
        rank[0]=ran;
		f=0;
		r=0;
	}
	else if(( (r+1)%SIZE) != f ){

        int i = r;

        while(rank[i]>ran && i>=f){
            rank[(i+1) % SIZE]=rank[i];
            q[(i+1) % SIZE]=q[i];
            i=(i+SIZE-1) % SIZE;
        }

		r=(r+1)%SIZE;
        q[i]=data;
        rank[i]=ran;
	}
	else
	{
		printf("Queue is full.Cant enque.\n");
		return;
	}
}

int deque(){
	if(f==-1){
		printf("Queue is empty.Cant deque.\nExiting.....\n");
		exit(0);
	}
	if(f==r){
		int temp=q[f];
		f=-1;
		r=-1;
		return temp;
	}
	return q[(f++)%SIZE];

}

void print(){
	int i=f;
	if(f==-1){
		printf("Empty queue\n");
		return;
	}
	printf("Front ---");
	while(i!=(r)%SIZE ){
			printf("(%d,%d) ---",q[i],rank[i] );
			i=(i+1)%SIZE;
    }
	printf("(%d,%d) ---",q[i],rank[i] );         
	printf("END\n");
}


int main(){
	printf("Priority Queue using Array\n");
	int c,data,ran;

	again:
	printf("\n1. Enque         2. Deque        Others to exit\n");
	scanf("%d",&c);
	if(c==1){
		printf("Enter data, rank\n");
		scanf("%d%d",&data,&ran);
		enque(data,ran);
	}
	else if(c==2){
		printf("%d removed from queue\n", deque() );
	}
	else{
		return 0;
	}
	//printf("f=%d\nr=%d\n\n",f,r );
	print();
	goto again;


	return 0;
}