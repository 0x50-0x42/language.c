#include<stdio.h>

#define MAXSZ 10000

char mem[MAXSZ];

char *allocedMem = mem;

char *alloc(unsigned reqMem) {

	if(reqMem >= MAXSZ)
		return NULL;

	if(MAXSZ - (allocedMem - mem) <= reqMem)
		return NULL;

	allocedMem += reqMem;
	char *temp = allocedMem - reqMem;
	allocedMem++;

	return temp;
}
