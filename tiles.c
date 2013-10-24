#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "tables.h"
#include "stack.h"
#include "tiles.h"





int find_name(char *pchName,stack_t *pResult) {
	int iRC = EXIT_FAILURE;
	if (0 == pchName[0]) {
		return (EXIT_SUCCESS);
	}
	if ( exists1(pchName[0]) ) {
		push(pResult,pchName[0]);
		iRC = find_name(((char *)&pchName[1]),pResult);	
	} 
	// Edge case, it could find something with one char which
	// is a dead end, so we have to try to double chars
	// so continue on. However, if it finds one and it is the 
	// last char we stop.
	if (iRC == EXIT_SUCCESS && (0 == pchName[1])) {
		return iRC;
	}
	// Edge case, if we don't have two chars left, we must
	// stop looking.
	if (0 == pchName[1]) {
		pop(pResult);	// Toss the last success
		return EXIT_FAILURE;
	}
	if (exists2(pchName[0],pchName[1] )) {
		push(pResult,pchName[0]);
		push(pResult,pchName[1]+32);
		iRC = find_name(((char *)&pchName[2]),pResult);	
	}
	return iRC;
}




