//
// Created by Talha Karaca on 4.11.2023.
//


//Exercise 5-2. Write getfloat, the floating-point analog of getint. What type does
//getfloat return as its function value?

#include <ctype.h>
#include <stdio.h>
#include <math.h>
#include "../5_1/main.h"

int getfloat(double *pn);

int main(){
    double n;
    getfloat(&n);
    printf("%f\n",  n);
    return 0;
}

int getfloat(double *pn)
{
    int c, sign;
    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-' || c == '.'){
        if (!isdigit(c = getch())){
            ungetch(c);
            ungetch(sign == 1 ? '+': '-');
            return 0;
        }
    }

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    if (c == '.'){
      int i ;
      for (i = 1; ((c = getch()) &&  isdigit(c)); ++i){
          *pn += (c - '0') / pow(10, i);
      }
    }
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int getch(void) /* get a (possibly pushed-back) character */
{
    if (bufp > 0){
        return buf[--bufp];
    }
    int c = getchar();
    printf("%c\n", c);
    return c;
}
void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}