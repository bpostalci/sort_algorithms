/*
 * quickSort.c
 * 
 * Copyright 2017 instantcrush <instantcrush>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//Make PRINT 1 to display generated random array and its sorted version
#define PRINT 0  // 0:disable print, 1:enable print

void equalKeysGenerator(int *A, int n) {
	
	for(int i = 0; i < n; i++) {
		A[i] = 55;
	}
}

//To sort in descending order
void desSort(int *A, int n) {
	
	int tmp;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i;j++)
		{
			if(A[j]<A[j+1])
			{
				tmp=A[j+1];
				A[j+1]=A[j];
				A[j]=tmp;
			}
		}
		#if PRINT == 1
		printf("arr[%d] = %d\n", i, A[i]);
		#endif
	}
}

void generateDescendingArray(int *arr, int n) {
	
	for(int i = n - 1; i >= 0; i--) {
		arr[n-i-1] = i;
		#if PRINT == 1
		printf("arr[%d] = %d\n", n-i-1, arr[n-i-1]);
		#endif
	}
}


void randomArrayGenerator(int *arr,int n) {
	
	for(int i = 0; i < n; i++) {
		arr[i] = rand() % n; //range: [0 - n]
		#if PRINT == 1
		printf("%d\n", arr[i]);
		#endif
	}
	
	#if PRINT == 1
	for(int i = 0; i < n; i++)
		printf("-");
	printf("\n");
	#endif
}

void swap(int *i, int *j) {
	int temp = *i;
	*i = *j;
	*j = temp;
}	

int partition(int *A, int start, int end) {
	
	int pivot = A[start];
	int i = start;
	int j = end + 1;
	
	while(j > i) {
		
		do { i++;
		} while(pivot > A[i]);
		
		do { j--;
		} while(pivot < A[j]);
		
		swap(&A[i], &A[j]);
		
	}
	swap(&A[i], &A[j]); //undo last swap when i >= j
	swap(&A[start], &A[j]);

	return j;
}

void quickSort(int *A, int start, int end) {
	
	if(end > start) {
		int s = partition(A, start, end); //split position
		quickSort(A, start, s - 1); //sort before the split
		quickSort(A, s + 1, end); //sort after the split
	}
}


int main() {
	//To randomize numbers
	srand(time(0));
	//For CPU running time measurement
	clock_t start, end;
	double cpu_time_used;
	
	printf("QUICKSORT ALGORITHM\n********************\n\n");
	
	
	int type;
	
	printf("Enter 1 to test your inputs\nEnter 2 to make automated tests(A1 - A2 - B1 - B2)\nChoice: ");
	scanf("%d", &type);
	
	if(type == 1) { 
		int n;
	
		printf("Enter how many random numbers do you want: ");
		scanf("%d", &n);
		
		
		int A[n];
		int choice;
		
		printf("\nEnter 1 to generate random numbers\nEnter 2 to generate descending order numbers\nEnter 3 to generate equal keys\nChoice: ");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
			randomArrayGenerator(A, n); //range depends on given n --> [0 - n]
			break;
			
			case 2:
			generateDescendingArray(A, n);
			break;
			
			case 3:
			equalKeysGenerator(A, n);
			break;
		}
		
		start = clock(); //To just measure algorithm's running time
		quickSort(A, 0, n-1);
		end = clock();
		
		#if PRINT == 1
		printf("After quick sort\n");
		
		
		for(int i = 0; i < n; i++)
			printf("A[%d] = %d\n", i, A[i]);
		#endif
		
		
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		
		switch(choice) {
			case 1:
			printf("\nCPU time used with -randomly generated- numbers = %.8f seconds\n", cpu_time_used);
			break;
			case 2:
			printf("\nCPU time used with -descending ordered- numbers = %.8f seconds\n", cpu_time_used);
			break;
			case 3:
			printf("\nCPU time used with equal keys = %.8f seconds\n", cpu_time_used);
			break;
		}
		
	} 
	else if(type == 2) { //Automated test cases A1 - A2 - B1 - B2
							
		int choice;
		int n;
		double average;
		
		printf("\nEnter 1 to make A1 test\nEnter 2 to make A2 test\nEnter 3 to make B1 test\nEnter 4 to make B2 test\nChoice: ");
		scanf("%d", &choice);
		
		if(choice == 1) {
			//For A1
			n = 4095;
			int A[n];
			
			printf("\nA1 Test\n");
			for(int i = 0; i < 12; i++) {
				
				randomArrayGenerator(A, n);
				
				start = clock();
				quickSort(A, 0, n-1);
				end = clock();
				
				cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
				printf("\n%d) %.8f\n", i + 1, cpu_time_used);
				average += cpu_time_used;
				
			}
			//Display average running time
			printf("\nAverage running time of A1 test: %.8f\n", average/12.0);
		}
		else if(choice == 2) {
			//For A2
			n = 32737;
			int A[n];
			
			printf("\nA2 Test\n");
			for(int i = 0; i < 12; i++) {
				randomArrayGenerator(A, n);
				
				start = clock();
				quickSort(A, 0, n-1);
				end = clock();
				
				cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
				printf("\n%d) %.8f\n", i + 1, cpu_time_used);
				average += cpu_time_used;
				
			}
			//Display average running time
			printf("\nAverage running time of A2 test: %.8f\n", average/12.0);
			
		}
		else if(choice == 3) {
			//For B1
			n = 4095;
			int A[n];
			
			printf("\nB1 Test\n");
			for(int i = 0; i < 12; i++) {
				randomArrayGenerator(A, n);
				desSort(A, n); //Sort in descending order
				
				start = clock();
				quickSort(A, 0, n-1);
				end = clock();
				
				cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
				printf("\n%d) %.8f\n", i + 1, (double)cpu_time_used);
				average += cpu_time_used;
				//printf("\n%d) %.8f\n", i + 1, cpu_time_used);
			}	
			printf("\nAverage running time of B1 test: %.8f\n", average/12.0);
		}
		else if(choice == 4) {
			//For B2
			n = 32767;
			int A[n];
			
			printf("\nB2 Test\n");
			for(int i = 0; i < 12; i++) {
				randomArrayGenerator(A, n);
				desSort(A, n); //Sort in descending order
				
				start = clock();
				quickSort(A, 0, n-1);
				end = clock();
				
				cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
				printf("%d) %.8f\n", i + 1, cpu_time_used);
				average += cpu_time_used;
				//printf("\n%d) %.8f\n", i + 1, cpu_time_used);
			}	
			printf("\nAverage running time of B2 test: %.8f\n", average/12.0);
		}
	} else {
		
		return 0;
		
	}
	
	
	
	
	return 0;
}

