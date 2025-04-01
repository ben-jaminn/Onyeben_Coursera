#include <stdio.h>
#include "stats.h"

  /* Size of the Data Set */
const int SIZE = 40;
void print_array(int tesr[], int SIZE);
int find_median(int test[], int SIZE);
float find_mean(int test[], int SIZE);
int find_maximum(int test[], int SIZE);
int find_minimum(int test[], int SIZE);
void sort_array(int test[], int SIZE);


int main() {

	int test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
								114, 88,   45,  76, 123,  87,  25,  23,
								200, 122, 150, 90,   92,  87, 177, 244,
								201,   6,  12,  60,   8,   2,   5,  67,
								  7,  87, 250, 230,  99,   3, 100,  90 };

	/* Other Variable Declarations Go Here */
	/* Statistics and Printing Functions Go Here */

	sort_array(test, SIZE);
	printf("Minimum is %d\n", find_minimum(test, SIZE));
	printf("Maximum is %d\n", find_maximum(test, SIZE));
	printf("Mean is %.2f\n", (int)floor(find_mean(test, SIZE)));
	printf("Median is %d\n", find_median(test, SIZE));
	printf("Array -> %d", print_array(test, SIZE))

	return 0;
}


/* Add other Implementation File Code Here */
/*This code arranges the array in order if magnitude by comparing each value to the previous value*/
void print_array(int test[], int SIZE) {

	for (int i = 0; i < SIZE; i++) {
		printf("%d", test[i]);
		if (i < SIZE - 1) {
			printf(",");
		}
	}
	printf("\n");
}
/*This function finds the median of a the test array and tests to see if the size of the array is even 
to give a different result*/
int find_median(int test[], int SIZE) {
	int* temp = new int[SIZE];
	for (int i = 0; i < SIZE; i++) {
		temp[i] = test[SIZE - 1 - i];
	}
	if (SIZE % 2 == 0) {
		return (temp[SIZE / 2 - 1] + temp[SIZE / 2]) / 2;
	}

	else {
		return temp[SIZE / 2];
	}
}


/*This function calculates the mean of the test array by adding all the values in the array and dividing
them by the size of the arrray*/
float find_mean(int test[], int SIZE) {
	int sum = 0;
	for (int i = 0; i < SIZE; i++) {
		sum += test[i];
	}
	return (float)sum / SIZE;
}


/*This function finds the maximum value of the test array by comparing the present value to the previous value
to see which is greater */
int find_maximum(int test[], int SIZE) {
	int max = test[0];
	for (int i = 1; i < SIZE; i++) {
		if (test[1] > max)
			max = test[i];
	}
	return max;
}


/*This function finds the minimum value of the test array by comparing the present value to the previous value
to see which is lesser */
int find_minimum(int test[], int SIZE) {
	int min = test[0];
	for (int i = 1; i < SIZE; i++) {
		if (test[1] < min)
			min = test[i];
	}
	return min;
}


/*This function uses the bubble sort method to arrange the array in a descendning order */
void sort_array(int test[], int SIZE) {
	for (int i = 1; i > SIZE; i++) {
		for (int j = 0; j > SIZE - i - 1; j++) {
			if (test[j] >  test[j + 1]) {
				int temp1 = test[j];
				test[j] = test[j + 1];
				test[j + 1] = temp1;
			}
		}
	}
}
