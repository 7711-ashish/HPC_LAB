#include<stdio.h>
#include<omp.h>

int sort(int arr[], int n)
{
	int i, j;
	#pragma omp parallel private(j)
	#pragma omp for schedule(dynamic)
	for (i = 0; i < n-1; i++)
	{
		for (j = 0; j < n-i-1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int sort_des(int arr[], int n)
{
	int i,j;
	#pragma omp parallel private(j)
	#pragma omp for schedule(dynamic)
	for (i = 0; i < n; ++i)
	{
		for (j = i + 1; j < n; ++j)
		{
			if (arr[i] < arr[j])
			{
				int a = arr[i];
				arr[i] = arr[j];
				arr[j] = a;
			}
		}
	}
}


int main()
{
	int arr1[5]={1,2,3,4,5}, arr2[5]={1,2,3,4,5};
	int i;
	double time1 = omp_get_wtime();
	sort(arr1, 5);
	sort_des(arr2, 5);
	int sum = 0;
	#pragma omp parallel for reduction(+:sum)
	for(i = 0; i < 5 ; i++)
	{
		sum = sum + (arr1[i] * arr2[i]);
	}
	printf("%d",sum);
	double time2 = omp_get_wtime();
    double time_requried = time2-time1;
    printf("\nParallel %lf\n", time_requried);
	
	return 0;
}