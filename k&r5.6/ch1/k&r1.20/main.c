#include<stdio.h>

#define __MAIN__

#include "def.h"

#undef __MAIN__

int main(void) {

	char s[SIZE];

	printf("enter a string: ");

	int len = _getline(s, SIZE);

	detab(s);

	return 0;
}
