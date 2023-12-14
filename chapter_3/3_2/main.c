//
// Created by Talha Karaca on 18.09.2023.
//
#include <string.h>
#include <stdio.h>

#define MAX 1000

//Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s.
// Use a switch. Write a function for the other direction as well, converting escape sequences into the real characters.


int escape(char *s, char *t){
    //şuan s'te yeteinde yer olduğu varsayıldı.
    int i = 0;
    for(int n = 0; n < strlen(t); n++, i++){
        switch (t[n]) {
            case '\n':
                s[i++] = '\\';
                s[i] = 'n';
                continue;
            case '\t':
                s[i++] = '\\';
                s[i] = 't';
                continue;
            default:
                s[i] = t[n];
        }
    }
    s[i] = '\0';
    return 0 ;
}

int deescape(char *s, char *t){
    //şuan s'te yeteinde yer olduğu varsayıldı.
    int i = 0;
    for(int n = 0; n < strlen(t); n++, i++){
        if (t[n] == '\\'){
            switch (t[n+1]) {
                case 't':
                    s[i] = '\t';
                    n++;
                    continue;
                case 'n':
                    s[i] = '\n';
                    n++;
                    continue;
            }
        }
        s[i] = t[n];
    }
    s[i] = '\0';
    return 0 ;}
int get_line(char line[], unsigned int limit)
{
    int i, c;
    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        line[i] = c;
    }

    if (c == '\n')
    {
        line[i++] = c;
    }

    line[i] = '\0';

    return i;
}

int main(void){
    char src[MAX];
    char dest[MAX];

    get_line(src, MAX);
    printf("%s", src);

    escape(dest, src);
    printf("%s\n", dest);

    deescape(dest, src);
    printf("%s", dest);

    return 0;
}

