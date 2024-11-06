#include<stdio.h>
#include<string.h>

#define MAXMEM 10000

char mem[MAXMEM];

char *byte = mem;

void *alloc(unsigned reqMem) {
	if(reqMem >= MAXMEM)
		return NULL;
	if(MAXMEM - (byte - mem) <= reqMem)
		return NULL;

	void *temp;

	byte += reqMem;

	temp = byte - reqMem;

	byte++;

	return temp;
}
