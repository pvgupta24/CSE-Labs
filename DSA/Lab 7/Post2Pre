
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char stack[10000][10000];
int top  = -1;

char t[100];

void push(char *c){
	strcpy(stack[++top], c);
}

char * pop(){
	return stack[top--];
}


int isOp(char c){
	
	if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%'){
		return 1;
	}
	return 0;
}

void main(){
	
	char s[100];
	
	printf("Post-Pre\nEnter Postfix Expression: ");
	scanf("%s", s);
	char op[2];
	op[1] = '\0';
	int i;char c;
	for (i =0 ; i <strlen(s); i++){
		c=s[i];
		if (isOp(c)){
		
			op[0] = c;
			char res[100];
			res[0]='\0';
			
			char b[100];

			strcpy(b, pop());
			strcat(res, op);
			strcat(res,pop());
			strcat(res,b);			
			push(res);		
			
		}
		else{
			char t[2];
			t[0] = c;
			t[1] = '\0';
			push(t);
		}		
	
	}
	
	printf("\n%s\n", pop());
	
}
