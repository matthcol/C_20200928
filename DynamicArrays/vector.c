/*
 * vector.c
 *
 *  Created on: 30 sept. 2020
 *      Author: Matthias
 */

#include <stdio.h>

#include "vector.h"


bool initVector(vector_t *vector, size_t size) {
	double *array = malloc(size*sizeof(double));
	if (array) { // pointer is NULL if malloc fails
		vector->array = array;
		vector->size = size;
		return true;
	}
	return false;
}

vector_t *newVector(size_t size) {
	vector_t *res;
	res = malloc(sizeof(vector_t));
	if (res) {  // struct allocation is ok
		if (initVector(res, size)) {
			return res;
		}
		free(res); // struct is allocated, array not allocated
	}
	return NULL; // struct or array is not allocated
}


void fillVector(vector_t *vector, double value) {
	for (size_t i=0; i < vector->size; i++) {
		vector->array[i] = value;
	}
}

void _displayArray(const char *format, const double* array, size_t size) {
	for (size_t i=0; i < size; i++) {
		printf(format, array[i]);
	}
}

void displayVector(const vector_t *vector){
	printf("[ ");
	if (vector->size <= 10) {
		_displayArray("%.3f ", vector->array, vector->size);
	} else {
		_displayArray("%.3f ", vector->array, 5);
		printf("... ");
		_displayArray("%.3f ", &vector->array[vector->size-5], 5);
	}
	printf("]%I64d", vector->size);
}

void cleanVector(vector_t *vector) {
	free(vector->array);
	// protect illegal use of this deteriorated vector
	vector->array = NULL;
	vector->size = 0;
}

void deleteVector(vector_t **vector) {
	cleanVector(*vector);
	free(*vector);
	*vector=NULL;
}
