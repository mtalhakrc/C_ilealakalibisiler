//
// Created by Talha Karaca on 20.09.2023.
//

/*
   * a-z
   * a-b-c
   * a-c-h-v
   * a-c-b-v
   * 0-9
   * 1-5
   * a-zA-Z
   * 0-9a-zA-Z
   * -a-z
   * a-z-
   * -a-z-

   * abcdefghijklmnopqrstuvwxyz
   * abc
   * abcdefghijklmnopqrstuv
   * abc-bcdefghijklmnopqrstuv
   * 0123456789
   * 12345
   * abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ
   * 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ
   * -abcdefghijklmnopqrstuvwxyz
   * abcdefghijklmnopqrstuvwxyz-
   * -abcdefghijklmnopqrstuvwxyz-

 */

//Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz in s2.
// Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally.

#include <stdio.h>
#define MAXLEN 1000

int get_line(char line[], unsigned int limit);
void expand(char shorthand[], char expanded[]);

int main() {
    char shorthand[MAXLEN];
    int len;
    len = get_line(shorthand, MAXLEN);

    char expanded[MAXLEN];

    expand(shorthand, expanded);
    printf("%s\n",expanded);




}

int get_line(char line[], unsigned int limit){
    int i, c;
    for(i = 0; i < limit-1 && (c = getchar()) != '\n';i++){
        line[i] = c;
    }
    line[i] = '\0';
    return i;
}

void expand(char shorthand[], char expanded[]){
    char from;
    char to;
    int i;
    int j;
    from = '\0';
    to = '\0';
    for (i = j = 0; shorthand[i] != '\0'; i++,j++){

//        if(shorthand[i] == '-'){
//            if (i == 0){
//                expanded[j] = shorthand[i];
//                continue;
//            }else {
//                from = shorthand[i-1];
//            }
//        }
//
//
//        if (from != '\0'){
//
//        }
//        switch (shorthand[i]) {
//            case '-':
//                if (i > 0 && ((shorthand[i-1] >= 'a' && shorthand[i-1] <= 'z') || (shorthand[i-1] >= 'A' && shorthand[i-1] <= 'Z') || (shorthand[i-1] >= '0' && shorthand[i-1] <= '9') ) ){
//                    from = shorthand[i-1];
//                }
//                break;
//            default:
//                expanded[j] = shorthand[i];
//                break;
//        }
        expanded[j] = shorthand[i];


        if (shorthand[i] == '-' && i > 0 && ((shorthand[i-1] >= 'a' && shorthand[i-1] <= 'z') || (shorthand[i-1] >= 'A' && shorthand[i-1] <= 'Z') || (shorthand[i-1] >= '0' && shorthand[i-1] <= '9') ) ){
            from = shorthand[i-1];
        }

        if (from != '\0'){
            if (shorthand[i] >= from){
                to = shorthand[i];
            }
        }

        if ( from != '\0' && to != '\0'){
            j -= 2;
            for (;from <= to; j++, from++){
                expanded[j] = from;
            }
            j--;
            from = '\0';
            to = '\0';
        }
        //expanded[j] = shorthand[i];
    }
    expanded[j] = '\0';
}








