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
	if (index > list-> size) {
		return false;
	}
	// create new cell
	cell_t *cell = newCell(value);
	if (!cell) {
		return false;
	}
	// insert new cell
	if (!list->first || index == 0) {
		// insert at beginning
		cell->next = list->first; // rest of list or empty list
		list->first = cell;
	} else {
		// insert at index from 1 to size
		cell_t *current = list->first;
		// shift index-1 times
		for (size_t i=1; i<index; i++) {
			 current = current->next;
		}
		// change pointers
		cell_t * after = current->next;
		current->next = cell;
		cell->next = after;
	}
	list->size++;
	return true;
}

bool removeList(list_t *list, size_t index) {
	if (index > list-> size) {
		return false;
	}
	// look for cell to remove
	cell_t *cell = NULL;
	if (index == 0) {
		// remove at beginning
		cell = list->first;
		list->first = cell->next;
	} else {
		// remove at index from 1 to size
		cell_t *current = list->first;
		// shift index-1 times
		for (size_t i=1; i<index; i++) {
			 current = current->next;
		}
		cell = current->next;
		current->next = cell->next;
	}
	// free memory from cell removed
	free(cell);
	list->size--;
	return true;
}

bool clearList(list_t *list) {
	// free inside cells
	cell_t *current = list->first;
	while (current) {
		cell_t *next = current->next;
		free(current);
		current = next;
	}
	// reset struct list
	list->first = NULL;
	list->size = 0;
	return true;
}

bool setListAt(list_t *list, size_t index, double value) {
	if (index >= list-> size) {
		return false;
	}
	// look for cell to set
	cell_t *current = list->first;
	for (size_t i=0; i<index; i++) {
		current = current->next;
	}
	current->value = value;
	return true;
}

double getListAt(const list_t *list, size_t index) {
	if (index >= list-> size) {
		return NAN;
	}
	// look for cell to set
	cell_t *current = list->first;
	for (size_t i=0; i<index; i++) {
		current = current->next;
	}
	return current->value;
}

void displayList(const list_t *list) {
	printf("[");
	for (cell_t *cell = list->first; cell; cell=cell->next) {
		printf("%f", cell->value);
		if (cell->next) {
			printf(", ");
		}
	}
	printf("]_%lu\n", list->size);
}
