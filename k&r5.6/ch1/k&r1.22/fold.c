#include<stdio.h>

#define __FLD__
#include "def.h"
#undef __FLD__

void fold(char *s) {
	int colNo = 0;

	while(*s) {
		if(*s == '\n')
			colNo = 0;

		if(*s == ' ' && colNo == NCOL) {
			printf("\n");
			colNo = 0;
		}

		else if(*s != ' ' && colNo == NCOL) {
			printf("\n");
			printf("%c", *s);
			colNo = 0;
		}

		else
			printf("%c", *s);

		s++;
		colNo++;
	}

	printf("\n");
}
