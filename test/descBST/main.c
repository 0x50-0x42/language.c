#include<stdio.h>

#define __MAIN__
#include "def.h"
#undef __MAIN__

int main(void) {

	struct tree* root = NULL;

	int val;

	while((val = getint()) != EOF)
		if(val != 0)
			root = addnode(root, val);
	treeprint(root);
	printf("\n");

	freeMem();
	return 0;
}
