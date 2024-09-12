#include<stdio.h>

#define __RDLN__
#include "def.h"
#undef __RDLN__

void readlines(char **lines, int maxlines) {

	for(int i = 0; i < maxlines; i++) {
		if(lines[i] == NULL) {
			puts("not enough memory, cannot proceed further!!");
			return;
		}

		_getline(lines[i], SIZE); // take user input
		clearerr(stdin);
	}
}
