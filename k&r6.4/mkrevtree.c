#include<stdio.h>

#define __REVTREE__
#include "def.h"
#undef __REVTREE__

void mkrevtree(struct tree*node1, struct tree**node2) {
	if(!node1)
		return;
	mkrevtree(node1->left, node2);
	revtree(node1, node2);
	mkrevtree(node1->right, node2);
}
