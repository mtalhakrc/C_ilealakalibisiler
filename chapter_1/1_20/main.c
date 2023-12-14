#include <stdio.h>
#include "../../std.h"

//1-20. Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?
#define MAX 1000
#define TAB_LENGTH 1

int main(){
    while (TRUE){
        char c = (char)getchar();
        if (c == EOF){
            break;
        }
        if (c == '\t'){
            int remainig_spaces = TAB_LENGTH;
            for(; remainig_spaces > 0; remainig_spaces-- ){
                putchar('X');
            }
        }else{
            putchar(c);
        }
    }
}