//
// Created by Talha Karaca on 29.09.2023.
//

//todo: 3_6 'yı karşılaştırmadım. onu solution ile karşılaştır.

//Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost
//occurrence of t in s, or -1 if there is none.

#include <string.h>
#include <stdio.h>

#define MAXLEN 1000
int strindex(char s[], char t[]) ;
int main(){
    printf("%d\n", strindex("aaaworld, awoqwqwdqwdrdld! world", "world"));
}


int strindex(char s[], char t[]) {
    int len_s, len_t;
    len_s = strlen(s);
    len_t = strlen(t);
    if (!len_s){
        return -1;
    }
    if (!len_t){
        return -1;
    }
    if (len_s == len_t){
        return 0;
    }

    int k =0;
    int found;
    found = -1;
    int tmp;

    for (int i = 0; i < len_s; i++){
        tmp = i;
        for (k = 0; k < len_t && s[tmp] == t[k]; k++,tmp++){
        }
        if (k == len_t){
            found = i;
        }
    }
    return found;
}