#define MAX 1000

#include<stdio.h>
#include<stdlib.h>

#include "def.h"

struct cref mem[MAX];
struct cref *byte = mem;

void*talloc() {
	if(byte - mem > MAX - 1)
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

void freeline(struct lines*node) {
	if(!node)
		return;
	freeline(node->left);
	freeline(node->right);
	free(node);
}
