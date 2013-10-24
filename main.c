#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tables.h"
#include "stack.h"
#include "unit.h"
#include "main.h"



/*
 * This code solves a question I was asked at the google interview.
 *
 * Given a name, determine if it can be formed from element names
 * from the periodic table.  Bonus points if you can form the name.
 * 
 * Consider the elements from the periodic table as tiles.
 * Hydrogen is tile H.
 * Helium is tile He.
 * 
 * When forming names, the lowercase second or third letter
 * is significant.  For instance tile 'He' would work for names
 * which have a name consiting of the diagraph he, that is
 * He_nry, Matt_he_w, etc.
 *
 * When given the question I was told to ignore three letter
 * tiles, but since I am doing this for myself, I am including 
 * those tiles as well.
 *
 */ 






int main(int argc, char *argv[]) {

	int iRC;

	iRC=EXIT_SUCCESS;

	if (argc != 1) {
		fprintf(stderr, "Usage: %s \n", argv[0]);
		iRC=EXIT_FAILURE;
		exit(iRC);
	}
	build_tiles2();

	unit_tests();
	
	exit(iRC);

}





