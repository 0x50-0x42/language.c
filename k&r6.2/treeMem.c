#include<stdio.h>

#include "def.h"

#define MAX 1000

struct tree mem[MAX];
struct tree *byte = mem;

void *talloc() {
	if(byte - mem >= MAX)
		return NULL;
	void *temp = NULL;
	byte++;
	temp = byte - 1;

	return temp;
}

void freeMem() {
	if(byte - mem == 0)
		return;
	while(byte != mem)
	byte--;
}
