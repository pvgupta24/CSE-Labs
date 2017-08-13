#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	printf("Enter n for n*n upper triangular square matrix\n");
	int n;
	scanf("%d",&n);
	int n1=n;
	int i=0,row,col;
	int temp;
	int *a=(int *)malloc(((n+1)*n/2)*sizeof(int));

	printf("Row major form\nEnter the matrix:\n");
	for (row = 0; row < n; ++row)
	{
		for (col = 0; col < n; ++col)
		{
			scanf("%d",&temp);
			if(row<=col)
				a[i++]=temp;			
		}
	}

	printf("Enter row,col for the required element\n");
	scanf("%d%d",&row,&col);
	--row;
	--col;
	temp=0;
	if(row>col)
		printf("0\n");
	else
	{
		for(i=0;i<row;++i)
		{
			temp+=n1;
			--n1;
		}
		temp+=col-row;
		printf("%d\n",a[temp] );
	}

	


	i=0;
	
	printf("Column major form\nEnter the matrix:\n");
	for (row = 0; row < n; ++row)
	{
		for (col = 0; col < n; ++col)
		{
			scanf("%d",&temp);
			if(row<=col)
				a[col*(1+col)/2+row]=temp;

				//a[row+col+col-((col%3)?1:0)]=temp;			
		}
	}

	printf("Enter row,col for the required element\n");
	scanf("%d%d",&row,&col);
	--row;
	--col;
	temp=0;

	if(row>col)
		printf("0\n");
	else
	{
		temp=col*(col+1)/2;
		temp+=row;
		printf("%d\n",a[temp] );
	}


free(a);
return 0;
}
