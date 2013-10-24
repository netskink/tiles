#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"





/* 
 * These tables for representing tiles are simply hard coded.
 * 
 * The idea is that there are three sets of tables.
 * One table for each of the possible sets of tiles,
 * Rather than do a hash table, this is simpler.
 * 
 * (NOTE: The question did not ask for three letter tiles 
 * and just for simplicity I omitted the third table.)
 *
 * Table one is of all the tiles that are one character each.
 * Its a simple 26 char array.  Each index represents a yes/no
 * value if it exists as a tile.  Yes, it could be done as a 
 * bit field, but we will be comparing on a character basis
 * and the table is small so no need to bit encode the values.
 *
 * To index the elements, each value is subtracted from the ASCII
 * value of 'A'.  This means 'A' will be at index 0.  We could make the
 * table 255 values and not have to do the subtract as well.
 *
 */

//                  {A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z};	// Raw Set
//                  {A,1,1,D,E,1,G,1,1,J,1,L,M,1,1,1,Q,R,1,T,1,1,1,X,1,Z};	// Elements present marked with 1
static int tiles1[]={0,1,1,0,0,1,0,1,1,0,1,0,0,1,1,1,0,0,1,0,1,1,1,0,1,0}; // Final table, 1=present, 0=missing
// Possible names from this list[BCHIKNOPSUVWY]: BOB, HUNYH, SUNNY , PWWN

static int tiles2[26][26];

void build_tiles2(void) {
	int i;
	for(i=0;i<26;i++) {
		bzero(&tiles2[i],26);
	}
	// Column 1
	tiles2['L'-'A']['I'-'A'] = 1;
	tiles2['N'-'A']['A'-'A'] = 1;
	tiles2['R'-'A']['B'-'A'] = 1;
	tiles2['C'-'A']['S'-'A'] = 1;
	tiles2['F'-'A']['R'-'A'] = 1;
	// Column 2
	tiles2['B'-'A']['E'-'A'] = 1;
	tiles2['M'-'A']['G'-'A'] = 1;
	tiles2['C'-'A']['A'-'A'] = 1;
	tiles2['S'-'A']['R'-'A'] = 1;
	tiles2['B'-'A']['A'-'A'] = 1;
	tiles2['R'-'A']['A'-'A'] = 1;
	// Column 3
	tiles2['S'-'A']['C'-'A'] = 1;
	tiles2['L'-'A']['U'-'A'] = 1;
	tiles2['L'-'A']['R'-'A'] = 1;
	// Column 4
	tiles2['T'-'A']['I'-'A'] = 1;
	tiles2['Z'-'A']['R'-'A'] = 1;
	tiles2['H'-'A']['F'-'A'] = 1;
	tiles2['R'-'A']['F'-'A'] = 1;
	// Column 5
	tiles2['N'-'A']['B'-'A'] = 1;
	tiles2['T'-'A']['A'-'A'] = 1;
	tiles2['D'-'A']['B'-'A'] = 1;
	// Column 6
	tiles2['C'-'A']['R'-'A'] = 1;
	tiles2['M'-'A']['O'-'A'] = 1;
	tiles2['S'-'A']['G'-'A'] = 1;
	// Column 7
	tiles2['M'-'A']['N'-'A'] = 1;
	tiles2['T'-'A']['C'-'A'] = 1;
	tiles2['R'-'A']['E'-'A'] = 1;
	tiles2['B'-'A']['H'-'A'] = 1;
	// Column 8
	tiles2['F'-'A']['E'-'A'] = 1;
	tiles2['R'-'A']['U'-'A'] = 1;
	tiles2['O'-'A']['S'-'A'] = 1;
	tiles2['H'-'A']['S'-'A'] = 1;
	// Column 9
	tiles2['C'-'A']['O'-'A'] = 1;
	tiles2['R'-'A']['H'-'A'] = 1;
	tiles2['I'-'A']['R'-'A'] = 1;
	tiles2['M'-'A']['T'-'A'] = 1;
	// Column 10
	tiles2['N'-'A']['I'-'A'] = 1;
	tiles2['P'-'A']['D'-'A'] = 1;
	tiles2['P'-'A']['T'-'A'] = 1;
	tiles2['D'-'A']['S'-'A'] = 1;
	// Column 11
	tiles2['C'-'A']['U'-'A'] = 1;
	tiles2['A'-'A']['G'-'A'] = 1;
	tiles2['A'-'A']['U'-'A'] = 1;
	tiles2['R'-'A']['G'-'A'] = 1;
	// Column 12
	tiles2['Z'-'A']['N'-'A'] = 1;
	tiles2['C'-'A']['D'-'A'] = 1;
	tiles2['H'-'A']['G'-'A'] = 1;
	tiles2['C'-'A']['N'-'A'] = 1;
	// Column 13
	tiles2['A'-'A']['L'-'A'] = 1;
	tiles2['G'-'A']['A'-'A'] = 1;
	tiles2['I'-'A']['N'-'A'] = 1;
	tiles2['T'-'A']['L'-'A'] = 1;
	// Column 14
	tiles2['S'-'A']['I'-'A'] = 1;
	tiles2['G'-'A']['E'-'A'] = 1;
	tiles2['S'-'A']['N'-'A'] = 1;
	tiles2['P'-'A']['B'-'A'] = 1;
	tiles2['F'-'A']['L'-'A'] = 1;
	// Column 15
	tiles2['A'-'A']['S'-'A'] = 1;
	tiles2['S'-'A']['B'-'A'] = 1;
	tiles2['B'-'A']['I'-'A'] = 1;
	// Column 16
	tiles2['S'-'A']['S'-'A'] = 1;
	tiles2['T'-'A']['E'-'A'] = 1;
	tiles2['P'-'A']['E'-'A'] = 1;
	tiles2['L'-'A']['O'-'A'] = 1;
	// Column 17
	tiles2['C'-'A']['L'-'A'] = 1;
	tiles2['B'-'A']['R'-'A'] = 1;
	tiles2['A'-'A']['T'-'A'] = 1;
	// Column 18
	tiles2['H'-'A']['E'-'A'] = 1;
	tiles2['N'-'A']['E'-'A'] = 1;
	tiles2['A'-'A']['R'-'A'] = 1;
	tiles2['K'-'A']['R'-'A'] = 1;
	tiles2['X'-'A']['E'-'A'] = 1;
	tiles2['R'-'A']['N'-'A'] = 1;
	// lanthanoids
	tiles2['L'-'A']['A'-'A'] = 1;
	tiles2['C'-'A']['E'-'A'] = 1;
	tiles2['P'-'A']['R'-'A'] = 1;
	tiles2['N'-'A']['D'-'A'] = 1;
	tiles2['P'-'A']['M'-'A'] = 1;
	tiles2['S'-'A']['M'-'A'] = 1;
	tiles2['E'-'A']['U'-'A'] = 1;
	tiles2['G'-'A']['D'-'A'] = 1;
	tiles2['T'-'A']['B'-'A'] = 1;
	tiles2['D'-'A']['Y'-'A'] = 1;
	tiles2['H'-'A']['O'-'A'] = 1;
	tiles2['E'-'A']['R'-'A'] = 1;
	tiles2['T'-'A']['M'-'A'] = 1;
	tiles2['Y'-'A']['B'-'A'] = 1;
	// lanthanoids
	tiles2['A'-'A']['C'-'A'] = 1;
	tiles2['T'-'A']['H'-'A'] = 1;
	tiles2['P'-'A']['A'-'A'] = 1;
	tiles2['N'-'A']['P'-'A'] = 1;
	tiles2['P'-'A']['U'-'A'] = 1;
	tiles2['A'-'A']['M'-'A'] = 1;
	tiles2['C'-'A']['M'-'A'] = 1;
	tiles2['B'-'A']['K'-'A'] = 1;
	tiles2['C'-'A']['F'-'A'] = 1;
	tiles2['E'-'A']['S'-'A'] = 1;
	tiles2['F'-'A']['M'-'A'] = 1;
	tiles2['M'-'A']['D'-'A'] = 1;
	tiles2['N'-'A']['O'-'A'] = 1;
}

int exists1(char chLetter) {
	return tiles1[chLetter-'A'];
}

// Could have used a pointer and then picked two chars
// For simplicity just pass two individual chars
int exists2(char chLetter1,char chLetter2) {
	return tiles2[chLetter1-'A'][chLetter2-'A'];
}




