/*
 * main.c
 *
 *  Created on: 1 oct. 2020
 *      Author: Matthias
 */

#include "list.h"

int main(int argc, char **argv) {
	list_t * myList = newList(); // empty list
	displayList(myList);
	// appends
	appendList(myList, 12.3);
	displayList(myList);
	appendList(myList, 4.3);
	displayList(myList);
	appendList(myList, 3.14);
	displayList(myList);
	appendList(myList, 7.32);
	displayList(myList);
	// inserts
	insertList(myList, 0, 1.1);
	displayList(myList);
	insertList(myList, 2, 6.6);
	displayList(myList);
	insertList(myList, myList->size, 9.9);
	displayList(myList);
	// removes
	removeList(myList, 2);
	displayList(myList);
	removeList(myList, 0); // first one
	displayList(myList);
	removeList(myList, myList->size-1); // last one
	displayList(myList);
	// read/write
	double value = getListAt(myList, 2);
	printf("Read at 2: %f\n", value);
	setListAt(myList, 2, 77.88);
	displayList(myList);
	// clean
	clearList(myList);
	displayList(myList);
	// free memory (inside is clean)
	free(myList);
}
