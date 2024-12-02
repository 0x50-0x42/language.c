#include<stdio.h>

#include "def.h"

void treeprint(struct tree*node) {
	if(!node)
		return;
	treeprint(node->right);
	printf("%d ", node->val);
	treeprint(node->left);
}
