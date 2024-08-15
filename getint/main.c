#include<stdio.h>

#define DEF
#include "def.h"
#undef DEF

int main(void) {

	int v[SIZE]; // an array that will store integers

	int n;

	char str[SIZE];

	printf("enter numeric string: ");

	for(n = 0; n < SIZE && (getint(&v[n])) != EOF; n++)
		;

	for(int i = 0; i < n; i++)
		printf("%d ", v[i]);
	printf("\n");

	return 0;
}
