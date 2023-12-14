//
// Created by Talha Karaca on 19.10.2023.
//

#ifndef C_PROGRAMMING_LANGUAGE_PROBLEMS_MAIN_H
#define C_PROGRAMMING_LANGUAGE_PROBLEMS_MAIN_H

#endif //C_PROGRAMMING_LANGUAGE_PROBLEMS_MAIN_H

#define SIZE 1000

#define BUFSIZE 100

int getch(void);

void ungetch(int);

int getint(int*);

char buf[BUFSIZE]; /* buffer for ungetch */

int bufp = 0; /* next free position in buf */
