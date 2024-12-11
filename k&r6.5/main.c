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
		if(strcmp(string, "#define") == 0) { // define preprocessor
			getword(s, MAXCHAR);
			getword(t, MAXCHAR);

			install(s, t); // store the name and its definition in the table
		}

		else if(strcmp(string, "#undef") == 0) { // undef
			getword(s, MAXCHAR);
			getword(t, MAXCHAR);

			_undef(s); // remove the name and its definition from the table
		}
	}

	display();

	freeMem();

	return 0;
}
