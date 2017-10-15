#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

#define SIZE 100
typedef struct node{
	char data;
	struct node *left;
	struct node *right;

}node;

node *newNode(char data){
	node *temp=(node *)malloc(sizeof(node));
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}

void print(node *head){
	if(head==NULL)
	{	//printf("NULL");
		return;
	}
	printf("%c(",head->data );
	print(head->left);
	printf(" , ");
	print(head->right);
	printf(")");
}


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

char pop(){
	if(top>=0)
		return stack[top--];
	
	printf("Invalid Popping...\n");
	exit(0);
}

node *node_stack[SIZE];
int node_top=-1;

void node_push(node *c){
	if(node_top==SIZE-1){
		printf("node_ Stack Overflow");
		exit(0);
	}

	++node_top;
	node_stack[node_top]= c;//Success
}

node *node_pop(){
	if(node_top>=0)
		return node_stack[node_top--];
	
	printf("Invalid Popping...\n");
	exit(0);
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



int main(){

	puts("Infix to Postfix");
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

			push(c);
		}
		else if(c==')'){
			while((temp=pop())!='('){
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
		if(temp!='(')
		post[j++]=temp;
	}
	post[j]='\0';
	printf("-----------------\n%s\n--------------\n",post );

	node *root=NULL,*tempNode;
	for (i = 0; i < len; ++i)
	{	c=post[i];
		if(isalpha(c)){
			node_push(newNode(c));
		}
		if(isOperator(c)){
			tempNode = newNode(c);
			tempNode->left= node_pop();
			tempNode->right= node_pop();
			node_push(tempNode);
		}
	}
	root=node_pop();
	print(root);
	printf("\n");
}
