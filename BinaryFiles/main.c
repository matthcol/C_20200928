/*
 * main.c
 *
 *  Created on: 2 oct. 2020
 *      Author: Matthias
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	unsigned short dataShort = 0xa3b1; // 41905
	printf("Data short: %u %x\n", dataShort, dataShort);
	FILE *fout = fopen("data.dat", "wb");
	if (fout) {
		fwrite(&dataShort,sizeof(unsigned short), 1, fout);
		fclose(fout);
	}
	return EXIT_SUCCESS;
}
