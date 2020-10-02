/*
 * drink.h
 *
 *  Created on: 30 sept. 2020
 *      Author: Matthias
 */

#ifndef DRINK_H_
#define DRINK_H_

#include <stdbool.h>

typedef struct {
	char name[30];  // static
	short volume;  // cl
	double alcool; // degree of alcool
	double temperature;  // degree Celcius
} drink_t;

void displayDrink(const drink_t *drink);
void initDrink(drink_t *drink, const char *name, short volume, double alcool, double temperature);
void copyDrink(drink_t *drink_to, const drink_t *drink_from);
drink_t * newDrink(const char *name, short volume, double alcool, double temperature);
void drinkToString(char *buffer, const drink_t *drink);

bool saveDrink(const drink_t *drink, const char *filename);
drink_t *readDrink(const char *filename);


#endif /* DRINK_H_ */
