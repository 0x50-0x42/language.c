#include<stdio.h>

#define __MAIN__
#include "def.h"
#undef __MAIN__

int main(void) {

	char s[SIZE];

	puts("enter a string:");

	int len = _getline(s, SIZE);

	fold(s);

	return 0;
}
