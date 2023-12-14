#include <stdio.h>
#include <stdlib.h>

int main(void){
    int arr[] = {1,2,3,4};

    int *p1 = &arr;
    int *p2 = &arr[0];

    printf("%p - %p \n", p1,p2);
    printf("%lu - %lu \n", sizeof (p1),sizeof (p2));
    printf("%lu\n", sizeof (arr));

    printf("\");

}