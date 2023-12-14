//
// Created by Talha Karaca on 3.10.2023.
//

//Exercise 4-3. Given the basic framework, it's straightforward to extend the calculator. Add
//the modulus (%) operator and provisions for negative numbers.


#include <stdio.h>
#include <stdlib.h> /* for atof() */
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
int getop(char []);
void push(double);
double pop(void);
/* reverse Polish calculator */
int main()
{
    int type;
    double op2;
    char s[MAXOP]; // operatörleri tutuyoruz. getop'ye vererek işlem yapılan şeysiyi alıyoruz
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                push((int)pop() % (int)op2);
                break;
            case '\n':
                printf("\t%.8g\n", pop()); // oha amına koyim harbiden goat kod
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

#define MAXVAL 100 /* maximum depth of val stack */
int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */
/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}
/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include <ctype.h>
int getch(void);
void ungetch(int);
/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t') // boşluk veya tab olduğu sürece getch ile karakter almaya devam et.
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-') // digit değil ve nokta da değil o halde aradığımız bir karakter değil. dön
        return c; /* not a number */

    if (c == '-'){
        c = getch();
        if (c != EOF){
            ungetch(c);
        }
        // digit değilse çıkarmanın kendisi
        if (!isdigit(c)){
            return '-';
        }
    }


    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ; // burada fazladan karakter okuyoruz. sonraki karakter '.' mı diye. eğer nokta ise noktalı sayı kısmını alacağız.
    if (c == '.') /* collect fraction part */
    while (isdigit(s[++i] = c = getch()))
        ;
    s[i] = '\0';
    if (c != EOF) // eğer file sonu değilse fazladan okumuş olduğumuz karakteri bitane stack'te sakla.
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */
int getch(void) /* get a (possibly pushed-back) character */
{
    if (bufp > 0){
        return buf[--bufp];
    }
    return getchar();
}
void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}