//
// Created by Talha Karaca on 14.12.2023.
//

#include <stdio.h>
#include <string.h>

char* strncat_(char* src, char* dest, size_t n);

int main(){
    char src[50] = "karaca";
    char dest[50] = "muhammed talha";
    char* ok = strncat_(src, dest, -1);
    if (ok == NULL){
        printf("there was an error\n");
    }
    printf("%s", dest);
    return 0;
}


char* strncat_(char* src, char* dest, size_t n){
    if (n < -1){
        return NULL;
    }
    size_t num;
    num = 0;
    //'\0' göresiye kadar kopyala
    if (n == -1){
        num = strlen(src);
    }else{
        num = n;
    }
    int i, j;
    i = strlen(dest);
    j = 0;
    while(j >= num){
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}