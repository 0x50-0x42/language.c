#include<stdio.h>
#include<string.h>

#define __ADDNODE__
#include "def.h"
#undef __ADDNODE__

extern int lineNum;

struct cref*
addword(struct cref*node, char *string) {
	if(!node) {
		node = talloc();
		node->word = strdup(string);
		node->line = NULL;
		node->line = addline(node->line, lineNum);
		node->left = node->right = NULL;

		return node;
	}

	else if(strcmp(string, node->word) < 0)
		node->left = addword(node->left, string);
	else if(strcmp(string, node->word) > 0)
		node->right = addword(node->right, string);
	else
		node->line = addline(node->line, lineNum);

	return node;
}
