//Given a randomly ordered array of ' n' elements. Determine the kth smallest element in the set.
#include <stdio.h>

void partition(int a[], int low, int high);

int main() {
    int n, k, i;
    printf("Enter n : ");
    scanf("%d", &n);

    //Input
    int a[n];
    for (i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    printf("\nEnter k : ");
    scanf("%d", &k);
    //k starts from 0
    --k;

    if (k < 0 || k > n - 1) {
        printf("Invalid k\n");
        return 0;
    }

    //a[last] will be the pivot
    int low = 0, high = n - 1;

    //Quick Select using partitions
    while (1) {
        partition(a, low, high);
        if (a[high] == a[k])
            break;
        else if (a[high] > a[k])
            --high;
        else
            ++low;
    }
    printf("The %dth smallest element is %d\n", k, a[k]);
    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low, j;  // Index of smaller element

    for (j = low; j <= high - 1; ++j) {
        // Place smaller elements at start by swapping with the ith element.
        if (a[j] <= pivot) {
            if (i != j)
                swap(a + i, a + j);
            ++i;
        }
    }
    //swapping pivot with the first no greater than it
    swap(a + i, a + high);
    //return i+1
}