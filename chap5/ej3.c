#include <stdio.h>
#include <stdlib.h>

void mystrcat(char*, char*);
void mystrcpy(char*, char*);

int main(int argc, char *argv[])
{
    char *dst;
    dst = malloc(sizeof(char) * 100);
    mystrcpy(argv[1], dst);
    mystrcat(dst, argv[2]);
    printf("%s\n", dst);
    exit(EXIT_SUCCESS);
}

void mystrcat(char* s, char* t)
{
    while(*s != '\0') {
        s++;
    }
    mystrcpy(t, s);
}

void mystrcpy(char* src, char* dst)
{
    int i;
    while (*src != '\0') {
        *dst++ = *src++;
    }
    *dst = '\0';
}
