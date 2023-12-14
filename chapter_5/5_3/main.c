//
// Created by Talha Karaca on 7.11.2023.
//

//Exercise 5-3. Write a pointer version of the function strcat that we showed in Chapter 2:
//strcat(s,t) copies the string t to the end of s.
#include <stdio.h>

void _strcat(char s[], char t[]);

int main(){
    char s[] = "talha";
    char t[] = "karaca";
    _strcat(s,t);
    printf("%s\n",s);
    return 0;
}

void _strcat(char *s, char *t)
{
    int i, j;
    i = j = 0;
    while (*(s+i) != '\0')
        i++;
    while ((*(s+i++) = *(t+j++)) != '\0')
        ;
}
