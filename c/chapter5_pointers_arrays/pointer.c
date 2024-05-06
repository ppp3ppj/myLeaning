#include <stdio.h>

void swap(int *px, int *py);
int main() {
    //p = &c; // can read p point to c

    // pointer basic
    int x = 1, y = 2, z[10];
    int *ip;
    ip = &x; // ip now point to x
    y = *ip; // y is now 1
    *ip = 0; // x is now 0
    ip = &z[0]; // ip now point to z[0]

    double *dp, atof(char *);
    *ip = *ip + 10;
    y = *ip + 1;
    *ip += 1;
    ++*ip;
    ++(*ip);
    (*ip)++;

    // painter and function arguments
    int a = 4;
    int b = 6;
    swap(&a, &b);
    printf("%d %d", a, b);
}

void swap(int *px, int *py) {
    int temp = 0;
    temp = *px;
    *px = *py;
    *py = temp;
}

/*
 * WRONG
void swap(int x, int y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
    // because of call by value, swap cant affect athe arg
    // it copy of a and b
}
*/
