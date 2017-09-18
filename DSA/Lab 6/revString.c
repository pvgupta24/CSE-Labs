#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100


char stack[SIZE];
int top=-1;

int push(char c){
	if(top==SIZE-1){
		printf("Stacks will collash..\nCannot insert \n");
		return 0;
	}
	//++top;
	stack[++top]=c;
	return 1;//Success
}

char pop(){
	if(top>=0)
		return stack[top--];
	
	printf("Stack 1 empty...\n");
	exit(0);
}

int main(){

	printf("Reverse string using stacks\n");
	printf("Enter string\n");


	int i=0;
	char str[SIZE];
	gets(str);
	int len=strlen(str);

	for(i=0;i<len;i++){
		push(str[i]);
	}
	for(i=0;i<len;i++){
		str[i]=pop();
	}

	printf("Reverse String is %s\n",str );
}