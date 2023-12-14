//
// Created by Talha Karaca on 22.09.2023.
//
#include <stdio.h>
#include <ctype.h>

#define MAXLEN 10000

int get_str(char str[], int limit);
void expand(char src[], char dest[]);

int main(){
    char str[MAXLEN];
    char expanded_str[MAXLEN];
    int len;
    len = get_str(str, MAXLEN);
    expand(str, expanded_str);
    printf("%s\n", expanded_str);
    return 0;
}

int get_str(char str[], int limit){
    int i, c;
    i = c = 0;

    // limit. item '\0'.
    while(i < limit-1 && (c = getchar()) != '\n' ){
        str[i++] = c;
    }
    str[i] = '\0';

    return i;
}

void expand(char src[], char dest[]){
    int i, j;
    i = j = 0;

    //MAXLEN - 1 : eğer sonuna ulaşırsa da son karakter '\0' olmak zorunda.
    for (i = 0; i < MAXLEN - 1 && j < MAXLEN - 1 && src[i] != '\0'; ++i){
        if (i < MAXLEN -2 && isalnum(src[i]) && src[i+1] == '-' && src[i] < src[i+2]){
            do {
                int k;
                for (k = 0; k <= (src[i+2] - src[i]); ++k){
                    int temp = src[i] + k;
                    //dest[j-1] != temp: kendisinden önceki harf başlangıç harfi ile aynı ise ilk harfi yazma
                    if(dest[j-1] != temp && (isdigit(temp) || isalnum(temp))){
                        dest[j++] = temp;
                    }
                }
                i += 2;
            } while(i < MAXLEN -2 && isalnum(src[i]) && src[i+1] == '-' && src[i] < src[i+2]);
        }else{
            dest[j++] = src[i];
        }
    }
    dest[j] = '\0';
}