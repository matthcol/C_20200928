/*
 * vector.h
 *
 *  Created on: 30 sept. 2020
 *      Author: Matthias
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	double * array;
	size_t size;
} vector_t;

/**
 *  allocate array memory area of a vector struct :
 *    - with size elements
 *    - without init value
 */
bool initVector(vector_t *vector, size_t size);

/**
 * allocate new struct vector and its memory area
 *    - with size elements
 *    - without init value
 */
vector_t *newVector(size_t size);

void fillVector(vector_t *vector, double value);

/**
 * display vector in stdout
 * if size is greater than 10 display first 5 and last 5 elements
 */
void displayVector(const vector_t *vector);

void cleanVector(vector_t *vector);

void deleteVector(vector_t **vector);

#endif /* VECTOR_H_ */
