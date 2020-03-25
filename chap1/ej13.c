#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXWORD 50

int main(int argc, char *argv[])
{
    int i, j, c, nc, state;

    int wordlen[MAXWORD] = { 0 };

    state = OUT;
    nc = 0;

    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            wordlen[nc]++;
            nc = 0;
        }
        else if (state == OUT) {
            state = IN;
        }
    }

    for (i = 0; i < MAXWORD; i++) {
        if (wordlen[i] > 0) {
            printf("%d:\t", i);
            for (j = 0; j < wordlen[i]; j++) { 
                printf("*");
            }
            printf("\n");
        }
    }
}
