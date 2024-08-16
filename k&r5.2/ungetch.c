#include<stdio.h>

#define _REMEM_
#include "def.h"
#undef _REMEM_

extern int buf[];
extern int bufp;

void ungetch(int val) {
	if(bufp >= BUFSZ - 1) {
		puts("too many characters!");
		return;
	}

	buf[++bufp] = val;
}
