#include<stdio.h>

#include "def.h"

#define MAX 1000

static struct tree mem[MAX];
static struct tree *byte = mem;

void *talloc() {
	if(byte - mem >= MAX)
		return NULL;

	void *temp = NULL;

	byte++;

	temp = byte - 1;

	return temp;
}

void freeMem() {
	if(byte - mem == 0) {
		puts("Memory already cleared!");
		return;
	}

	while(byte != mem)
		byte--;
}
