#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

//Check if No. is valid in given base
int check(char* input,int base)
{

	 int i,len=strlen(input);
	 char max=	(base>0&&base<=10)	?	(base-1+'0')	:	((base-10)+'a');
	 for (i = 0;  i<len ; i++) {
	        if(input[i]>max)
	            return 0;
	    } 
	  //Valid
	  return 1;
}

//Converts given no to decimal
int toDecimal(char *input, int base) {
	    int len = strlen(input);
	    int i, decimal = 0;
	
	    for (i = len - 1; i >= 0; i--) {
	        decimal += round(pow(base, len - i - 1)) *
	                   (int) ((input[i] >= '0' && input[i] <= '9') ? (input[i] - '0') : (input[i] - 'a'+10));
	    }
	    return decimal;
	}
char *out;

//Converts decimal to given base
char* toBase(int decimal, int baseY) {
	    char output[100];
	    int temp = 0, i = 0, j;
	    while (decimal) {
	        temp = decimal % baseY;
	       
	        output[i] = (temp < 10) ? ((char) temp + '0') : ((char) (temp - 10) + 'a');
	        
	        ++i;
	        decimal /= baseY;
	    }
	    out=(char*)malloc(i*sizeof(char));
	    for (j = 0; j < i; j++)
	        out[j] = output[i - 1 - j];
	    out[j]='\0';
	   
	   return out;
	   }

int main()
{
	//Label
	again:
	printf("\n-----------------------------------------\n");
	printf("Program to find r and (r-1)'s complement\n");
	printf("-----------------------------------------\n");
	printf("Enter the base (r) : ");
	int base;
	scanf("%d",&base);
	char a[100];
	printf("Enter the number :");
	scanf("%s",a);

	if(!check(a,base))
		{ 
			printf("Invalid Input for the given base. Try again.\n");
			goto again;
		}
	int n=strlen(a);

	//To find r's complement by r^n - N, where n is no. of digits and N is the given number
	toBase((pow(base,n)-toDecimal(a,base)),base);
	printf("The %d's complement of %s is %s\n",base,a,out);

	//To find r-1's complement by r^n - N - r^-m
	//where n is no. of characteristic digits, m is the no. of mantissa digits and N is the given number
	toBase((pow(base,n)-toDecimal(a,base)-1),base);
	printf("The %d's complement of %s is %s\n",base-1,a,out);

	char c;
	printf("Do you want to continue (y/n) ?\n");
	getchar();
	scanf("%c",&c);

	if (c=='n'||c=='N')
	{
		return 0;	
	}
	else
	{
		goto again;
	}
	return 0;
}
