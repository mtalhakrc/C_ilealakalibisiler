//
// Created by Talha Karaca on 23.09.2023.
//

//Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa; that is, convert
//an integer into a string by calling a recursive routine

#include <stdio.h>
#include <string.h>
#include <limits.h>
#define MAXLEN 100

void reverse(char s[]);
int itoa(int n, char s[], int i);

int main(){
    char s[MAXLEN];
    itoa(-2147483647, s,0);
    printf("%s\n", s);
    return 0;
}
int itoa(int n, char s[], int i){
    if (n == INT_MIN){
        strcpy(s, "-2147483648");
        return i;
    }
    int sign;
    if ((sign = n) < 0)
        n = -n;

    s[i++]=n%10+'0';

    if ((n /= 10) > 0){
        i = itoa(n,s,i);
    }

    if (sign < 0){
        s[i++] = '-';
        s[i] = '\0';
        reverse(s);
    }
    return i;
}

void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
