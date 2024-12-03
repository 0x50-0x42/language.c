#include<stdio.h>
#include<stdlib.h>

#include "def.h"

void treeprint(struct tree*node) {
	if(!node)
		return;

	treeprint(node->right);
	printf("%s: %d\n", node->word, node->count);
	treeprint(node->left);
	free(node->word);
	free(node);
}
