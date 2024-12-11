#include<stdio.h>

#define __CONST__
#include "def.h"
#undef __CONST__

unsigned hash(char *s) {
	unsigned hashval = 0;
	while(*s != '\0') {
		hashval = *s + 31 * hashval;
		s++;
	}

	return hashval % HASHSIZE;
}
