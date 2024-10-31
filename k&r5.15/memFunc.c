#include<stdio.h>
#include<string.h>

#define MAXMEM 10000

char mem[MAXMEM];
char *byte = mem;

char* alloc(unsigned reqMem) {
	if(reqMem >= MAXMEM)
		return NULL;
	if(MAXMEM - (byte - mem) <= reqMem)
		return NULL;
	char *temp;

	byte += reqMem;

	temp = byte - reqMem;

	byte++;

	return temp;
}

void freeMem(void**vec) {
	if(byte - mem == 0) {
		*vec = NULL;
		return;
	}

	byte--;
	byte -= strlen((char*)*vec);

	*vec = NULL;
}
