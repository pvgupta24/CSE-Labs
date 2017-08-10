#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("Matrix Multiplication\n");	
	int r[2],c[2];
	printf("Enter r1,c1,r2,c2\n");
	scanf("%d%d%d%d",&r[1],&c[1],&r[2],&c[2]);


	if (c[1]!=r[2])
	{
		printf("C1 not equals r2.. exiting..\n");
		exit(0);
	}

	int *a=(int *)malloc(r[1]*c[1]*sizeof(int));
	int *b=(int *)malloc(r[2]*c[2]*sizeof(int));
	if(a==NULL||b==NULL)
	{
		printf("Could not allocate memory..\n");
		exit(0);
	}
	int row,col;
	
	for(row=0;row<r[1];row++)
	{
		for(col=0;col<c[1];col++)
		{
			scanf("%d",a+c[1]*row+col);
		}
	}

	for(row=0;row<r[2];row++)
	{
		for(col=0;col<c[2];col++)
		{
			scanf("%d",b+c[2]*row+col);
		}
	}
	
	int i,j;
	int *ans=(int *)malloc(r[1]*c[2]);

	for (i=0;i<c[2];i++)
	{
		for(row=0;row<r[1];row++)
		{
			*(ans+i+row)=0;
			for (col = 0; col<c[1];col++)
			{		
				*(ans+i+row)+=(*(a+c[1]*row+col))*(*(b+i+col*c[2]));		

			}
		}
	}
	printf("Output: \n");
	for (row=0;row<r[1];row++,printf("\n"))
	{
		for (col=0;col<c[2];col++)
		{
			printf("%d ",*(ans+row*c[2]+col));
		}
	}

free(a);
free(b);

	return 0;
}
