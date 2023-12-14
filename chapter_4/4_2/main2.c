//
// Created by Talha Karaca on 1.10.2023.
//

#include <stdio.h>
#include <ctype.h>

#define MAXLEN 500

int get_line(char line[], unsigned int max_line_len);
double atof(char s[]);

int main(int argc, char *argv[]){
    char line[MAXLEN];
    get_line(line,MAXLEN);
    printf("%f\n", atof(line));

}

double atof(char s[]){
    double val, power;
    int i, sign, exp_sign, exp_power;
    exp_sign = 1;
    exp_power = 0;

    for(i = 0; isspace(s[i]); ++i){
        ;
    }
    if (s[i] == '-'){
        sign = -1;
    }else{
        sign = 1;
    }
    if (s[i] == '+' || s[i] == '-'){
        ++i;
    }
    for (val = 0.0; isdigit(s[i]); ++i){
        val = 10.0 * val +(s[i] - '0');
    }
    if (s[i] == '.')
    {
        ++i;
    }

    for (power = 1.0; isdigit(s[i]); ++i)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    if (s[i] == 'e' || s[i] == 'E'){
        if (s[++i] == '-'){
            exp_sign = -1;
            ++i;
        }
    }

    while (isdigit(s[i])) {
        exp_power = 10 * exp_power + (s[i] - '0');
        ++i;
    }

}
int get_line(char line[], unsigned int max_line_len){
    int i = 0, c;

    while (i < max_line_len - 1 && (c = getchar()) != '\n')
    {
        line[i] = c;
        ++i;
    }

    if (c == '\n')
    {
        line[i++] = c;
    }

    line[i] = '\0';

    return i;
}
