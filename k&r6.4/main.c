#include<stdio.h>

#define __MAIN__
#include "def.h"
#undef __MAIN__

int main(void) {

	struct tree*root = NULL, *node = NULL;

	char string[MAX];

	while(getword(string, MAX) != EOF)
		if(*string != '\0')
			root = addnode(root, string);

	puts("Words and their frequencies:");
	mkrevtree(root, &node); // make another tree which contains nodes in a BST sorted according their frequencies

	freeMem();

	treeprint(node);
	return 0;
}
