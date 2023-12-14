//
// Created by Talha Karaca on 18.09.2023.
//

//Exercise 3-1. Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside.)
// Write a version with only one test inside the loop and measure the difference in run-time.

#include <stdio.h>
#include <time.h>


/* binsearch:  find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high)/2;
        if (x < v[mid]){
            high = mid -1;
        }else {
            low = mid + 1;
        }
    }
    if(x == v[low - 1]){
        return mid;
    }
    return -1;   /* no match */
}

int main(){
    clock_t start_time, end_time;

    start_time = clock();
    int numbers[] = {1,5,34,43,51,90,121,200};
    int len;
    len = 8;
    int found;
    found = binsearch(1, numbers, len);
    printf("%d\n",found);

    end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Program süresi: %f saniye\n", elapsed_time);

    return 0;

}