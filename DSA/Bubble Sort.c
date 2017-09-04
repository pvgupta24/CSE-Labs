#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("Bubble Sort\n");
	int i,j,n,temp;
	printf("Enter n : ");
	scanf("%d",&n);
	printf("Enter %d numbers : \n",n);
	int *a=(int *)malloc(n*sizeof(int));
	if(a==NULL)
	{
		printf("Could not allocate memory.. Exiting....\n");
		exit(0);
	}
	for (i = 0; i < n; ++i)
	{
		scanf("%d",a+i);
	}

	//Binary Sort
	for (i = 0; i < n-1; ++i)
	{	
			for (j = 0; j<n-1-i; ++j)
			{
				if(a[j]>a[j+1])
				{
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
	}
	printf("Binary Sorted List : \n");
	for (i = 0; i < n; ++i)
	{
		printf("%d\n",*(a+i));
	}
	free(a);
	return 0;
}
