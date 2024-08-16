#include<stdio.h>

#define DEF
#include "def.h"
#undef DEF

int main(void) {

	int v[SIZE], n;

	printf("enter numbers: ");

	for(n = 0; n < SIZE && (getint(&v[n])) != EOF; n++)
		;

	for(int i = 0; i < n; i++)
		printf("%d ", v[i]);

	printf("\n");

	return 0;
}
