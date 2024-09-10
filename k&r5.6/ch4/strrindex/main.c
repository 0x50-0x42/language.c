#include<stdio.h>

#include "def.h"

int main(void) {

	char *s = "C programming. Programming in C";

	char *found = strrindex(s, "gram"); // return the rightmost occurence of "amm" in s

	if(found == NULL)
		puts("can't find string!");
	else
		printf("Found in: %s\n", found);

	return 0;
}
