#include <stdio.h>
#include <stdbool.h>
/*
 * block comment
 */
//E""" \' ' '    \n \n \n \n kanakaaa

#define MAX_STR 50000
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
void remove_comments(char str[], char no_com_str[]){
    bool in_quote = false;
    bool line_comment = false;
    bool block_comment = false;
    int i = 0, j = 0;
    while(str[i] != '\0'){

        if (!block_comment){
            if (!in_quote && str[i] == '"'){
                in_quote = true;
            } else if (in_quote && str[i] == '"'){
                in_quote = false;
            }
        }

        if (!in_quote){

            if(str[i] == '/' && str[i+1] == '*' && !line_comment){
                block_comment = true;
            }

            if (str[i] == '*' && str[i+1] == '/'){
                block_comment = false;
                i += 2;
            }

            if (str[i] == '/' && str[i+1] == '/'){
                line_comment = true;
            }
            if (str[i] == '\n'){
                line_comment= false;
            }
            if (line_comment || block_comment){
                i++;
            }else if(!line_comment || !block_comment){
                no_com_str[j++] = str[i++];
            }

        }else{
            no_com_str[j++] = str[i++];
        }

    }
    no_com_str[j] = '\0';
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
    remove_comments(str, uncommented_str);
    printf("%s\n", uncommented_str);
}
