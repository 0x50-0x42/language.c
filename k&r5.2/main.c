/*
   K&R2 exercise 5.2

   getfloat() need not return any double type as it directly accesses the array elements via their addresses
   it can return int type
 */
#include<stdio.h>
#include<limits.h>

#define DEF
#include "def.h"
#undef DEF

int main(void) {

	double v[SIZE];

	int n = 0, val;
	
	puts("enter some numbers:");

	while(n < SIZE && (val = getfloat(&v[n])) != EOF) {
		if(val == INT_MAX)
			continue;
		n++;
	}

	puts("the array: ");
	for(int i = 0; i < n; i++)
		printf("%lf ", v[i]);

	printf("\n");

	return 0;
}
