#include<stdio.h>

int rightrot(unsigned, int);

int main(void) {

	int x = 19, result;

	int n = 2;

	result = rightrot(x, n);

	printf("Result: %d\n", result);

	return 0;
}

int rightrot(unsigned x, int n) {
	int d = 32; // when we consider a 32-bit number, then we don't need to create the mask
	return (x >> n) | (x << (d - n));
}
