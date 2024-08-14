/*
   K&R2 exercise 4.13
*/

#include<stdio.h>
#include<stdlib.h>
#include "def.h"

int main(void) {

	char s[MAXLEN];

	int len;

	printf("enter a string: ");

	len = _getline(s, MAXLEN);

	printf("string before reversing: %s\n", s);

	reverse(s, 0);

	printf("string after reversing: %s\n", s);

	return 0;
}
