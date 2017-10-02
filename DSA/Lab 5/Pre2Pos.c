#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#define SIZE 100

char stack[SIZE][SIZE];
int top=-1;

void push(char *c){
	if(top==SIZE-1){
		printf("Stack Overflow");
		exit(0);
	}

	++top;
	strcpy(stack[top], c);//Success
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

char *pop(){
    char *t;
    if(top>=0)
    {   strcpy(t, stack[top--]);
        return t;
    }
	
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
            char c;
            int isOp;	
            char *a,*b;
            //printf("\n%d\n",len);
            for(i=len-1; i>-1; --i){
                c=inf[i];
                isOp = isOperator(c);               

                if(isOp){
                    strcpy(a,pop());
                    strcpy(b,pop());

                    char res[SIZE];
                    char d[2];
                    d[0] = c;
                    d[1] = '\0';
                    strcpy(res, a);
                    strcat(res, b);
                    strcat(res, d);                    
                    push(res);
                }
                else if(isalpha(c)){
                    printf("pushing .. %c",c);
                    char t[2];
                    t[0] = c;
                    t[1] = '\0';
                    push(t);                   
                }

            }
            while(top!=-1){
                printf("%s",pop());
            }
        }