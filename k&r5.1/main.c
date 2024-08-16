/*
   K&R2 exercise 5.1
 */

#include<stdio.h>
#include<limits.h>

#define DEF
#include "def.h"
#undef DEF

int main(void) {

	int v[SIZE];
	
	printf("enter some numbers: ");

	int n = 0, val;

	while(n < SIZE && (val = getint(&v[n])) != EOF) {
		if(val == INT_MAX)
			continue;
		n++;
	}

	puts("the array is: ");

	for(int i = 0; i < n; i++)
		printf("%d ", v[i]);

	printf("\n");

	return 0;
}
