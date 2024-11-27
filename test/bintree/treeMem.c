#include<stdio.h>

#define MAX 1000

#include "def.h"

static struct tree mem[MAX];

static struct tree *byte = mem;

void *talloc() {
	if(byte - mem == MAX - 1)
		return NULL;

	void *temp = NULL;

	byte++;
	temp = byte - 1;

	return temp;
}

void freeTree() {
	if(byte - mem == 0)
		return;
	while(byte != mem)
		byte--;
}
