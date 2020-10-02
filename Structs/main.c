/*
 * main.c
 *
 *  Created on: 29 sept. 2020
 *      Author: Matthias
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "drink.h"


int main(void) {
	drink_t drink;
//	strcpy(drink.name,"Heineken");
//	drink.volume = 25;
//	drink.alcool = 6.5;
//	drink.temperature = 12.0;
	initDrink(&drink, "Heineken" , 25, 6.5, 12.0);
	displayDrink(&drink);
	drink_t drink2 = {"Paix Dieu", 33, 10.0, 13.2};
	displayDrink(&drink2);
	drink_t drink3 = {.name="Maredsous",.volume=75, .alcool=9.5, .temperature=14.2};
	displayDrink(&drink3);

	copyDrink(&drink, &drink2);
	displayDrink(&drink);
	drink_t * pdrink = newDrink("Lagunitas Daytime IPA", 33, 4.5, 12.1);
	displayDrink(pdrink);
	char buffer[255];
	drinkToString(buffer, pdrink);
	printf("Drink converted to string: %s\n", buffer);
	free(pdrink); pdrink = NULL;
	if (saveDrink(&drink, "beerOfToday.txt")) {
		printf("Beer in the fridge\n");
	} else {
		printf("Beer lost :(\n");
	}
	if ((pdrink=readDrink("beerOfToday.txt"))) {
		printf("From the bridge:");
		displayDrink(pdrink);
	} else {
		printf("\nBeer lost :(\n");
	}
	return EXIT_SUCCESS;
}

