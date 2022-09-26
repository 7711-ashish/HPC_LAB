#include <stdio.h>
#include <omp.h>
#include <time.h>

int main(int argc, char **argv)
{

    double start;
    double end;
    start = omp_get_wtime();

    #pragma omp parallel num_threads(3)
    {
        printf("Hello from process: %d\n", omp_get_thread_num());
    }
    end = omp_get_wtime();
    printf("Work took %f seconds\n", end - start);
    return 0;
}