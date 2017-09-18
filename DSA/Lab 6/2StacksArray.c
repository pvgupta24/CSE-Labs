#include<stdio.h>
#include<stdlib.h>
#define SIZE 8


int stack[SIZE],stack1[SIZE];
int top=-1,top1=SIZE;

int push(int c){
	if(top==top1-1){
		printf("Stacks will collash..\nCannot insert \n");
		return 0;
	}
	++top;
	stack[top]=c;
	return 1;//Success
}

int pop(){
	if(top>=0)
		return stack[top--];
	
	printf("Stack 1 empty...\n");
	exit(0);
}


int push1(int c){
	if(top==top1-1){
		printf("Stacks will collash..\nCannot insert \n");
		return 0;
	}
	--top1;
	stack1[top1]=c;
	return 1;//Success
}

int pop1(){
	if(top1<SIZE)
		return stack1[top1++];
	
	printf("Stack 2 empty...\n");
	exit(0);
}

void printStacks(){
	int i=0,j=SIZE-1;
	printf("STACK 1\n");

	while(i!=top+1){
		printf("%d ---",stack[i] );
		++i;
	}
	printf("TOP\n\n");
	printf("STACK 2\n");

	while(j!=top1-1){
		printf("%d ---",stack1[j] );
		--j;
	}
	printf("TOP\n");
}

int main(){
	printf("2 Stacks in array\n");
	int c,data;

	again:
	printf("\n1. Push in 1         2. Pop from 1        \n3. Push in 2         4. Pop from 2        \nOthers to exit\n");
	scanf("%d",&c);
	if(c==1){
		printf("Enter data\n");
		scanf("%d",&data);
		push(data);
	}
	else if(c==2){
		printf("%d removed from stack 1\n", pop() );
	}
	else if(c==3){
		printf("Enter data\n");
		scanf("%d",&data);
		push1(data);

	}
	else if(c==4){
		printf("%d removed from stack 2\n", pop1() );
	}
	else{
		return 0;
	}
	printStacks();
	goto again;


	return 0;

}