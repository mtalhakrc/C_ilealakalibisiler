#include <stddef.h>
#include <stdio.h>
#include <string.h>

//
// Created by Talha Karaca on 14.12.2023.
//
char* _strncpy(char *dest, const char *src, size_t n);


int main(){
    char src[40];
    char dest[12];

    memset(dest, '\0', sizeof(dest));
    strcpy(src, "This is tutorialspoint.com");
    _strncpy(dest, src, 5);

    printf("Final copied string : %s\n", dest);

    return 0;
}

// strncpy copies src most n contents to dest, if n is -1 it would copy all
char* _strncpy(char *dest, const char *src, size_t n){
    if (dest == NULL || src == NULL){
        return NULL;
    }
    size_t i;
    i = 0;

    while ((dest[i] = src[i]) != '\0' && i < n){
        i++;
    }
    dest[i] = '\0';
    return dest;
}




