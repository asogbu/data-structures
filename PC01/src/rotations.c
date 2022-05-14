/* Name: Andres Santiago Orozco Gorjon (Santi)
 * Email: aorozcog@nd.edu
 * File name: rotations.c
 * Contents: Function definitions for PC01
 */

#include <stdio.h>

int keepGoing() {
	fprintf(stdout, "Do you wish to continue? (y/n): ");

	char userInput;
	fscanf(stdin, " %c", &userInput);

	switch (userInput) {
		case 'y':
			return 1;
		case 'n':
			return 0;
		default:
			return -1;
	}
}

void offset_intArray_print(int theArray[], int array_len, int offset) {
	for (int i = 0; i < array_len; ++i) {
		int rotated_i = (i + offset) % array_len;
		fprintf(stdout, "%d at %p\n", theArray[rotated_i], &theArray[rotated_i]);
	}
}
