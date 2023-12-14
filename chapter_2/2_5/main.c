//
// Created by Talha Karaca on 17.09.2023.
//

#include "stdlib.h"
#include "stdio.h"
//Exercise 2-5. Write the function any(s1,s2), which returns the first location in a string s1 where any character from the string s2 occurs,
// or -1 if s1 contains no characters from s2. (The standard library function strpbrk does the same job but returns a pointer to the location.)

int any(char s1[], char s2[]){
    if (s1 == NULL){
        return -1;
    }
    if (s2 == NULL){
        return -1;
    }
    int i = 0;
    int j = 0;
    while(s1[i++] !='\0'){
        while(s2[j++] != '\0'){
            if (s1[i] == s2[j] ){
                return i;
            }
        }
        j = 0;
    }
    return -1;
}

int main(){
    int result= any("muhammedtalhakaraca", "talha");
    printf("%d\n",result);
    return 0;
}

