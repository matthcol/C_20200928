/*
 * main.c
 *
 *  Created on: 30 sept. 2020
 *      Author: Matthias
 */

#include "vector.h"

int main() {
	vector_t vectorStack;
	initVector(&vectorStack, 10);
	fillVector(&vectorStack, 1.0);
	displayVector(&vectorStack);

	printf("\n--------\n");

	vector_t * pVectorHeap = newVector(1000000);
	fillVector(pVectorHeap, 2.0);
	displayVector(pVectorHeap);

	// clean memory
	// vectorStack : clean internal array
	cleanVector(&vectorStack);
	// pVectorHeap : clean internal array + clean struct
	cleanVector(pVectorHeap);
	free(pVectorHeap); pVectorHeap=NULL;
}

