#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    clock_t begin = clock();
    int n = 200, i ,j=99;
    int arr1[n], answer[n];
    for(i = 0; i < n; i++){
        arr1[i] = rand()%100;
    }    
    #pragma omp parallel for schedule(static,20) shared(arr1, answer,j) private(i)
    for(i = 0; i < n; i++)
    {
        answer[i] = arr1[i] + j;
    }
    printf("\nArray 1: \n");
    for(i = 0; i < n; i++){
        printf("\t %d", arr1[i]);
    }
    printf("\nAnswer: \n");
    for(i = 0; i < n; i++){
        printf("\t %d", answer[i]);
    }
    clock_t end = clock();
    double time_execution = (double)(end-begin)/CLOCKS_PER_SEC;
    printf("\nTime for execution: %lf", time_execution);
    return 0;
}