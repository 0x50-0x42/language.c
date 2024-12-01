#include<stdio.h>
#include<stdlib.h>

#include "def.h"

struct lines*
addline(struct lines *node, int val) {
	if(!node) {
		node = malloc(sizeof(struct lines));
		node->val = val;
		node->left = node->right = NULL;

		return node;
	}

	else if(val < node->val)
		node->left = addline(node->left, val);
	else if(val > node->val)
		node->right = addline(node->right, val);
	return node;
}
