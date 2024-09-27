// Zaid Orozco-Lerma
// Assignment 3

#include <stdio.h>
#include <stdlib.h>
#include "array.h"

// Initiation of our three functions. They will be below main for simplicity.
void output_array(Array *a);
void shift_array(Array *a);
Array *average_adjacent(Array *a);

int main(int argc, char *argv[]) {

	int array_size = atoi(argv[1]); // Here we are taking the command line argument for array size, converting it into an int from a string, and assigning it to a variable. 

	Array *array_data = (Array *) malloc(sizeof(Array)); 
	// 1) We initiate struct 'array_data' and assign to it the amount of space required for an 'Array' struct.
	array_data->size = array_size; 
	// 2) Within struct 'array_data', we set the member 'size' = to our array_size variable, defining the # of elements in our array. 
	array_data->data = (double *) malloc(array_size * sizeof(double)); 
	// 3) The second member (a pointer to a double) is assigned an address containing a chunk of space equal to [the array size] times [the space needed for a double].
	printf("		Code check: array size stored in struct for array: %d\n\n", array_data->size); // Sanity check for whether the given array size was saved properly.
	
	// Here, I wanted the option to input values as well as being able to generater them. It takes inputs from the user and will just generate the numbers instead if any non-numbers are inputted. 
	printf("Enter %d values for the array, or type any letter to automatically fill it with integers:\n\n", array_size);
	for(int i = 0; i < array_size; i++) {
		double temp;
		if (scanf("%lf", &temp) == 1) {
			array_data->data[i] = temp;
		}
		else {
			printf("\nFilling array automatically:\n");
    		for(int j = 0; j < array_size; j++) {
				array_data->data[j] = j;
				i = j;
			}
		}
	}

printf("============================================\n");
printf("\nOriginal array numbers:\n");
output_array(array_data);

shift_array(array_data);
printf("Shifted array numbers:\n");
output_array(array_data);

Array *average_array = average_adjacent(array_data);
printf("Averaged array numbers:\n");
output_array(average_array);

free(array_data->data);
free(array_data);
free(average_array->data);
free(average_array);

printf("============================================\n\n");

printf("Freed allocated memory. ");

return 0;
}


void output_array(Array *a) {
	printf("||");
	for(int i = 0; i < a->size; i++) {
		printf(" %f ||", a->data[i]);
	}
	printf("\n\n");
}

void shift_array(Array *a) {
	int temp = a->data[0];
	int i;
	for(i = 0; i+1 < a->size; i++) {
		a->data[i] = a->data[i+1];
	}

	a->data[i] = temp;
}

Array *average_adjacent(Array *a) {
	Array *b = (Array *) malloc(sizeof(Array)); 
	if(a->size % 2) {
		b->size = (a->size - 1) / 2;
	}
	else {
		b->size = a->size / 2;
	}

	b->data = (double *) malloc(b->size * sizeof(double));

	for(int i = 0; i < b->size; i++) {
		b->data[i] = (a->data[2*i] + a->data[2*i+1]) / 2;
	}

	return b;
}
