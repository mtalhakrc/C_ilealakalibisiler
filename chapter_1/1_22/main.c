#include <stdio.h>
#include "../../std.h"

//Exercise 1-22. Write a program to ``fold'' long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.

#define LINE_LENGTH 20
#define MAX_LINE_LENGTH 1000


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
//void fold_line(char line[], int len){
//    if (len > LINE_LENGTH){
//        int i = 0;
//        while(i < len){
//            int k = 0;
//            if (i > 0 && line[i-1] != ' ' && line[i] == ' '){
//                k = 1;
//            }
//            for(; k < LINE_LENGTH && k+i < len; k++){
//                printf("%c", line[k+i]);
//            }
//            i += LINE_LENGTH;
//            if (line[i] != ' ' && i < len){
//                putchar('-');
//            }
//            putchar('\n');
//
//        }
//    }else{
//        printf("%s", line);
//    }
//}

#define BREAKING_POINT 20
#define OFFSET 10

void fold_line(char line[], char fold_str[],int n_break){
    int column = 0;
    bool split = FALSE;
    int last_blank = 0;
    int i;
    int j;

    for(i = 0,j = 0; line[i] != '\0';i++,j++){
        fold_str[j] = line[i];
        if (fold_str[j] =='\n'){
            column = 0;
        }
        column++;

        if (column == n_break - OFFSET){
            split = TRUE;
        }

        if (split && (fold_str[j] == ' ' || fold_str[j] == '\t')){
            last_blank = j;
        }

        if (column == n_break){
            if(last_blank){
                fold_str[last_blank] = '\n';
                column = j - last_blank;
                last_blank = 0;
            }else{
                fold_str[j] = '-';
                j++;
                fold_str[j] = '\n';
                column = 0;
            }
            split = FALSE;
        }
    }
    fold_str[j] = '\0';

}
int main() {
    char line[MAX_LINE_LENGTH];
    char fold_str[MAX_LINE_LENGTH];
    int len = 0;
    while(TRUE){
        len = getLineX(line, MAX_LINE_LENGTH);
        if (len <= 0){
            break;
        }
        fold_line(line,fold_str,BREAKING_POINT);
        printf("%s\n",fold_str);
    }
}

