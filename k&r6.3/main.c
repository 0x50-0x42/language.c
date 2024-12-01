#include<stdio.h>

#define __MAIN__
#include "def.h"
#undef __MAIN__

int lineNum = 1; // by default, line number 1

#define LSTSZ (sizeof list / sizeof(list[0]))

int main(void) {

	struct cref *root = NULL;

	char string[MAXCHAR];

	while(getword(string, MAXCHAR) != EOF)
		if(*string != '\0' && (binsearch(string, list, LSTSZ)) == -1)
			root = addword(root, string);

	puts("Line numbers where the words occur:");

	printword(root);

	freeline(root->line);

	freeMem();

	return 0;
}
