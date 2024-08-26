#include<stdio.h>

#define __RMCOM__
#include "def.h"
#define __RMCOM__

void rmCom(char *s) {

	while(*s) {
		multCom(s);
		singleCom(s);
		printf("%c", *s);

		s++;
	}

	printf("\n");
}
