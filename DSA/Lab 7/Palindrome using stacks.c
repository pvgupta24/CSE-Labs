#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100


char stack[SIZE];
int top=-1;
int temp;

int push(char c){
	if(top==SIZE-1){
		printf("Stack full\nCannot insert \n");
		return 0;
	}
	//++top;
	stack[++top]=c;
	return 1;//Success
}

char pop(){
	if(top>=0)
		return stack[top--];
	
	printf("Stack empty...\n");
	exit(0);
}


int main(){
	printf("Check if palindrome using Stacks\n");
	printf("Enter string\n");
	char str[SIZE];
	gets(str);
	int l=strlen(str);
	int i;
	for(i=0;i<l;++i)
		push(str[i]);

	for (i=0;i<l;++i)
	{
		if(pop()!=str[i]){
			printf("Not a palindrome\n");
			exit(0);
		}
	}
	printf("Palindrome\n");

	return 0;
}
