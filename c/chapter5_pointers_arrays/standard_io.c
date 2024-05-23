#include <stdio.h>
#include <stdlib.h>

void scanfBasic();

int cancatenateFileV1(int , char *[]);
int cancatenateFileV2ErrorHandling(int , char *[]);
int main(int argc, char *argv[]) {

    //cancatenateFileV1(argc, argv);
    cancatenateFileV2ErrorHandling(argc, argv);
    return 0;
}

int cancatenateFileV1(int argc, char *argv[]) {
    FILE *fp;
    void filecopy(FILE *, FILE *);

    if(argc == 1)
        filecopy(stdin, stdout);
    else
        while(--argc > 0)
            if((fp = fopen(*++argv, "r")) == NULL) {
                printf("cat: can't open %s\n", *argv);
                return 1;
            } else {
                filecopy(fp, stdout);
                fclose(fp);
            }
    return 0;
}

int cancatenateFileV2ErrorHandling(int argc, char *argv[]) {
    FILE *fp;
    void filecopy(FILE *, FILE *);
    char *prog = argv[0];

    if(argc == 1)
        filecopy(stdin, stdout);
    else
        while (--argc > 0) {
            if((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                exit(1);
            } else {
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    if(ferror(stdout)) {
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(2);
    }
    exit(0);
}

void filecopy(FILE *ifp, FILE *ofp) {
    int c;
    while((c = getc(ifp)) != EOF)
        putc(c, ofp);
}


void scanfBasic() {
    double sum, v;
    sum = 0;
    while (scanf("%lf", &v) == 1) {
        printf("\t%.2f\n", sum += v);
    }

}
