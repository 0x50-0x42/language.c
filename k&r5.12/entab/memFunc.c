#include<stdio.h>

#define MAX 10000

char mem[MAX];

char *body = mem;

char *alloc(unsigned reqMem) {
	if(reqMem >= MAX)
		return NULL;

	if(MAX - (body - mem) > reqMem) {

		body += reqMem;

		return (body - reqMem);
	}

	else
		return NULL;
}

void freeMem(char**storage) {
	*storage = NULL;
	body = mem;
}
