#include<stdio.h>

#include "def.h"

int main(void) {
	char *s = "C programming";

	char *found = strindex(s, "amm");

	if(found == NULL)
		puts("can't find string!");
	else
		printf("Found in: %s\n", found);

	return 0;
}
