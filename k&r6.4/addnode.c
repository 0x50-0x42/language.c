#include<stdio.h>
#include<string.h>

#define __ADDNODE__
#include "def.h"
#undef __ADDNODE__

struct tree*
addnode(struct tree*node, char *string) {
	if(!node) {
		node = talloc();
		node->word = strdup(string);
		node->count = 1;
		node->left = node->right = NULL;

		return node;
	}

	else if(strcmp(string, node->word) < 0)
		node->left = addnode(node->left, string);
	else if(strcmp(string, node->word) > 0)
		node->right = addnode(node->right, string);
	else
		node->count++;

	return node;
}
