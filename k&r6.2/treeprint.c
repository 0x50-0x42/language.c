#include<stdio.h>
#include<stdlib.h>

#include "def.h"

void treeprint(struct tree*node) {
	if(!node)
		return;

	treeprint(node->left);
	printf("%s: %d\n", node->word, node->count);
	free(node->word);
	treeprint(node->right);
}
