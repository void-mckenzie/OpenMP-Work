#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <time.h>
#include "omp.h"


int len_arr= 3*26214400; 
int numthreads = 8;

void quickSort_parallel(int* array, int lenArray, int numThreads);
void quickSort_parallel_main(int* array, int left, int right, int buffer);



void quickSort_parallel(int* array, int lenArray, int numThreads){

	int buffer = 1000;

	#pragma omp parallel num_threads(numThreads)
	{	
		#pragma omp single nowait
		{
			quickSort_parallel_main(array, 0, lenArray-1, buffer);	
		}
	}	

}



void quickSort_parallel_main(int* array, int left, int right, int buffer) 
{

	int i = left, j = right;
	int tmp;
	int pivot = array[(left + right) / 2];

	
	{
	  	
		while (i <= j) {
			while (array[i] < pivot)
				i++;
			while (array[j] > pivot)
				j--;
			if (i <= j) {
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				i++;
				j--;
			}
		}

	}


	if ( ((right-left)<buffer) ){
		if (left < j){ quickSort_parallel_main(array, left, j, buffer); }			
		if (i < right){ quickSort_parallel_main(array, i, right, buffer); }

	}else{
		#pragma omp task 	
		{ quickSort_parallel_main(array, left, j, buffer); }
		#pragma omp task 	
		{ quickSort_parallel_main(array, i, right, buffer); }		
	}

}


void quickSort(int* arr, int left, int right) 
{
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}

	if (left < j){ quickSort(arr, left, j);  }
	if (i< right){ quickSort(arr, i, right); }
}

int main()
{
	int min = 1;
	int max = len_arr;

	double startTime, stopTime;

	int* arr2; 
	int* arr3;

	arr2 = (int*) malloc(len_arr*sizeof(int));
	arr3 = (int*) malloc(len_arr*sizeof(int));
	
	int i;
	srand(27);
	printf("Array is initialized\n");
	for (i=0; i<len_arr; i++){
		arr2[i] = min+(rand()%max);
		arr3[i] = arr2[i];
	}
	printf("Initialization complete\n");


	printf("\nSerial QuickSort Algorithm:"); fflush(stdout);
	startTime = clock();
	quickSort(arr2, 0, len_arr-1);
	stopTime = clock();

	printf("\nTime taken: %f seconds \n\n", (double)(stopTime-startTime)/CLOCKS_PER_SEC);

	printf("\nParallel QuickSort Algorithm:"); fflush(stdout);
	startTime = omp_get_wtime();
	quickSort_parallel(arr3, len_arr, numthreads);
	stopTime = omp_get_wtime();

	printf("\nTime taken: %f seconds \n\n", (stopTime-startTime));


	free(arr2);
	free(arr3);

	return 0;
}