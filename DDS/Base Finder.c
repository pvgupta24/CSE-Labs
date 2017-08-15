//Author-pvgupta24

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

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
                   (int) ((input[i] >= '0' && input[i] <= '9') ? (input[i] - '0') : (input[i] - 'a' + 10));
    }
    return decimal;
}

int main() {
    printf("Program  : To find X,Y  if  A in base X =B in base Y\n");

    char a[25], b[25];
    printf("Enter A : ");
    scanf("%s", a);

    printf("Enter B : ");
    scanf("%s", b);

    int i, j;
    int found = 0;

    for (i = 1; i <= 36; i++) {
        for (j = 1; j <= 36; j++) {
            if (!check(a, i) && !(check(b, i))) {
                if (toDecimal(a, i) == toDecimal(b, j)) {
                    printf("%s in base %d = %s in base %d\n", a, i, b, j);
                    found = 1;
                }
            }
        }
    }
    if (!found)
        printf("Not Found\n");
    return 0;
}

