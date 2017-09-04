//Design  and implement a recursive algorithm to solve the Tower of Hanoi problem for one or more disks.

#include <stdio.h>

#define movePrint(DISK, INITIAL, FINAL) printf("Move disk %d from %c to %c\n",DISK,INITIAL,FINAL)

void solve(int n, char from, char intermediate, char to) {

    if(n==0)
        return;

    if (n == 1) {
        movePrint(n, from, to);
        return;
    }
    //Top disks to intermediate peg
    solve(n - 1, from, to, intermediate);

    //Move nth disk
    movePrint(n, from, to);

    //Intermediate disks to final peg
    solve(n - 1, intermediate, from, to);
}

int main() {
    int n = 0;
    printf("Enter no. of disks\n");

    scanf("%d", &n);
    if (n < 0) {
        printf("Enter n>=1\n");
        return 0;
    }
    solve(n, 'A', 'B', 'C');
    printf("---------Solved -------\n");
    return 0;
}
