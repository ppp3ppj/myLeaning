#include <stdio.h>

#define ALLOCSIZE 1000

static char allocbuf[ALLOCSIZE]; // storage for alloc
static char *allocp = allocbuf; // next free position

char *alloc(int n) {
    if(allocbuf + ALLOCSIZE - allocp >= n) { // it fits
        allocp += n;
        return allocp - n;
    } else {
        return 0;
    }
}

char afree(char *p) {
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
