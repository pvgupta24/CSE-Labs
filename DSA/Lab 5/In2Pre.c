#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#define SIZE 100

char stack[SIZE];
int top=-1;

void push(char c){
	if(top==SIZE-1){
		printf("Stack Overflow");
		exit(0);
	}

	++top;
	stack[top]=c;//Success
}

int isOperator(char c){
	

	if (c=='+')
		return 1;
	if (c=='-')
		return 1;
	if (c=='*')
		return 2;
	if (c=='/')
		return 2;
	if (c=='^')
		return 3;

	return 0;
}

char pop(){
	if(top>=0)
		return stack[top--];
	
	printf("Invalid Popping...\n");
	exit(0);
	}

int main(){

	puts("Infix to Prefix");
	char inf[SIZE];
	gets(inf);
	int i,isOP;
	int len = strlen(inf);
	int j=0;
	char post[SIZE];
	char temp=' ',c;
	int isOp;	

	for(i=0;i<len;++i){
		c=inf[i];
		isOp = isOperator(c);

		if(c=='('){
			//printf("Pushing %c\n",c);
			push(')');
		}
		else if(c==')'){
			while((temp=pop())!=')'){
				//printf("K--");
					post[j++]=temp;
			}
		}

		else if(isOp){
			while(top>=0 && isOp<=isOperator((temp=pop()))){
				post[j++]=temp;
			}
			if(top>=-1)
				push(temp);
			
			//printf("Pushing %c\n",c);
			push(c);
		}

		else if(isalpha(c))
		{
			post[j++]=c;
		}

		else{

		}
		
	}

	while(top>=0){
		temp=pop();
		if(temp!=')')
		post[j++]=temp;
	}
	post[j]='\0';
	printf("Pre-Fix :\n%s\n",post);

}