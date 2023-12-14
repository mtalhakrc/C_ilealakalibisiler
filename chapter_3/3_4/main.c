//
// Created by Talha Karaca on 23.09.2023.
//

//Exercise 3-4. In a two's complement number representation, our version of itoa does not handle the largest negative number, that is, the value of n equal to -(2wordsize-1).
// Explain why not. Modify it to print that value correctly, regardless of the machine on which it runs.

// AÇIKLAMA: bilgisayar bir sayıyın negatifini alırken two's complement denen bir yöntem kullanır. bu yöntem bütün 0'ları 1'e çevirir ve 1 ekler.
// en küçük negatif sayı 1000 0000 0000 0000 0000 0000 0000 0000' dir. (-2 ^ 31) -2147483648. ve bu sayı bir istisnadır. bu sayıya uygulanınca kendisini verir.


#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define MAXLEN 100

void reverse(char s[]);
void itoa(int n, char s[]);

int main(){
    char s[MAXLEN];
    itoa(pow(-2, 31), s);
    printf("%s\n", s);
    return 0;
}
void itoa(int n, char s[]){
    if (n == INT_MIN){
        strcpy(s, "-2147483648");
        return;
    }
    int i, sign;
    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++]=n%10+'0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c; }
}
