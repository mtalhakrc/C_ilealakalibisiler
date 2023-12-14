//
// Created by Talha Karaca on 29.09.2023.
//

//Exercise 3-6. Write a version of itoa that accepts three arguments instead of two. The third
//argument is a minimum field width; the converted number must be padded with blanks on the
//left if necessary to make it wide enough.


#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define MAXLEN 100

void reverse(char s[]);
void itoa(int n, char s[],int min_width);

int main(){
    char s[MAXLEN];
    itoa(pow(-2, 31),s, 12);
    printf("%s\n", s);
    printf("%lu\n", strlen(s));
    return 0;
}
void itoa(int n, char s[], int min_width){
    int org = n;
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
    if (org == INT_MIN){
        strcpy(s, "8463847412-");
    }
    int len;
    len = strlen(s);
    i = 0;
    while(len < min_width){
        s[i+len] = ' ';
        len++;
        i++;
    }
    s[i+len+1] = '\0';
    reverse(s);



    //mal kafam benim reverse olmadan sonuna eklesene
//    int len;
//    len = strlen(s);
//    if (len < min_width){
//        int step;
//        step = min_width-len;
//        if (len+1+step > MAXLEN){
//            strcpy(s, "max 100 len str");
//            return;
//        }
//        char tmp1;
//        char tmp2;
//        for (int k = 0; k < step; k++){
//            tmp1 = s[k];
//            for(i = 0; i < len;i++){
//                tmp2 = s[i+1];
//                s[i+1] = tmp1;
//                tmp1 = tmp2;
//            }
//            s[k] =  ' ';
//        }
//        s[i+len] = '\0';
//    }
}

void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c; }
}
