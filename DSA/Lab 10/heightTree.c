#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define in(n) scanf("%d",&n)
#define pf(n) printf("%d ",n)

int main(){
    int n;
    printf("Enter n\n");
    in(n);
    int h=ceil(log2(n));
    pf(h);
    printf("\n");
    return 0;
}
