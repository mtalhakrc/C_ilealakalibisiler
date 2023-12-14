//
// Created by Talha Karaca on 27.07.2023.
//
//for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
//       s[i] = c;

//Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||.
#include <stdio.h>
int main(){
    int lim =1000;
    for (int i = 0; i < lim-1;++i ){
        int c = getchar();
        if (c == '\n' || c == EOF){
            break;
        }
    }
}