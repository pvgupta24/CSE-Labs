// Given the set of 'n' distinct numbers. Find the length of the longest monotone increasing sub sequence.

#include <stdio.h>

int main() {
    int n,i;
    printf("Enter no. of elements\n");
    scanf("%d", &n);
    int a[n];

    printf("Enter %d elements\n",n);
    for (i = 0; i < n; scanf("%d", a + i), i++);

    int length = 1, l2 = 1;
    for (i = 1; i < n; i++) {
        if (a[i] > a[i-1]) {
            ++l2;
        } else {
            length = l2 > length ? l2 : length;
            l2 = 1;
        }
    }
    length = l2 > length ? l2 : length;
    printf("Length of max increasing sub sequence is %d\n",length);

    return 0;
}