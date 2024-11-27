#include<stdio.h>

#include "def.h"

void showTree(struct tree *node) {

	if(!node)
		return;

	printf("%s: %d\n", node->word, node->count);

	showTree(node->left);
	showTree(node->right);
}
