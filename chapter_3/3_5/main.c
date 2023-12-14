//
// Created by Talha Karaca on 23.09.2023.
//

#define MAXLEN 1000

#include <stdio.h>
#include <string.h>


//Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into a base b character representation in the string s.
// In particular, itob(n,s,16) formats s as a hexadecimal integer in s.

void itob(int n, char str[], int base);
void reverse(char s[]);

int main() {
    char str[MAXLEN];
    int n;
    n = 458;
    itob(n, str, 16);
    printf("%s\n", str);
}

void itob(int n, char str[], int base) {
    int i = 0;
    int p;
    char c;
    if (base == 10){
        while(n > 0){
            p = n % 10;
            n /= 10;
            c = '0' + p;
            str[i++] = c;
        }
        str[i] = '\0';
        reverse(str);
    }else if (base == 16){
        while(n > 0){
            p = n % 16;
            n /= 16;
            c = '0' + p;
            if (p > 9){
                c = 'A' + p - 10;
            }
            str[i++] = c;
        }
        str[i] = '\0';
        reverse(str);
    }else{
        strcpy(str, "kullanım hatası!");
    }
}

void reverse(char s[]){
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}