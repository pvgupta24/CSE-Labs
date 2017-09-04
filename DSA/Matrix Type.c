#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

	printf("Enter n for n*n square matrix\n");
	int n;
	scanf("%d",&n);
	int row,col;
	int **mat=(int **)malloc(sizeof(int *));

	for (row = 0; row < n; ++row)
	{
		mat[row]=(int *)malloc(n*sizeof(int));
	}


	for (row = 0; row < n; ++row)
	{
		for (col = 0; col < n; ++col)
		{
			scanf("%d",&mat[row][col]);
		}
	}

	int isUpper=1,isLower=1,isDiag=1;

	for (row = 0; row < n; ++row)
	{
		for (col = 0; col < n; ++col)
		{
			if(isDiag)
				if(row!=col && mat[row][col]!=0)
					isDiag=0;

			if(isLower)
				if(col>row && mat[row][col]!=0)
					isLower=0;

			if(isUpper)
				if(col<row && mat[row][col]!=0)
					isUpper=0;

		}
	}
	if(isUpper)
		printf("The matrix is a Upper matrix\n");
	if(isLower)
		printf("The matrix is a Lower matrix\n");
	if(isDiag)
		printf("The matrix is a diagonal matrix\n");	
	if(!isDiag && !isLower && !isUpper)
		printf("None\n");		


	free(mat);
	return 0;

}
