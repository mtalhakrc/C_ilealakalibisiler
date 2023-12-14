//
// Created by Talha Karaca on 12.10.2023.
//


//Add commands for handling variables.
// (It's easy to provide twenty-six variableswith single-letter names.)
// Add a variable for the most recently printed value

#include <stdio.h>
#include <stdlib.h>
#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);
void swap();
void duplicate();
void clear();

#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

int main()
{
    int type;
    double op2;
    int tmp;
    char s[MAXOP]; // operatörleri tutuyoruz. getop'ye vererek işlem yapılan şeysiyi alıyoruz
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                printf("\t%.8g\n", pop());
                break;
            case '*':
                push(pop() * pop());
                printf("\t%.8g\n", pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                printf("\t%.8g\n", pop());
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                printf("\t%.8g\n", pop());
                break;
            case '%':
                op2 = pop();
                push((int)pop() % (int)op2);
                printf("\t%.8g\n", pop());
                break;
            case 'p':
                tmp = sp;
                if (!tmp){
                    printf("empty stack:\n");
                    break;
                }
                printf("stack:\n");
                while(tmp--){
                    printf("%.2f\n----\n", val[tmp]);
                }
                break;
            case '\n':
                break;
            case 's':
                swap();
                break;
            case 'd':
                duplicate();
                break;
            case 'c':
                clear();
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void swap(){
    if (sp < 1){
        printf("should at least 2 item\n");
        return;
    }
    double tmp1;
    double tmp2;
    tmp1 = pop();
    tmp2 = pop();
    push(tmp2);
    push(tmp1);
}

void duplicate(){
    double tmp = pop();
    push(tmp);
    push(tmp);
    return;
}

void clear() {
    sp = 0;
}

#include <ctype.h>
int getch(void);
void ungetch(int);
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
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ; // burada fazladan karakter okuyoruz. sonraki karakter '.' mı diye. eğer nokta ise noktalı sayı kısmını alacağız.
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF) // eğer file sonu değilse fazladan okumuş olduğumuz karakteri bitane stack'te sakla.
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
int getch(void)
{
    if (bufp > 0){
        return buf[--bufp];
    }
    return getchar();
}
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}