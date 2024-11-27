#include<stdio.h>

#include "def.h"

void displayTree(struct tree *node) {
	if(!node)
		return;

	printf("%d ", node->val);

	displayTree(node->left);
	displayTree(node->right);
}
