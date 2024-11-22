#include<stdio.h>
#include<string.h>

#define MAXMEM 10000

char mem[MAXMEM];
static char *byte = mem;

void *alloc(unsigned reqMem) {

	if(reqMem >= MAXMEM)
		return NULL;
	if(MAXMEM - (byte - mem) <= reqMem)
		return NULL;

	void *temp = NULL;

	byte += reqMem;
	temp = byte - reqMem;
	byte++;

	return temp;
}

void freeMem(void*vec) {

	if(!strlen(vec))
		return;

	if(byte - mem == 0)
		return;

	byte--;
	byte -= strlen(vec);
}
