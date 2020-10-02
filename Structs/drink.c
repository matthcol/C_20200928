/*
 * drink.c
 *
 *  Created on: 30 sept. 2020
 *      Author: Matthias
 */
#include "drink.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayDrink(const drink_t *drink) {
	printf("%s: %dcl, %f° A, %f°C\n",
			drink->name, drink->volume, drink->alcool, drink->temperature);
}

void initDrink(drink_t *drink, const char *name, short volume, double alcool, double temperature) {
	strcpy(drink->name, name);
	drink->volume = volume;
	drink->alcool = alcool;
	drink->temperature = temperature;
}

void copyDrink(drink_t *drink_to, const drink_t *drink_from) {
	initDrink(
			drink_to,
			drink_from->name, drink_from->volume, drink_from->alcool, drink_from->temperature);
}

drink_t * newDrink(const char *name, short volume, double alcool, double temperature) {
	drink_t *res = malloc(sizeof(drink_t));
	initDrink(res, name, volume, alcool, temperature);
	return res;
}

void drinkToString(char *buffer, const drink_t *drink) {
	sprintf(buffer, "%s (%dcl, %f° A, %f°C)",
			drink->name, drink->volume, drink->alcool, drink->temperature);
}

bool saveDrink(const drink_t *drink, const char *filename) {
	FILE * f = fopen(filename, "w");
	if (!f) {
		return false;
	}
//	char buffer[255];
//	drinkToString(buffer, drink);
	// can also use fputs
	fprintf(f, "%s,%d,%0.1f,%0.1f\n", drink->name, drink->volume,
			drink->alcool, drink->temperature);
	fclose(f);
	return true;
}

// TODO : handle \0 char reached if no '\n'
const char *readExtract(char *to, const char *pos, char sep) {
	int count = 0;
	const char *end = pos;
	while ((*end != sep) && (*end != '\n')) {
		end++;
		count++;
	}
	strncpy(to, pos, count);
	to[count] = '\0';
	return end;
}


drink_t *readDrink(const char *filename) {
	drink_t *res = NULL;
	FILE *f = fopen(filename, "r");
	if (!f) {
		return NULL;
	}
	char buffer[255];
	if (fgets(buffer, 255, f)) {
		// fscanf(f, "%s", buffer); // method to read one word
		// isspace for whitespace
		// feof
//		printf("Read drink: <%s>\n", buffer);
//		char lastChar = buffer[strlen(buffer)-1];
//		printf("Last character is \\n: %d\n", lastChar == '\n');
//		printf("Last character is whitespace: %d\n", isspace(lastChar));
		char extract[255];
		char name[50];
		short volume;
		double alcool;
		double temperature;
		const char *pos = buffer;
		// TODO: handle parsing errors
		pos = readExtract(name, pos, ',');
		pos = readExtract(extract, pos+1, ',');
		volume = (short) atoi(extract);
		pos = readExtract(extract, pos+1, ',');
		alcool = atof(extract);
		pos = readExtract(extract, pos+1, ',');
		temperature = atof(extract);
		res = newDrink(name, volume, alcool, temperature);
	}
	fclose(f);
	return res;
}






