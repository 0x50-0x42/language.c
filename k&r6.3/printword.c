#include<stdio.h>
#include<stdlib.h>

#define __PRINTNODE__
#include "def.h"
#undef __PRINTNODE__

void printword(struct cref*node) {
	if(!node)
		return;
	printword(node->left);
	printf("%s: ", node->word);
	printline(node->line);
	printf("\n");
	printword(node->right);
}
