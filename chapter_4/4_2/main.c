//
// Created by Talha Karaca on 29.09.2023.
//

//todo: öncekini de kontrol etmedim aq

// Exercise 4-2. Extend atof to handle scientific notation of the form
//123.45e-6
//where a floating-point number may be followed by e or E and an optionally signed exponent.

#define MAXLEN 100

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// bilimsel gösterimde e kısmı yalnızca ondalıklı kısımda ortaya çıkar.

double _atof(char s[]);
int main(){
    char s[] = "0.2e-2";
    double res;
    res = _atof(s);
    printf("%.10lf\n", res);
    return 0;
}

double _atof(char s[]){
    double val, power;
    int i, sign;
    for (i = 0; isspace(s[i]); i++) {
        ;
    }
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-'){
        i++;
    }
    for (val = 0.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.'){
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    // s[i] is 'e' or 'E'
    val = sign * val / power;
    int sc_exponent = 0;
    char *sc_exponent_ptr = NULL;
    if ((s[i] == 'e' || s[i] == 'E') && i > 0){
        sc_exponent_ptr = malloc(strlen(s) + 1);
        strcpy(sc_exponent_ptr, s+i+1);
        sc_exponent =(int) _atof(sc_exponent_ptr);
        val = val * (pow(10, sc_exponent));
    }
    free(sc_exponent_ptr);
    return val;
}

