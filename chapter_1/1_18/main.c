//Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input,
//and to delete entirely blank lines.
#include <stdio.h>
#include "../../std.h"

bool isVisibleChar(char c){
    return (bool) (('a' <= c) && (c <= 'z')) || (('A' <= c) && (c <= 'Z')) || (('0' <= c) && (c <= '9'));
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

void trim_space(char line[], int len){
    int i = 0;
    int n = 0;
    char c;
    bool in = FALSE;
    if (len == 0) {
        return;
    }
    int end = 0;
    for(int k = len-1;;k-- ){
        if (isVisibleChar(line[k])){
            end = k;
            break;
        }
    }
    while(line[i] != '\0' && i < len && i < end){
        c = line[i];
        if (isVisibleChar(c)){
            in = TRUE;
        }
        if (in){
            line[n] = line[i];
            n++;
        }
        i++;
    }
    line[n+1] = '\0';
}

int main(){
    char deneme[] = "a \t\tmerhaba ben Muhammed Talha Karaca\n\n     \t";
    trim_space(deneme, len(deneme,sizeof deneme));
    printf("%s\n",deneme);
}
