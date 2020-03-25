#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

void reverse(char to[], char from[], int len);
int mygetline(char s[], int lim);

int main(int argc, char* argv[])
{
    int len;
    char line[MAXLINE];
    char invl[MAXLINE];

    while ((len = mygetline(line, MAXLINE)) > 0) {
        reverse(invl, line, len);
        printf("%s\n", invl);
    }
    
    exit(EXIT_SUCCESS);
}

int mygetline(char s[], int lim)
{
    int c, i;

    for (i=0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    // discard '\n'
    s[i] = '\0';
    return i;
}

void reverse(char to[], char from[], int len) 
{
    int i, j;
    i = j = 0;
    for (i = len - 1; i >= 0; i--) {
        to[j++] = from[i];
    }
    to[j] = '\0';
}
