#include <stdio.h>

/*An array A contains (n-1) unique integers in the range [0,n-1],
 that is there is one number from this range that is not in A.
Design an O(n) time algorithm for finding that number. 
You are allowed to use only O(1) additional space besides the array A itself.*/



int main() {
    int n, sum = 0;
    printf("Enter no. of elements\n");
    scanf("%d", &n);
    int a[n];
    a[0] = n;

    printf("Enter %d elements\n", n-1);
    for (; n > 1; --n) {
        scanf("%d", a + a[0]-n+1 );
        sum += a[a[0]-n+1];
    }
    //Sum of n-1 elements
    a[0]=a[0]*(a[0]-1)/2;
    printf("The missing no. is %d\n",a[0]-sum);
    return 0;
}