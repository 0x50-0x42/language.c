/*
   swap() using pointers
 */

#include<stdio.h>

void swap(int*, int*);

int main(void) {
	int a = 10, b = 20;

	printf("a = %d, b = %d\n", a, b);

	swap(&a, &b);

	printf("a = %d, b = %d\n", a, b);

	return 0;
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
