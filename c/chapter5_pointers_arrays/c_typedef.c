#include <cstdio>
#include <stdio.h>
#include <string.h>

typedef int Lenght;
void *malloc(size_t);

Lenght len, maxlen;
Lenght *lengths[];
typedef char *String;

String p, lineptr[10], alloc(int);
int strcmp2(String, String);

typedef struct tnode *Treeptr;
typedef struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
} Treenode;

Treeptr talloc(void) {
    return (Treeptr) malloc(sizeof(Treenode));
};

typedef int (*PFI) (char *, char *);
PFI strump, numcmp;

union u_tag {
    int ival;
    float fval;
    char *sval;
} u;

#define NSYM
struct {
    char *name;
    int flags;
    int utype;
    union {
        int ival;
        float fval;
        char *sval;
    } u;
} symtab[NSYM];

// bit fields
#define KEYWORD 01
#define  EXTRENAL 02
#define STATIC 04

// Or can use enum like this :)
enum { KEYWORD1 = 01, EXTRENAL1 = 02, STATIC1 = 03 };


struct {
    unsigned int is_keyword : 1;
    unsigned int is_extern : 1;
    unsigned int is_static : 1;
} flags;

int main() {
    flags.is_extern = flags.is_static = 1; //on
    flags.is_extern = flags.is_static = 0; // off
    if(flags.is_extern == 0 && flags.is_static == 0) {
    }
    return 0;
}
