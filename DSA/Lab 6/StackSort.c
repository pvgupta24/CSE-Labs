#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100


int stack[SIZE];
int top=-1;
int temp;

int push(char c){
	if(top==SIZE-1){
		printf("Stacks will collash..\nCannot insert \n");
		return 0;
	}
	//++top;
	stack[++top]=c;
	return 1;//Success
}

int pop(){
	if(top>=0)
		return stack[top--];
	
	printf("Stack 1 empty...\n");
	exit(0);
}
int peek(){
    if(top!=-1)
        return stack[top];
    printf("Stack 1 empty...\n");
    exit(0);
}

void insert(int item){
	if(top==-1 || item >= peek()){
		push(item);
	}
	else{
		int temp=pop();
		insert(item);
		push(temp);
	}
	
}

void sort(){

	if(top ==-1){
		return;
	}
	int item=pop();
	sort();
	insert(item);

}


void print(){
	int i=0;
	if(top==-1){
		printf("Empty stack\n");
		return;
	}

	while(i!=top+1){
		printf("%d ---> ",stack[i] );
		++i;
	}
	printf("TOP\n");

}
int main(){

	printf("Sorting stack using recursion\n");

	push(1);
	push(5);
	push(3);
	push(2);

	sort();
    print();
    
	return 0;
}
