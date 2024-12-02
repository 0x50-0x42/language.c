#include<stdio.h>

#define __ADDNODE__
#include "def.h"
#undef __ADDNODE__

struct tree *addnode(struct tree*node, int val) {
	if(!node) {
		node = talloc();
		node->val = val;
		node->right = node->left = NULL;

		return node;
	}

	else if(val < node->val)
		node->left = addnode(node->left, val);
	else if(val > node->val)
		node->right = addnode(node->right, val);
	return node;
}
