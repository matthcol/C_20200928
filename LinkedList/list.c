/*
 * list.c
 *
 *  Created on: 1 oct. 2020
 *      Author: Matthias
 */


#include "list.h"

// internal function to make new cell (not in .h)
cell_t * newCell(double value) {
	cell_t *res = malloc(sizeof(cell_t));
	if (res) {
		res->value = value;
		res->next = NULL;
	}
	return res;
}

list_t * newList() {
	list_t *res;
	if ((res=malloc(sizeof(list_t)))) {
		res->first = NULL;
		res->size = 0;
	}
	return res;
}

bool appendList(list_t *list, double value) {
	cell_t *cell = newCell(value);
	if (!cell) {
		return false;
	}
	cell_t *current = list->first;
	if (!current) { // empty list
		list->first = cell;
	} else {
		while (current->next) {
			current = current->next;
		}
		current->next = cell;
	}
	list->size++;
	return true;
}

bool insertList(list_t *list, size_t index, double value) {

}

bool removeList(list_t *list, size_t index) {
	return false;
}
bool clearList(list_t *list) {
	return false;
}
bool setListAt(list_t *list, size_t index, double value) {
	return false;
}
double getListAt(list_t *list, size_t index) {
	return NAN;
}

void displayList(list_t *list) {
	printf("[");
	for (cell_t *cell = list->first; cell; cell=cell->next) {
		printf("%f", cell->value);
		if (cell->next) {
			printf(", ");
		}
	}
	printf("]_%lu\n", list->size);
}
