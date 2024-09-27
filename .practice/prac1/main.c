// count the number of words in a given text

#include<stdio.h>

#define __MAIN__
#include "def.h"
#undef __MAIN__

int main(void) {

	char s[SIZE];

	puts("enter some text:");

	int len = _getline(s, SIZE);

	int words = wc(s);

	printf("number of words in the given text: %d\n", words);

	return 0;
}
