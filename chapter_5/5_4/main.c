//
// Created by Talha Karaca on 7.11.2023.
//
//Exercise 5-4. Write the function strend(s,t), which returns 1 if the string t occurs at the
//end of the string s, and zero otherwise



#include <stdio.h>
#include <string.h>

int strend( char s[], char t[]);

int main(){
    char s[] = "of the string s, and zero otherwise";
    char t[] = "s, and zero otherwise";
    int eq = strend(s,t);
    printf("%d\n",eq);
    return 0;
}

int strend(char s[], char t[]){
    size_t s_length = strlen(s);
    size_t t_length = strlen(t);
    s += s_length;
    t += t_length;
    while (t_length && (*s-- == *t--)){
        --t_length;
    }
    if (t_length){
        return 0;
    }
    return 1;
}

//
//int strend(char s[], char t[]){
//    int i, j;
//    i = strlen(s) - strlen(t);
//    j = 0;
//    if (i == 0){
//        return 1;
//    }else if (i < 0){
//        return -1;
//    }
//
//    while (s[i] == t[j]){
//        i++;
//        j++;
//    }
//
//    return i-1 == strlen(s);
//}