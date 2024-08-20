/*
   K&R2 exercise 5.4
 */

#include<stdio.h>
#include "def.h"

int main(void) {

	char s[SIZE], t[SIZE];

	printf("enter first string: ");
	_getline(s, SIZE);

	clearerr(stdin);

	printf("enter second string: ");
	_getline(t, SIZE);

	if(strend(s, t))
		printf("%s occurs at the end of %s\n", t, s);
	else
		printf("%s doesn't occur at the end of %s\n", t, s);

	return 0;
}
