#include<stdio.h>
#include<string.h>

#define __MAIN__
#define __CONST__
#include "def.h"
#undef __CONST__
#undef __MAIN__

struct nlist *hashtab[HASHSIZE];
unsigned hashval;

int main(void) {

	char string[MAXCHAR], s[MAXCHAR], t[MAXCHAR];

	while(getword(string, MAXCHAR) != EOF) {
		if(strcmp(string, "#define") == 0) {
			getword(s, MAXCHAR);
			getword(t, MAXCHAR);
			install(s, t); // install the name and the replacement text in the table
		}

	}

	displaytable();

	freeMem();

	return 0;
}
