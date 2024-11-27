#include<stdio.h>

#define __ADDNODE__
#include "def.h"
#undef __ADDNODE__

struct tree*
addtree(struct tree *node, int val) {
	if(node == NULL) {
		node = talloc(1);
		node->val = val;
		node->right=node->left = NULL;

		return node;
	}

	else if(val < node->val)
		node->left = addtree(node->left, val);// move left
	else if(val > node->val)
		node->right = addtree(node->right, val);// move right
	else
		puts("Duplicate value!");

	return node;
}
