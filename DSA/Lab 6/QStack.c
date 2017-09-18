#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int stack[SIZE],tempStack[SIZE];
int top=-1,tempTop=-1;


int push(int c){
	if(top==SIZE-1){
		printf("Stack full \n");
		return 0;
	}
	++top;
	stack[top]=c;
	return 1;//Success
}

int pop(){
	if(top>=0)
		return stack[top--];
	
	printf("Stack empty...\n");
	exit(0);
}

int pushTemp(int c){
	if(tempTop==SIZE-1){
		return 0;
	}
	++tempTop;
	tempStack[tempTop]=c;
	return 1;//Success
}

int popTemp(){
	if(tempTop>=0)
		return tempStack[tempTop--];
	
	printf("Stack empty...\n");
	exit(0);
}




void enque(int data){
	push(data);
}

int deque(){
	if(top==-1){
		printf("Queue is empty.Cant deque.\nExiting.....\n");
		exit(0);
	}

	while(top!=0){
		pushTemp(pop());
	}

	int temp= pop();

	while(tempTop!=-1){
		push(popTemp());
	}
	return temp;

}

void print(){
	int i=0;
	if(top==-1){
		printf("Empty queue\n");
		return;
	}
	printf("Front ---");

	while(i!=top+1){
		printf("%d ---",stack[i] );
		++i;
	}
	printf("END\n");

}




int main(){
	printf("Queue using Stacks\n");
	int c,data;

	again:
	printf("\n1. Enque         2. Deque        Others to exit\n");
	scanf("%d",&c);
	if(c==1){
		printf("Enter data\n");
		scanf("%d",&data);
		enque(data);
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