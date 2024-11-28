#include<stdio.h>

#include "def.h"

// printing in alphabetical order
void treeprint(struct tree*node) {

	if(!node)
		return;
	treeprint(node->left);
	printf("%s\n", node->string);
	treeprint(node->right);
}
