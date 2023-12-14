#include <stdio.h>
#include <stdbool.h>
/*
 * block comment
 */
//Write a program to remove all comments from a C program. Don't forget to handle quoted strings and character constants properly. C comments don't nest
//E""" \' ' '    \n \n \n \n kanakaaa

#define MAX_STR 50000

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

int main(){
    char str[MAX_STR];
    char uncommented_str[MAX_STR];

    char deneme[] = "burayı // silme kanka \" burayı da \n \" silme kanka";

    //aç olan var mı??
    /*
     * buarsı block comment silsene burayı
     */
    /**
     * burayı da sil kanka. ## "   "
     */

    int len = get_str(str, MAX_STR);
    uncomment_str(str, uncommented_str, len);
    printf("%s\n", uncommented_str);
}

/*
 *   // şuankinden sonraki \0 olmasın.
        char c = str[i];
        if (str[i] == '"'){
            if (in_quote && i > 0 && str[i-1] == '\\'){
                ;
            }else if(in_quote){
                in_quote = false;
            }else{
                in_quote = true;
            }
        }

        if(str[i] == '\n'){
            if (in_quote){
                ;
            }else{
                line_comment = false;
            }
        }
        if (str[i] == '*' && str[i+1] == '/'){
            block_comment = false;
            i = i+2;
        }
        if (str[i] == '/' && str[i+1] == '/'){
            if (in_quote){
                ;
            }else{
                line_comment = true;
            }
        }

        if(str[i] == '/' && str[i+1] == '*'){
            if (in_quote){
                ;
            }else{
                block_comment = true;
            }
        }

        if(line_comment || block_comment) {
            j--;
            continue;
        }

        uncommented_str[j++] = str[i];
 */