#include<stdio.h>

#define __DTAB__

#include "def.h"

#undef __DTAB__

void detab(char *s) {
	while(*s != '\0') {
		if(*s == '\t')
			for(int i = 0; i < TABLEN; i++)
				printf(" ");
		else
			printf("%c", *s);
		s++;
	}

	printf("\n");
}
