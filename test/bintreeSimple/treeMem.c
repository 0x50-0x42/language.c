#include<stdio.h>

#define MAX 1000

#include "def.h"

struct tree mem[MAX];
struct tree *byte = mem;

void *talloc(int reqMem) {

	if(reqMem >= MAX)
		return NULL;
	if(MAX - (byte - mem) <= reqMem)
		return NULL;

	void *temp = NULL;

	byte += reqMem;
	temp = byte - reqMem;

	return temp;
}
