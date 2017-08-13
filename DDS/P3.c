//Author-pvgupta24

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int charToInt(char c)
{
	return (c>='a')?(c-'a'+10):(c-'0');
}

char intToChar(int c)
{
	return (c>=10)?((c-10)+'a'):(c+'0');
}
	
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

void *sameLengthString(char *input,int maxLen,char *out,int len)
{
	int i,j;
	char temp;	
	i=maxLen-len+1;
	for (j = 0; j<i; ++j)
	{
		out[j]='0';
	}

	for(j=0;j<len;++j,++i)
	{
		out[i]=input[j];
	}
	out[i]='\0';
}

int main()
{	again:
{
	printf("\n-----------------------------------------\n");
	printf("Program to perform (num1)x + (num2)x\n");
	printf("-----------------------------------------\n");

	
	int base;

	printf("Enter the base: ");
	scanf("%d",&base);

	if (base>16||base<1)
	{
		printf("Enter valid base\n");
		return 0;
	}

	char a[25],b[25];
	printf("Enter num1 in base %d : ",base);
	scanf("%s",a);

	printf("Enter num2 in base %d : ",base);
	scanf("%s",b);



	if(!(check(a,base)&&check(b,base)))
		{ 
			printf("Invalid Input for the given base. Try again.\n");
			goto again;
		}

	int temp,carry=0,i;
	int l1=strlen(a);
	int l2=strlen(b);
	int maxLen=(l1>l2) ? l1:l2;
	char x[maxLen+1],y[maxLen+1],output[maxLen+1];
	sameLengthString(a,maxLen,x,l1);
	sameLengthString(b,maxLen,y,l2);
	//printf("%s\n%s\n", x,y);

	for (i = 0; i < maxLen+1; ++i)
	{
		temp	=	charToInt(x[maxLen-i])+charToInt(y[maxLen-i])+carry;
		
		if(temp<base){
			carry=0;
			output[i]=intToChar(temp);
		}
		else{
			carry= 1	;
			output[i]=intToChar(temp-base);
			
		}
	}
	output[i]='\0';
	int len=strlen(output);
	//printf("%s\n", output);
	char t;	int j;

	for ( i = 0; i <= (maxLen+1)/2; ++i)
	{	
		t=output[i];
		output[i]=output[len-1-i];
		output[len-1-i]=t;
	}
	output[len]='\0';
	//printf("yoo%s\n", output);
	printf("The sum (%s)%d + (%s)%d = %s\n",a,base,b,base,output );
	printf("-----------------------------------------\n\n");

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
	
	
}
}
