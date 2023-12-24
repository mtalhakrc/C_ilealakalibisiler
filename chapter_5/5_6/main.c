//
// Created by Talha Karaca on 24.12.2023.
//

//Exercise 5-6. Rewrite appropriate programs from earlier chapters and exercises with pointers
//instead of array indexing. Good possibilities include getline (Chapters 1 and 4), atoi, itoa,
//and their variants (Chapters 2, 3, and 4), reverse (Chapter 3), and strindex and getop
//(Chapter 4).

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void __reverse(char *s);
void itoa(int n , char *s);
int main(){
    char *s = (char*) malloc(sizeof ( char) * 200);
    itoa(1999, s);
    printf("%s",s);

}

/*
 *
 *
 * int getline(char s[],int lim)
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
 */

// getline pointer version
int __getline(char *s, int lim){
    int c,i;
    for (i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; ++i){
      *(s+i) = c;
    }
    if (c == '\n'){
        *s = c;
        ++i;
    }
    *(s+i) = '\0';
    return i;
}


/*
 * int atoi(char s[])
{
int i, n;
n = 0;
for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
n = 10 * n + (s[i] - '0');
return n;
}
As we di
 */


int __atoi(char *s){
    int i,n;
    n = 0;
    for (i = 0; *(s+i) >= '0' && *(s+i) <= '9'; ++i ){
        n = 10 * n + ((*(s+i)) - '0');
    }
    return n;
}
///* itoa: convert n to characters in s */
//void itoa(int n, char s[])
//{
//int i, sign;
//if ((sign = n) < 0) /* record sign */
//n = -n; /* make n positive */
//i = 0;
//do { /* generate digits in reverse order */
//s[i++] = n % 10 + '0'; /* get next digit */
//} while ((n /= 10) > 0); /* delete it */
//if (sign < 0)
//s[i++] = '-';
//s[i] = '\0';
//reverse(s);
//}

void itoa(int n , char *s){
    int i, sign;
    i = 0;
    if ((sign = n) < 0){
        n = -n;
    }
    do{
        *(s+i++) = n%10 +'0';
    }while((n /= 10)>0);
    if (sign < 0){
        *(s+i++) = '-';
    }
    *(s+i) ='\0';
    __reverse(s);
}

/*
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
 */

void __reverse(char *s){
    int c,i,j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = *(s+i);
        *(s+i) = *(s+j);
        *(s+j) = c;
    }
}