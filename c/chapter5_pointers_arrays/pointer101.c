#include <stdio.h>

int main() {
    // dcl
    char **argv; // argv: pointer to char
    int (*daytab)[13]; // daytab: pointer to array[13] of int
    int *daytab2[13]; // daytab: array[13] of pointer to int
    void (*comp)(); // comp: pointer to func return void
    void *comp2(); // comp2: func return pointer to void
    char (*(*x())[])(); // x: func return pointer to array[] of pointer to func return char
    char (*(*y[3])())[5]; // y: array[3] of pointer to func return pointer to array[5] of char
    return 0;
}
