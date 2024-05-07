#include <stdio.h>

int strlenLength(char *s);
int main() {
    int *pa;
    //pa = &a[0]; // ismean pa to point to element zero of a; address of a[0]
    // if assume: *(pa + 1) -> go next 1 address
    // if assume: *(pa + 2) -> go next 2 address
    // or can write
    // pa = a; // it equal pa = &a[0]
    int s_len = strlenLength("hello world");
    printf("%d", s_len);
    return 0;
}

// char s[]; and char *s; // are equivalent
int strlenLength(char *s) {
    int n;
    for (n = 0; *s != '\0'; s++ )
         n++;
    return n;
}
