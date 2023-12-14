//
// Created by Talha Karaca on 27.07.2023.
//
//Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits
// (including an optional 0x or 0X) into its equivalent integer value.
// The allowable digits are 0 through 9, a through f, and A through F.

#define MAXSIZE 100
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


//htoi  converts a string of hexadecimal digits
//(including an optional 0x or 0X) into its equivalent integer value.
// -1 if error occurs
//int htoi(const char s[]){
//    int val = 0;
//    if (s == NULL){
//        return -1;
//    }
//    unsigned long size = strlen(s);
//    if (size < 2){
//        return -1;
//    }
//    if ((toupper(s[0])) != '0' && (toupper(s[0])) != 'X'){
//        return -1;
//    }
//    int i = 2;
//    int power = size - 3;
//    //char hexnums[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
//    while(s[i] != '\0'){
//        int upper = toupper(s[i]);
//        printf("%c\n", (char) upper);
//        switch (upper) {
//            case '0':
//                val += pow(16,power) * 0;
//                break;
//            case '1':
//                val += pow(16,power) * 1;
//                break;
//
//            case '2':
//                val += pow(16,power) * 2;
//                break;
//
//            case '3':
//                val += pow(16,power) * 3;
//                break;
//
//            case '4':
//                val += pow(16,power) * 4;
//                break;
//
//            case '5':
//                val += pow(16,power) * 5;
//                break;
//
//            case '6':
//                val += pow(16,power) * 6;
//                break;
//
//            case '7':
//                val += pow(16,power) * 7;
//                break;
//
//            case '8':
//                val += pow(16,power) * 8;
//                break;
//
//            case '9':
//                val += pow(16,power) * 9;
//                break;
//
//            case 'A':
//                val += pow(16,power) * 10;
//                break;
//
//            case 'B':
//                val += pow(16,power) * 11;
//                break;
//
//            case 'C':
//                val += pow(16,power) * 12;
//                break;
//
//            case 'D':
//                val += pow(16,power) * 13;
//                break;
//
//            case 'E':
//                val += pow(16,power) * 14;
//                break;
//
//            case 'F':
//                val += pow(16,power) * 15;
//                break;
//
//        }
//        power--;
//        i++;
//    }
//    return val;
//}

int htoi(char hex[]){
    int result = 0;
    int i = 0;
    int len =(int) strlen(hex);
    while (i < len){
        if (hex[i] == '0' && hex[i+1] == 'x' || hex[i+1] == 'X'){
            i+=2;
        }
        int temp = tolower(hex[i]);
        if (isdigit((temp))){
            temp -= '0'; //
        }
        if (isalpha(temp) && temp <='f'){
            temp = temp -'a' + 10;  //
        }

        if((hex[i] >= '0' && hex[i] <= '9' )|| (hex[i] >= 'a' && hex[i] <= 'f') ||(hex[i] >= 'A' && hex[i] <= 'F') ){
            result += temp * (int) pow(16,len-i-1);
        } else{
            printf("Error: Not a valid hex value.\n Try this format: 0xHHHH, where H is a hex digit.\n");
            return -1;
        }
        ++i;
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
                    "0123dd",
                    -1,
            },
            {
                "0Xd6B",
                    3435,
            },
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
    return 0;
}