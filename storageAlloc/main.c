/*
   Simulating malloc(): rudimentary(from K&R2)
 */

#include<stdio.h>

#include "def.h"

int main(void) {
	int *v;

	v = alloc(5); // requesting 5 consecutive bytes

	if(v == 0) {
		puts("cannot proceed!");
		return -1;
	}

	puts("enter values:");

	for(int i = 0; i < 5; i++)
		scanf("%d", v + i);

	puts("elements are:");

	for(int i = 0; i < 5; i++)
		printf("%d ", v[i]);

	afree(v);

	printf("\n");

	return 0;
}
