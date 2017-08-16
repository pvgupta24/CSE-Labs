
//Design an algorithm for power evaluation that is built upon a base 3 strategy rather that the current base 2 method.
//Compare the result for this new method with the current algorithm.


#include <stdio.h>
int power2(int x, int n);
int power3(int x, int n);

int main() {
    printf("x power n\n");
    int n, x;
    printf("Enter x : \n");
    scanf("%d", &x);
    printf("Enter n : \n");
    scanf("%d", &n);

    printf("Power evaluation - Base 2 : %d^%d = %d\n", x, n, power2(x, n));
    printf("Power evaluation - Base 3 : %d^%d = %d\n", x, n, power3(x, n));

    return 0;
}
int power2(int x, int n) {
    if (n == 1)
        return x;
    if (n == 0)
        return (long)1;

    if (n % 2 == 0) {
        long half = power2(x, n / 2);
        return half * half;
    }
    long half = power2(x, (n - 1) / 2);
    return x * half * half;

}

int power3(int x, int n) {
    if (n == 1)
        return x;
    if (n == 0)
        return 1;

    if (n % 3 == 0) {
        long third = power3(x, n / 3);
        return third * third * third;
    }
    if (n % 3 == 1) {
        long third = power3(x, (n - 1) / 3);
        return x * third * third * third;
    }
    long third = power3(x, (n - 2) / 3);
    return x * x * third * third * third;
}
