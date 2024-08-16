#include<stdio.h>

#define _REMEM_
#include "def.h"
#undef _REMEM_

int buf[BUFSZ];
int bufp = -1;

int getch() {
	return bufp >= 0 ? buf[bufp--] : getchar();
}
