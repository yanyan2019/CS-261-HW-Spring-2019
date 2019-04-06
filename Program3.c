/* Program3.c */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void sort(int* number, int n){ /* sort the numbers in accsending order */
	int i, j, temp;
	for(i = 0; i < n; i++){ /* loop through total number of elements */
		for(j = 0; j < n-i; j++){ /* exclude the sorted number */
			if(number[j] > number[j+1]){ /* swap two numbers */
				temp = number[j];
				number[j] = number[j+1];
				number[j+1] = temp;
			}
		}
	}
}

int main(){
	/* declare variables */
	int n = 20, i, j;
	int *arr_ptr = NULL;
	srand(time(NULL));
	
	arr_ptr = (int*) malloc(sizeof(int[n])); /* allocate space for integer array */

	printf("\n");
	for(i = 0; i < n; i++){ /* fill array with random integer from 0 to 100 */
		arr_ptr[i] = rand()%100;
		printf("%d ", arr_ptr[i]); /* print the content of the array */
	}
	printf("\n\n");
	sort(arr_ptr, n);
	
	for(j = 0; j < n ;j++){ /* print the sorted array */
		 printf("%d ", arr_ptr[j]);	
	}
	printf("\n");	
	return 0;
}
