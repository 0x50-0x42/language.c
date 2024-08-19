#include<stdio.h>

#include "def.h"

int main(void) {

	char string1[SIZE], string2[SIZE];

	printf("enter first string: ");
	_getline(string1, SIZE);

	clearerr(stdin);

	printf("enter second string: ");
	_getline(string2, SIZE);


	int equal; 
	if((equal = _strcmp(string1, string2)) == 0)
		puts("strings are equal!");
	else
		puts("strings are not equal!");

	return 0;
}
