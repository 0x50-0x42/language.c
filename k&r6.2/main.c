#include<stdio.h>
#include<ctype.h>

#include "def.h"

int main(int argc, char **argv) {

	struct words *root = NULL;

	int match = 6; // number of matching characters by default

	if(argc == 1)
		argv++;

	if(argc > 1) {
		if(isdigit(**argv))
			match = atoi(*argv);
	}

	while(getword(string, MAXCHAR) != EOF)
		root = addtree(root, string, match);

	return 0;
}
