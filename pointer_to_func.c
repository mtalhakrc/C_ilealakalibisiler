//
// Created by Talha Karaca on 29.09.2023.
//

#include <stdio.h>

int deneme(int gg){
    return gg;
}

int deneme2(int (*pointertofunc)(int),int gg){
    return (*pointertofunc)(gg);
}

int main(int argc, char *argv[]){
    int gg = 10;
    int res = deneme2(deneme,gg);
    printf("%d\n", res);
}


