#include<stdio.h>

#include "def.h"

int _write(char *string, unsigned int length) {
	char *base = string;

	while(*string != '\0') {
		printf("%c", *string);
		string++;
	}

	return (string - base);
}
