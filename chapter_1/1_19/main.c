//Exercise 1-19. Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input a line at a time.
#include <stdio.h>
#include "../../std.h"

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
void reverse(char line[], int len){
    if(len == 0){
        return;
    }
    int front = 0;
    int back = len-1;
    char tmp;
    while(back > front){
        tmp = line[front];
        line[front] = line[back];
        line[back] = tmp;
        front++;
        back--;
    }
}

int main(){
    char line[1000];
    int len = getLineX(line,1000);
    reverse(line,len);
    printf("%s", line);
}