#include<stdio.h>
#include<string.h>

#include "def.h"

int main(void) {

	char string[MAXCHAR];

	int intC = 0, whC = 0, doC = 0, forC = 0, ifC = 0;

	// getword() takes one word at a time as input from the stdin
	while(getword(string, MAXCHAR) != EOF) {
		if(strcmp(string, "int") == 0)
			intC++;
		if(strcmp(string, "while") == 0)
			whC++;
		if(strcmp(string, "do") == 0)
			doC++;
		if(strcmp(string, "for") == 0)
			forC++;
		if(strcmp(string, "if") == 0)
			ifC++;
	}

	printf("int: %d\nwhile: %d\ndo: %d\nfor: %d\nif: %d\n", intC, whC, doC, forC, ifC);

	return 0;
}
