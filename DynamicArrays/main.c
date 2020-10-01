/*
 * main.c
 *
 *  Created on: 30 sept. 2020
 *      Author: Matthias
 */
#include <stdio.h>
#include <stdlib.h>

#include "vector.h"



void setGetVector(vector_t *vector, size_t index) {
	double value = 7.5;
	printf("Test Set/Get vector at index: %d\n", index);
    if (setVectorAt(vector, index, value)) {
		printf("Vector after set:");
		displayVector(vector);
		double valueRead = getVectorAt(vector, index);
		printf("\nRead value: %f\n", valueRead);
    } else {
    	printf("Error while setting vector");
    }
}

void testSetGetVector(vector_t *vector) {
	setGetVector(vector, 4);  // correct index
	setGetVector(vector, 150); // out of bound index
}

// int main(void) {  // args and env are ignored
int main(int argc, char **argv) { // args in command line
	printf("Nb of args: %d\n", argc);
	for (int i=0; i<argc; i++) {
		printf("\t- Arg %d : %s\n", i, argv[i]);
	}
	vector_t vectorStack;
	if (initVector(&vectorStack, 100)) {
		fillVector(&vectorStack, 1.0);
		displayVector(&vectorStack);
		testSetGetVector(&vectorStack);
		// clean memory
		// vectorStack : clean internal array
		cleanVector(&vectorStack);
		// set/get after clean
		testSetGetVector(&vectorStack);
	}

	printf("\n--------\n");

	vector_t * pVectorHeap = NULL;
	if ((pVectorHeap = newVector(100))) {
		fillVector(pVectorHeap, 2.0);
		displayVector(pVectorHeap);
		testSetGetVector(pVectorHeap);
		// clean memory
		// pVectorHeap : clean internal array + clean struct
		deleteVector(&pVectorHeap);
	}
	printf("\nThe End !");

	return EXIT_SUCCESS;
}

