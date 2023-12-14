//Exercise 1-17. Write a program to print all input lines that are longer than 80 characters.
#define MAXLINE 10000

#include <stdio.h>
#include "../../std.h"
int getLineX(char line[],int lim);
int main(){
    char line[MAXLINE];
    while(TRUE){
        int len = getLineX(line,MAXLINE);
        if (len <= 0){
            break;
        }
        if (len > 80){
            printf("%s ; len: %d\n", line, len);
        }
    }
}

int getLineX(char line[],int lim){
    char c;
    int i = 0;
    while(i < lim-1){
        c =(char)getchar();
        if (c == EOF){
            break;
        }
        if(c == '\n'){
            break;
        }
        line[i++] = c;
    }
    line[i+1] = '\0';
    return i;
}
