//
// Created by Talha Karaca on 27.09.2023.
//

#define MAXLEN 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char itoc(int a);
void reverse(char s[]);
void itob(int n, char s[], int b);
int main(){
    char s[MAXLEN];
    int n ;
    n = 255;
    itob(n,s, 16);
    printf("%s\n", s);
}


char itoc(int a){
    if (a <= 9){
        return a + '0';
    }
    return a + 'a' - 10;
}

void reverse(char s[]){
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
void itob(int n, char s[], int b){
    int i, sign;
    i = 0;
    sign = n;

    do{
        s[i++] = itoc(abs(n) % b);
        n /= b;
    }while(n);

    switch (b) {
        case 2:
            s[i++] = 'b';
            s[i++] = '0';
            break;

        case 16:
            s[i++] = 'x';
            s[i++] = '0';
            break;
    }
    if (sign < 0){
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}
