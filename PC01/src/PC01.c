/* Name: Andres Santiago Orozco Gorjon (Santi)
 * Email: aorozcog@nd.edu
 * File name: PC01.c
 * Contents: main() for PC01
 */

#include <stdio.h>
#include "../include/rotations.h"

int main() {

	while (1) {
		// Receive first line of input: Array length, number of rotations, direction (L/R)
		int array_len, rotations;
		char direction;
		fprintf(stdout, "Enter the size, number of rotations, and direction (L/R): ");
		fscanf(stdin, "%d %d %c", &array_len, &rotations, &direction);

		// Receive second line of input: array elements
		int theArray[array_len];
		fprintf(stdout, "Input the %d values: ", array_len);
		for (int i = 0; i < array_len; ++i) {
			fscanf(stdin, "%d", &theArray[i]);
		}

		// Before rotation: Display
		fprintf(stdout, "Before rotation:\n");
		offset_intArray_print(theArray, array_len, 0);

		// Rotation: Calculate offset based on rotations and direction
		int offset = rotations % array_len;
		switch (direction) {
			case 'L':
				break;
			case 'R':
				offset = array_len - offset;
				break;
			default:
				fprintf(stderr, "Error: Unrecognizable input '%c' for direction\n", direction);
				return 1;
		}
				
		// Rotation: Display
		fprintf(stdout, "After rotation:\n");
		offset_intArray_print(theArray, array_len, offset);

		// Ask to continue or quit
		switch (keepGoing()) {
			case 1:
				break;
			case 0:
				return 0;
			case -1:
				fprintf(stderr, "Error: Input not recognized\n");
				return 1;
		}
	}
}
