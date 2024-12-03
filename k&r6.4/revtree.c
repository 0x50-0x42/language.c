#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "def.h"

void revtree(struct tree*node1, struct tree**node) {
	if(!(*node)) {
		*node = malloc(sizeof(struct tree));
		(*node)->word = strdup(node1->word);
		(*node)->count = node1->count;
		(*node)->left = (*node)->right = NULL;

		return;
	}

	else if(node1->count <= (*node)->count)
		revtree(node1, &(*node)->left);
	else if(node1->count > (*node)->count)
		revtree(node1, &(*node)->right);
}
