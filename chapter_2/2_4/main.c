
/*
void squeeze(char s[], int c)
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}
 */
#define MAXSIZE 1000
#include <stdio.h>
#include <string.h>

typedef struct{
    char str1[MAXSIZE];
    char str2[MAXSIZE];
    char expected[MAXSIZE];
}test;

void squeeze(char str1[], char str2[]){
    int i = 0;
    int j = 0;
    int k = 0;
    int found = 0;

    for (; str1[i] != '\0'; ++i){
        for(;str2[j] != '\0'; ++j){
            if (str2[j] == str1[i]){
                found = 1;
                break;
            }
        }
        if(!found){
            str1[k++] = str1[i];
        }
        found = 0;
        j = 0;
    }
    str1[k] ='\0';
    return;
}

//Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in s1 that matches any character in the string s2.
int main(void){
    test tests[] = {
            {
                "talhakaraca",
                "talha",
                "krc",
            },
            {
                "asdf",
                "asdf",
                "",
            },
            {
                "yeni",
                "eni",
                "y",
            }
    };
    for(int i = 0 ; i < sizeof(tests) / sizeof(tests[0]); i++){
        test testi = tests[i];
        squeeze(testi.str1, testi.str2);
        if (strcmp(testi.str1, testi.expected) != 0){
            printf("FAIL case. expected: %s got: %s\n", testi.expected, testi.str1);
            return -1;
        }
    }
    printf("PASS\n");


}