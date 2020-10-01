/*
 * main.c
 *
 *  Created on: 1 oct. 2020
 *      Author: Matthias
 */

#include "list.h";

int main(int argc, char **argv) {
	list_t * myList = newList(); // empty list
	displayList(myList);
	appendList(myList, 12.3);
	displayList(myList);
	appendList(myList, 4.3);
	displayList(myList);
	appendList(myList, 3.14);
	displayList(myList);
	appendList(myList, 7.32);
	displayList(myList);
	insertList(myList, 2, 6.6);
	displayList(myList);
	removeList(myList, 1);
	displayList(myList);
	double value = getListAt(myList, 2);
	printf("Read at 2: %f\n", value);
	setListAt(myList, 2, 77.88);
	displayList(myList);
	clearList(myList);
	displayList(myList);
}
