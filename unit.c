#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "unit.h"
#include "stack.h"
#include "tiles.h"
#include "main.h"



//	iRC=EXIT_SUCCESS;
//	iRC=EXIT_FAILURE;

// Possible names from this list: BOB, HUNYH, STU, PWWN
// Names to Test, Bruce, Allen, Linda, Huynh, Matt, John, Manish, Johnathon, Ehud, David, Jan
int test1() {

	int iRC=EXIT_FAILURE;	// Assume failure.
	stack_t stResult;

	iRC = find_name("BOB",&stResult);
	if (EXIT_SUCCESS == iRC) {
		dump_stack(&stResult);
		return (EXIT_SUCCESS);
	} else {
		iRC = EXIT_FAILURE;
	}
	return (iRC);
}


int test2() {

	int iRC=EXIT_FAILURE;	// Assume failure.
	stack_t stResult;

	iRC = find_name("HUNYH",&stResult);
	if (EXIT_SUCCESS == iRC) {
		dump_stack(&stResult);
		return (EXIT_SUCCESS);
	} else {
		iRC = EXIT_FAILURE;
	}
	return (iRC);
}

int test3() {

	int iRC=EXIT_FAILURE;	// Assume failure.
	stack_t stResult;

	iRC = find_name("SUNNY",&stResult);
	if (EXIT_SUCCESS == iRC) {
		dump_stack(&stResult);
		return (EXIT_SUCCESS);
	} else {
		iRC = EXIT_FAILURE;
	}
	return (iRC);
}

int test4() {

	int iRC=EXIT_FAILURE;	// Assume failure.
	stack_t stResult;

	iRC = find_name("PWWN",&stResult);
	if (EXIT_SUCCESS == iRC) {
		dump_stack(&stResult);
		return (EXIT_SUCCESS);
	} else {
		iRC = EXIT_FAILURE;
	}
	return (iRC);
}


// This tests a value which can not be formed.
int test5() {

	int iRC=EXIT_FAILURE;	// Assume failure.
	stack_t stResult;

	iRC = find_name("JOHN",&stResult);
	if (EXIT_FAILURE == iRC) {
		empty_stack(&stResult);
		iRC = EXIT_SUCCESS;
	} else {
		iRC = EXIT_FAILURE;
	}
	return (iRC);
}
// This tests a value which requires a double to form.
int test6() {

	int iRC=EXIT_FAILURE;	// Assume failure.
	stack_t stResult;

	iRC = find_name("AL",&stResult);
	if (EXIT_SUCCESS == iRC) {
		dump_stack(&stResult);
		return (EXIT_SUCCESS);
	} else {
		iRC = EXIT_FAILURE;
	}
	return (iRC);
}

// This tests a value which requires two doubles to form.
// This is also an edge case
// Exists C,O,N,Ne,Co exist in the tables.
// C,O,N lead to a dead-end, where as Co and C,O do not.
// Two possible outcomes
int test7() {

	int iRC=EXIT_FAILURE;	// Assume failure.
	stack_t stResult;

	iRC = find_name("CONE",&stResult);
	if (EXIT_SUCCESS == iRC) {
		dump_stack(&stResult);
		return (EXIT_SUCCESS);
	} else {
		iRC = EXIT_FAILURE;
	}
	return (iRC);
}

// This tests a value which requires two singles and a double to form.
// O Ti S
int test8() {

	int iRC=EXIT_FAILURE;	// Assume failure.
	stack_t stResult;

	iRC = find_name("OTIS",&stResult);
	if (EXIT_SUCCESS == iRC) {
		dump_stack(&stResult);
		return (EXIT_SUCCESS);
	} else {
		iRC = EXIT_FAILURE;
	}
	return (iRC);
}

// Exists: O, Ti, S, At. Does not exist: A.
// OAtIS
int test9() {

	int iRC=EXIT_FAILURE;	// Assume failure.
	stack_t stResult;

	iRC = find_name("OATIS",&stResult);
	if (EXIT_SUCCESS == iRC) {
		dump_stack(&stResult);
		iRC = EXIT_SUCCESS;
	} else {
		iRC = EXIT_FAILURE;
	}
	return (iRC);
}


// Exists: O, Ti, AS. 
// OTiAs
int test10() {

	int iRC=EXIT_FAILURE;	// Assume failure.
	stack_t stResult;

	iRC = find_name("OTIAS",&stResult);
	if (EXIT_SUCCESS == iRC) {
		dump_stack(&stResult);
		iRC = EXIT_SUCCESS;
	} else {
		iRC = EXIT_FAILURE;
	}
	return (iRC);
}

// GeOFF
int test11() {

	int iRC=EXIT_FAILURE;	// Assume failure.
	stack_t stResult;

	iRC = find_name("GEOFF",&stResult);
	if (EXIT_SUCCESS == iRC) {
		dump_stack(&stResult);
		return (EXIT_SUCCESS);
	} else {
		iRC = EXIT_FAILURE;
	}
	return (iRC);
}

void unit_tests(void) {
	if ( test1() ) {
		fprintf(stderr,"Test 1 failed.\n");
		return;
	}
	printf("---------------\n");
	if ( test2() ) {
		fprintf(stderr,"Test 2 failed.\n");
		return;
	}
	printf("---------------\n");
	if ( test3() ) {
		fprintf(stderr,"Test 3 failed.\n");
		return;
	}
	printf("---------------\n");
	if ( test4() ) {
		fprintf(stderr,"Test 4 failed.\n");
		return;
	}
	printf("---------------\n");
	if ( test5() ) {
		fprintf(stderr,"Test 5 failed.\n");
		return;
	}
	printf("---------------\n");
	if ( test6() ) {
		fprintf(stderr,"Test 6 failed.\n");
		return;
	}
	printf("---------------\n");
	if ( test7() ) {
		fprintf(stderr,"Test 7 failed.\n");
		return;
	}
	printf("---------------\n");
	if ( test8() ) {
		fprintf(stderr,"Test 8 failed.\n");
		return;
	}
	printf("---------------\n");
	if ( test9() ) {
		fprintf(stderr,"Test 9 failed.\n");
		return;
	}
	printf("---------------\n");
	if ( test10() ) {
		fprintf(stderr,"Test 10 failed.\n");
		return;
	}
	printf("---------------\n");
	if ( test11() ) {
		fprintf(stderr,"Test 11 failed.\n");
		return;
	}
	printf("---------------\n");
	printf("All tests passed.\n");

}







