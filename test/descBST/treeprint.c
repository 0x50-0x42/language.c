#include<stdio.h>

#include "def.h"

void treeprint(struct tree*node) {
	if(!node)
		return;
	treeprint(node->left);
	printf("%d ", node->val);
	treeprint(node->right);
}
