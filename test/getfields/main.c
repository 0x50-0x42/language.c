#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "def.h"

int main(void) {

	char string[MAXCHAR];

	int len = _getline(string, MAXCHAR);

	if(len == EOF) {
		puts("No string input given!");
		return 1;
	}

	int field = 3;

	char *fieldStr = getField(string, field);

	if(fieldStr != NULL)
		printf("String at field %d: %s\n", field, fieldStr);
	else
		printf("No string at field %d\n", field);

	return 0;
}
