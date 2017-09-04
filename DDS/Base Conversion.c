
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


char *out;


int check(char *input, int base) {
    int i, len = strlen(input);
    char max = (base >= 0 && base <= 10) ? (base - 1 + '0') : ((base - 10) + 'a');
    for (i = 0; i < len; i++) {
        if (input[i] > max)
            return 1;
    }
    return 0;
}

int toDecimal(char *input, int base) {
    int len = strlen(input);
    int i, decimal = 0;

    for (i = len - 1; i >= 0; i--) {
        decimal += round(pow(base, len - i - 1)) *
                   (int) ((input[i] >= '0' && input[i] <= '9') ? (input[i] - '0') : (input[i] - 'a'+10));
    }
    return decimal;
}



char* toBaseY(int decimal, int baseY) {
    char output[25];
    int temp = 0, i = 0, j;
    while (decimal) {
        temp = decimal % baseY;
       //printf("mod is %d\n", temp);
        output[i] = (temp < 10) ? ((char) temp + '0') : ((char) (temp - 10) + 'a');
        printf("%c", output[i]);
        ++i;
        decimal /= baseY;
    }
    out=(char*)malloc(i*sizeof(char));
    for (j = 0; j < i; j++)
        out[j] = output[i - 1 - j];
    out[j]='\0';
    //printf("ans is %s\n", out);

    return out;
}
int main()
{
//check to check if input is correct
//toDecimal and toBaseY
    printf("Program to find Output if (A)BaseX=(B)BaseY\n");
    printf("Enter A\n");
    char a[100],b[100];
    int x,y;
    scanf("%s",a);

    printf("Enter X\n");
    scanf("%d",&x);

    printf("Enter Y\n");
    scanf("%d",&y);

    toBaseY(toDecimal(a,x),y);
    printf("%s",out);
    return 0;
}
