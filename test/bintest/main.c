#include<stdio.h>

#define __MAIN__
#include "def.h"
#undef __MAIN__

int main(void) {

	struct tree *root = NULL;

	char string[MAXCHAR];

	while(getword(string, MAXCHAR) != EOF)
		root = addtree(root, string);

	treeprint(root);

	freeMem();
	return 0;
}
