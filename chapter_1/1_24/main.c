#include <stdio.h>
#include <stdbool.h>

//Exercise 1-24. Write a program to check a C program for rudimentary syntax errors like unmatched parentheses,
// brackets and braces. Don't forget about quotes, both single and double, escape sequences, and comments.
// (This program is hard if you do it in full generality.)

#define MAXLEN 1000
void uncomment_str(char str[], char uncommented_str[], int len);
bool check_sytax(char str[], char errmsg[], int len);

int get_str(char str[], int lim);

int main(void) {
    char str[MAXLEN];
    char errmsg[MAXLEN];
    int len = get_str(str, MAXLEN );
    char uncommented_str[MAXLEN];
    uncommented_str(str, uncommented_str, len);

    int err =  check_sytax(,errmsg , len);
    if (err) {
        fprintf(stderr, "%s\n", str);
    }
    fprintf(stdout, "success!\n");

}

int get_str(char str[], int lim){   //test command
    char c;
    int i = 0;
    while(true){
        c = (char) getchar();
        if (c == EOF){
            break;
        }
        str[i] = c;
        i++;
    }
    str[i] = '\0';
    return i;
}

//check_sytax gets string to be checked, fills descriptive errormessage if any syntax error occurs.
//returns 0 if none, otherwise -1.
bool check_sytax(char str[], char errmsg[], int len){
    int brackets = 0; // { }

    int braces = 0; // []
    int phranteses = 0; // ( )
    int quotes = 0; // ' or ""
    int i = 0;
    while (str[i] != 0){
        if (str[i] == '\"' || str[i] == '\''){
            if (in_quote){
                if (i > 0 && i < len && str[i-1] == '\\'){ //is escape character do nothing
                    ;
                }
                in_quote = false;
            }else{
                in_quote = true;
            }
        }

        if (!in_quote){
            if (str[i] == '('){
                in_parenthes = true;
            }

            if (str[i] == '{'){
                in_bracket = true ;
            }

            if (str[i] == '['){
                in_brace = true;
            }


//            if (str[i] == ')'){
//                in_parenthes = false;
//            }
//
//            if (str[i] == '}'){
//                in_bracket = false ;
//            }
//
//            if (str[i] == '}'){
//                in_brace = false;
//            }
        }
        i++;
    }
    return -1;
}

void uncomment_str(char str[], char uncommented_str[], int len){
    bool in_quote = false;
    bool block_comment = false;
    bool line_comment = false;

    int i, j;
    for(i = 0, j = 0; str[i] != '\0'; i++){
        if (str[i] == '"'){
            if (line_comment){
                ;
            }else{
                if(in_quote && i > 0 && str[i-1] == '\\' || str[i-1] == '\''){
                    ; //hala quote olmaya devam ediyor.
                }else if (in_quote){
                    in_quote = false;
                }else{
                    in_quote = true;
                }
            }
        }

        if (str[i] == '\n' && !in_quote){
            line_comment = false;
            //j--;
        }
        if (i < len && str[i] == '*' && str[i+1] == '/' && !in_quote){
            block_comment = false;
            i = i+2;
        }


        if (i < len && str[i] == '/' && str[i+1] == '/' && !in_quote){
            line_comment = true;
        }
        if (i < len && str[i] == '/' && (str[i+1] == '*' || str[i+1] == '*' && str[i+2] == '*') && !in_quote){ //buraya bak kanka.
            block_comment = true;
        }

        if (block_comment){
            continue;
        }else if(line_comment){
            continue;
        }

        uncommented_str[j++] = str[i];
    }
    uncommented_str[j] = '\0';
}
