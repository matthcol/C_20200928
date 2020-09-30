/*
 * main.c
 *
 *  Created on: 30 sept. 2020
 *      Author: Matthias
 */
#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

// int main(void) {  // args and env are ignored
int main(int argc, char **argv) { // args in command line
	printf("Nb of args: %d\n", argc);
	for (int i=0; i<argc; i++) {
		printf("\t- Arg %d : %s\n", i, argv[i]);
	}
	vector_t vectorStack;
	if (initVector(&vectorStack, 10000000000)) {
		fillVector(&vectorStack, 1.0);
		displayVector(&vectorStack);
		// clean memory
		// vectorStack : clean internal array
		cleanVector(&vectorStack);

	}

	printf("\n--------\n");

	vector_t * pVectorHeap = NULL;
	if ((pVectorHeap = newVector(10000000000))) {
		fillVector(pVectorHeap, 2.0);
		displayVector(pVectorHeap);
		// clean memory
		// pVectorHeap : clean internal array + clean struct
		deleteVector(&pVectorHeap);
	}
	printf("\nThe End !");

	return EXIT_SUCCESS;
}

