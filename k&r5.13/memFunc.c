#include<stdio.h>

#define MAXSZ 10000

char mem[MAXSZ];

char *body = mem;

char *alloc(unsigned reqMem) {

	if(reqMem > MAXSZ)
		return NULL;

	if(MAXSZ - (body - mem) > reqMem) {

		body += reqMem;

		char *sentMem = body;
		body++;

		return (sentMem - reqMem);
	}

	return NULL;
}

void freeMem() {
	body = mem;
}
