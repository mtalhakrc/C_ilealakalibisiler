//
// Created by Talha Karaca on 20.09.2023.
//
#include <stdio.h>

#define MAXLEN 1000

int get_line(char line[], unsigned int limit){
    int i,c ;
    for (i = 0; i < limit-1 && (c = getchar()) != EOF && c != '\n'; i++){
        line[i] = c;
    }
    if (c == '\n'){
        line[i++] = c;
    }
    line[i] ='\0';
    return i;
}

void escape(char dest[], char src[]){
    int i, j;
    for (i = j = 0; src[i] != '\0'; i++,j++){
        switch (src[i]) {
            case '\n':
                dest[j++] = '\\';
                dest[j] = 'n';
                break;
            case '\t':
                dest[j++] = '\\';
                dest[j] = 't';
                break;
            default:
                dest[j] = src[i];
                break;
        }
    }

        dest[j] = '\0';
}

void unescape(char dest[], char src[]){
    int i, j;
    for(i = j = 0; src[i] != '\0'; i++,j++){
        switch (src[i]) {
            case '\\':
                switch (src[++i]) {
                    case 'n':
                        dest[j] = '\n';
                        break;
                    case 't':
                        dest[j] = '\t';
                        break;
                }
            default:
                dest[j] = src[i];
                break;
        }
    }
        dest[j] = '\0';

}


int main() {
    char src[MAXLEN];
    char dest[MAXLEN];

    get_line(src, MAXLEN);
    printf("%s", src);

    escape(dest, src);
    printf("%s\n", dest);

    unescape(dest, src);
    printf("%s", dest);

    return 0;
}