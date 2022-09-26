#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[])
{
	printf("\nExecution With Parallel running...\n");
    clock_t begin = clock();
    //program to add square of the numbers
    int number = 0, addittion = 0;
    #pragma omp parallel for
    for(int i = 0 ; i <= 10; i++)
    {
        printf("\tSquare of %d: %d", i, i*i);
        addittion += i*i;
    }
    clock_t end = clock();
    double time = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nAddition of first 10 squares: %d", addittion);
	printf("\nExecution Time: %lf", time);
}