#include<stdio.h>
#include<string.h>

#define __ADDNODE__
#include "def.h"
#undef __ADDNODE__

struct tree*
addtree(struct tree *node, char *string, int match) {
	if(!node) {
		node = talloc();
		node->word = strdup(string);
		node->count = 1;
		node->left = node->right = NULL;
		return node;
	}

	// if the first `match' characters are the same, then
	else if(strncmp(node->word, string, match) == 0) {
		// store the string lexicographically
		if(strcmp(string, node->word) < 0)
			node->left = addtree(node->left, string, match);

		else if(strcmp(string, node->word) > 0)
			node->right = addtree(node->right, string, match);
		else
			node->count++;
	}

	else {
		// store the string lexicographically
		if(strcmp(string, node->word) < 0)
			node->left = addtree(node->left, string, match);

		else if(strcmp(string, node->word) > 0)
			node->right = addtree(node->right, string, match);
	}

	return node;
}
