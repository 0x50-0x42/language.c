#include<stdio.h>

#include "def.h"

void printline(struct lines*node) {
	if(!node)
		return;
	printline(node->left);
	printf("%d ", node->val);
	printline(node->right);
}
