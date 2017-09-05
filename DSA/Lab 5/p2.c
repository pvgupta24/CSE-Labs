#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#define SIZE 100

double stack[SIZE];
int top=-1;

int push(char c){
	if(top==SIZE-1){
		return 0;
	}

	++top;
	stack[top]=c;
	return 1;//Success
}

double pop(){
	if(top>=0)
		return stack[top--];
	
	printf("Invalid Expression...\n");
	exit(0);
	}

int isOperator(char c){
	

	if (c=='+')
		return 1;
	if (c=='-')
		return 2;
	if (c=='*')
		return 3;
	if (c=='/')
		return 4;
	if (c=='^')
		return 5;

	return 0;
}

int main(){
	puts("\nPRE-FIX evaluation\nEnter no. of variables\n");
	int n;
	scanf("%d",&n);
	double var[n];
	int i=0;

	for(i=0;i<n;++i){
		printf("Enter %c  :  ", 'a'+i);
		scanf("%lf",var+i);
	}

	char exp[SIZE];
	printf("Enter pre-fix expression :\n");
	getchar();

	gets(exp);

	int len = strlen(exp);
	char c;
	int isOp=0;
	double a,b;

	for(i=len-1;i>-1;--i){
		c=exp[i];

		isOp = isOperator(c);

		if(isOp)
		{	
			a=pop();
			b=pop();
			switch(isOp){
				case 1:
					push(a+b);
					break;
				case 2:
					push(a-b);
					break;
				case 3:
					push(a*b);
					break;
				case 4:
					push((double)a/b);
					break;
				case 5:
					push(pow(a,b));
					break;

			}
		}

		else if(isalpha(c)){
			push(var[c-'a']);
		}

		else{
			printf("Invalid expression.\n");
			exit(0);
		}

	}

	printf("Value = %0.3lf\n",pop());

return 0;
}