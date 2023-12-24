//
// Created by Talha Karaca on 24.12.2023.
//

//Exercise 5-7. Rewrite readlines to store lines in an array supplied by main, rather than
//calling alloc to maintain storage. How much faster is the program?

// array supplied from stack

#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAXLINES 5000 /* max #lines to be sorted */
#define ALLOCSIZE 10000 /* size of available space */

char *lineptr[MAXLINES]; /* pointers to text lines */

#define ALLOCSIZE 10000 /* size of available space */
static char *allocp; /* next free position */

int readlines(char *lineptr[], int maxlines, char* allocbuf);
void writelines(char *lineptr[], int nlines);
/* sort input lines */
void __swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
void __qsort(char *v[], int left, int right)
{
    int i, last;
    if (left >= right) /* do nothing if array contains */
        return; /* fewer than two elements */
    __swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            __swap(v, ++last, i);
    __swap(v, left, last);
    __qsort(v, left, last-1);
    __qsort(v, last+1, right);
}

int main()
{
    static char allocbuf[ALLOCSIZE]; /* storage for alloc */
    allocp = allocbuf;

    unsigned int start = clock();
    int return_code;
    int nlines; /* number of input lines read */
    if ((nlines = readlines(lineptr, MAXLINES,allocbuf)) >= 0) {
        __qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return_code = 0;
    } else {
        printf("error: input too big to sort\n");
        return_code = -1;
    }
    unsigned int end = clock();
    double dblTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("time: %f", dblTime);
    return return_code;
}

#define MAXLEN 1000 /* max length of any input line */

//int _getline(char *, int);
int __getline(char s[],int lim)
{
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

#define ALLOCSIZE 10000 /* size of available space */
//static char allocbuf[ALLOCSIZE]; /* storage for alloc */

char* alloc(char* allocbuf, int n) /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
        allocp += n;
        return allocp - n; /* old p */
    } else /* not enough room */
        return NULL;
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines, char* allocbuf)
{
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = __getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(allocbuf, len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}