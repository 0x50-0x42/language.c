#include<stdio.h>
#include<string.h>

#define __ADDNODE__
#include "def.h"
#undef __ADDNODE__

struct tree*
addtree(struct tree *node, char *string) {

	int cond;
	if(!node) {
		node = talloc();
		node->word = strdup(string);
		node->count = 1;
		node->left = node->right = NULL;

		return node;
	}

	else if((cond = strcmp(string, node->word)) < 0)
		node->left = addtree(node->left, string);
	else if(cond > 0)
		node->right = addtree(node->right, string);
	else
		node->count++;

	return node;
}
