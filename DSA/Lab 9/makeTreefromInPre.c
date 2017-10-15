#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;

}node;

node *newNode(int data){
	node *temp=(node *)malloc(sizeof(node));
	temp->data=data;
	temp->left=temp->right=NULL;

	return temp;
}

void print(node *head){
	if(head==NULL)
	{
		//printf("NULL");
		return;
	}
	printf("%d(",head->data );
	print(head->left);
	printf(" , ");
	print(head->right);
	printf(")");
}

node *makeTree(int in[], int pre[], int in_start,int in_end,int pre_start,int pre_end){

	if(in_start>in_end || pre_start>pre_end)
		return NULL;

	node *root = newNode(pre[pre_start]);
	int index=-1,i,leftCount=0;

	for(i=in_start;i<=in_end;++i){
		if(in[i]==pre[pre_start]){
			index=i;
			break;
		}
		++leftCount;
	}

	if(index==-1)
	{
		printf("Error with input\nTry again\n Exiting...\n");
		exit(0);
	}

	root->left = makeTree(in,pre,in_start,index-1,pre_start+1,pre_start+leftCount);
	root->right = makeTree(in,pre,index+1,in_end, pre_start+1+leftCount,pre_end);

	return root;
}

int main(){
	printf("Enter no. of elements\n");
	int n,i;
	/*scanf("%d",&n);
	int in[n], pre[n];

	printf("Enter in-fix terms\n");
	for(i-0;i<n;++i)
		scanf("%d",in+i);


	printf("Enter pre-fix terms\n");
	for(i-0;i<n;++i)
		scanf("%d",pre+i);
*/
	n=7;
	int in[]={4,2,5,1,6,3,7};
	int pre[]={1,2,4,5,3,6,7};

	node *root=NULL;
	root = makeTree(in,pre,0,n-1,0,n-1);

	print(root);
	printf("\n--------------------------------\n");
	return 0;
}
