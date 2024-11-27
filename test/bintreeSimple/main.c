// implementing a simple binary tree
/* enter number input, duplicate numbers won't be inserted */

#include<stdio.h>
#include<stdlib.h>

#define __MAIN__
#include "def.h"
#undef __MAIN__

struct tree *root = NULL;

int main(void) {

	int val;

	while((val = getint()) != EOF)
		root = addtree(root, val);

	puts("here's the tree:");

	displayTree(root);

	return 0;
}
