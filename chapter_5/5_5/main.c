//
// Created by Talha Karaca on 7.11.2023.
//

//Exercise 5-5. Write versions of the library functions strncpy, strncat, and strncmp, which
//operate on at most the first n characters of their argument strings. For example,
//strncpy(s,t,n) copies at most n characters of t to s. Full descriptions are in Appendix B.

#include <stdio.h>
#include <string.h>

int main () {
    char src[40];
    char dest[12];

    memset(dest, '\0', sizeof(dest));
    strcpy(src, "This is tutorialspoint.com");
    strncpy(dest, src, 10);

    printf("Final copied string : %s\n", dest);

    return(0);
}