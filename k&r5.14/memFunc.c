#include<stdio.h>
#include<string.h>

#define MAX 10000

char mem[MAX];

char *byte = mem;

char *alloc(unsigned reqMem) {

	if(reqMem >= MAX)
		return NULL;

	if(MAX - (byte - mem) <= reqMem)
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
