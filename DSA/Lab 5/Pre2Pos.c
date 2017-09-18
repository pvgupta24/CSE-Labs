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
        
            puts("Prefix to Postfix");
            char inf[SIZE];
            gets(inf);
            int i,isOP;
            int len = strlen(inf);
            int j=0;
            char post[SIZE];
            char temp=' ',c;
            int isOp;	
            char a,b;
            //printf("\n%d\n",len);
            for(i=len-1; i>-1; --i){
                c=inf[i];
                isOp = isOperator(c);               

                if(isOp){
                    a=pop();
                    b=pop();
                    push(c);             
                    push(b);
                    push(a);
                }
                else if(isalpha(c)){
                    //printf("pushing .. %c",c);
                    push(c);
                    
                }

            }
            while(top!=-1){
                printf("%c",pop());
            }
        }