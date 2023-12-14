#include <stdio.h>


// Revise the main routine of the longest-line program so it will correctly print the length of arbitrary long input lines, and as much as possible of the text.
#define MAXLINE 10000
#define TRUE 1
#define FALSE !TRUE
int getLineX(char line[],int lim);
void copy(char to[], const char from[]);

int main(){
    char line[MAXLINE];
    char longest[MAXLINE];
    int max = 0;
    while(TRUE){
        int len = getLineX(line, MAXLINE);
        if (len > max){
            max = len;
            copy(longest,line);
        }
        if(len <= 0){
            break;
        }
    }

    printf("line lenght: %d\n", max);
    printf("%s\n", longest);
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

void copy(char to[], const char from[]){
    int i = 0;
    while(TRUE){
        if (from[i] == '\0'){
            break;
        }
        to[i] = from[i];
        i++;
    }
}