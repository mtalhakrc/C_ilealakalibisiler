//
// Created by Talha Karaca on 28.07.2023.
//
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAXSIZE 100


int htoi(char hex[]){
    int len =(int) strlen(hex);
    int i = 0;
    int result = 0;
    if (len == 0){
        return -1;
    }
    while(i< len){
        if (hex[i] == '0' && (hex[i+1] == 'x' || hex[i+1] =='X') ){
            i+=2;
        }
        char temp = (char) tolower(hex[i]);
        if (isdigit(temp)){
            temp -= '0';
        }
        if (isalpha(temp) && temp <= 'f'){
            temp = temp - 'a'+ 10;
        }

        int power = len-i-1;

        if ((hex[i] >= '0' && hex[i] <= '9')|| (hex[i] >= 'a' && hex[i] <= 'f') || (hex[i]>= 'A' && hex[i]<= 'F')){
            result += temp * (int) pow(16,power);
        }else{
            return -1;
        }
        i++;
    }
    return result;
}

typedef struct{
    char given[MAXSIZE];
    int expected;
}test;

int main(){
    test tests[] = {
            {
                    "0xff",
                    255,
            },
            {
                    "0Xff",
                    255,
            },
            {
                    "0X75",
                    117,
            },
            {
                    "0XAB",
                    171,
            },
            {
                    "0Xd6B",
                    3435,
            },
            {
                "",
                -1,
            },
            {
                "0X1",
                1,
            }
    };
    for(int i = 0 ; i < sizeof(tests) / sizeof(tests[0]); i++){
        test testi = tests[i];
        int res = htoi(testi.given);
        if (res != testi.expected){
            printf("FAIL case. expected: %d got: %d\n", testi.expected, res);
            return -1;
        }
    }
    printf("PASS\n");
}