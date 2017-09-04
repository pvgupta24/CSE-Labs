#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("Binary Search\n");
	int i,j,n,temp;
	printf("Enter n : ");
	scanf("%d",&n);
	printf("Enter %d numbers in ascending order : \n",n);
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

	printf("Enter key to search\n");
	int key; 
	scanf("%d",&key);
	
	int f=0,
		m=(n-1)/2,
		l=n-1;

	while(f<l)
	{
		m=(f+l)/2;
		if(key==a[m])
		{
			printf("%d found at postion %d\n",key,m+1);
			free(a);
			exit(0);
		}
		else if(a[m]<key)
		{
			f=m+1;
		}
		else
		{
			l=m-1;
		}

	}
	printf("Could not find %d in the list\n", key);
	free(a);
	return 0;
}
