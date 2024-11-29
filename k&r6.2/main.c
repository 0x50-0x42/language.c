#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define __MAIN__
#include "def.h"
#undef __MAIN__

int main(int argc, char **argv) {

	struct tree *root = NULL;

	int match = 6; // number of matching characters by default

	if(argc >= 1)
		argv++;

	if(argc > 1) {
		if(isdigit(**argv))
			match = atoi(*argv);
	}

	printf("%d\n", match);

	char string[MAXCHAR];

	while(getword(string, MAXCHAR) != EOF)
		if(*string != '\0')
			root = addtree(root, string, match);

	treeprint(root);

	freeMem();

	return 0;
}
