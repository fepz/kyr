#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define BUFSIZE 100

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode*, char*);
struct tnode *addnumtree(struct tnode *p, int count, char *w);
struct tnode *talloc(void);
void treeprint(struct tnode*);
struct tnode *traverse(struct tnode*, struct tnode*);
int getword(char*, int);
char* mystrdup(char *s);
int getch(void);
void ungetch(int c);


char buf[BUFSIZE];
int bufp = 0;

int main(int argc, char* argv[])
{
    struct tnode *root, *root2;
    char word[MAXWORD];

    root = NULL;
    root2 = NULL;

    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            root = addtree(root, word);
        }
    }

    root2 = traverse(root, root2);

    treeprint(root2);

    exit(EXIT_SUCCESS);
}

/* traverse: */
struct tnode* traverse(struct tnode *from, struct tnode *to)
{
    if (from != NULL) {
        to = traverse(from->left, to);
        to = addnumtree(to, from->count, from->word);
        to = traverse(from->right, to);
    }
    return to;
}

/* addtree: agrega un nodo con w en o bajo p. */
struct tnode *addnumtree(struct tnode *p, int count, char *w)
{
    if (p == NULL) {
        p = talloc();
        p->word = mystrdup(w);
        p->count = count;
        p->left = p->right = NULL;
    }
    else if (count > p->count) {
        p->left = addnumtree(p->left, count, w);
    }
    else {
        p->right = addnumtree(p->right, count, w);
    }

    return p;
}

/* addtree: agrega un nodo con w en o bajo p. */
struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = mystrdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0) {
        p->count++;
    }
    else if (cond < 0) {
        p->left = addtree(p->left, w);
    }
    else {
        p->right = addtree(p->right, w);
    }

    return p;
}

/* talloc: crea un tnode. */
struct tnode *talloc(void) 
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

/* treeprint: imprime el Ãrbol p en orden. */
void treeprint(struct tnode* p)
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d:\t%s\n", p->count, p->word);
        treeprint(p->right);
    }
}

/* mystrdup: crea un duplicado de s. */
char* mystrdup(char *s)
{
    char *p;
    p = (char*) malloc(strlen(s) + 1); // +1 para '\0'
    if (p != NULL) {
        strcpy(p, s);
    }
    return p;
}

/* getword: obtiene la siguiente plabra o carÃcter de entrada. */
int getword(char* word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
        ;

    if (c != EOF) {
        *w++ = c;
    }

    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }

    for ( ; --lim > 0; w++) {
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    }

    *w = '\0';
    return word[0];
}

/* getch: obtiene un (posiblemente ya regresado) caracter de la entrada. */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: regresa caracter a la entrada. */
void ungetch(int c)
{
    if (bufp > BUFSIZE) {
        printf("ungetch: demasiados caracteres\n");
    } else {
        buf[bufp++] == c;
    }
}
