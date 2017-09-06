#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("Matrix Multiplication\n");	
	int r1,c1,r2,c2;
	printf("Enter r1,c1,r2,c2\n");
	scanf("%d%d%d%d",&r1,&c1,&r2,&c2);


	if (c1!=r2)
	{
		printf("C1 not equals r2.. exiting..\n");
		exit(0);
	}

	int *a=(int *)malloc(r1*c1*sizeof(int));
	int *b=(int *)malloc(r2*c2*sizeof(int));
	if(a==NULL||b==NULL)
	{
		printf("Could not allocate memory..\n");
		exit(0);
	}
	int row,col;
	
	for(row=0;row<r1;row++)
	{
		for(col=0;col<c1;col++)
		{
			scanf("%d",a+c1*row+col);
		}
	}

	for(row=0;row<r2;row++)
	{
		for(col=0;col<c2;col++)
		{
			scanf("%d",b+c2*row+col);
		}
	}
	
	int i,j,k;
	int *ans=(int *)malloc(r1*c2);

	
	/*for(i=0;i<r1;++i){

		for(j=0;j<c2;++j){

			ans[i*c2+j]=0;

			for(k=0;k<c1;++k){

				ans[i*c2+j]+=	a[i*c1+k] * b[k*r2+j];

			}
		}
	}*/
	
	
	for ( i = 0; i < r1; i++) {
        for ( j = 0; j <c2; j++) {
            int sum = 0;
			for (k = 0; k < r2; k++)
			{	
			printf("Yo\n");
			
                sum = sum + a[i * c1 + k] * b[k * c2 + j];}
            ans[i * c2 + j] = sum;
        }

	}
	

/*
	for (i=0;i<c2;i++)
	{
		for(row=0;row<r1;row++)
		{
			*(ans+i+row)=0;
			for (col = 0; col<c1;col++)
			{		
				*(ans+i+row*r1)+= (*(a+c1*row+col))*(*(b+i+col*c2));		
				//k[4*x+y] += i[4*x+z] * j[4*z+y];

				//*(ans+4*i+row)+=(*(a+4*i+col))*(*(b+4*col+row));
			}
		}

	}
	*/
	printf("Output: \n");
	for (row=0;row<r1;row++,printf("\n"))
	{

		for (col=0;col<c2;col++)
		{
			printf("%d ",*(ans+row*c2+col));
		}
	}

free(a);
free(b);
free(ans);

	return 0;
}
