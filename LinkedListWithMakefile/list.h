/*
 * list.h
 *
 *  Created on: 1 oct. 2020
 *      Author: Matthias
 */

#ifndef LIST_H_
#define LIST_H_

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

typedef struct _cell_t {
	double value;
	struct _cell_t *next;
} cell_t;

typedef struct {
	cell_t *first;
	size_t size;
} list_t;

list_t * newList();
bool appendList(list_t *list, double value);
bool insertList(list_t *list, size_t index, double value);
bool removeList(list_t *list, size_t index);
bool clearList(list_t *list);
bool setListAt(list_t *list, size_t index, double value);
double getListAt(const list_t *list, size_t index);
void displayList(const list_t *list);
#endif /* LIST_H_ */
