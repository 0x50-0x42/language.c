#include<stdio.h>
#include "def.h"

int main(void) {

	char s[SIZE];

	printf("enter a string: ");

	_getline(s, SIZE);

	printf("Length of %s is: %d\n", s, _strlen(s));

	return 0;
}
