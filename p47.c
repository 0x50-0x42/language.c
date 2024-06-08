/*
	write a function setbits(x, p, n, y) that returns x with the n bits that begin at position p set
	to the rightmost n bits of y, leaving the other bits unchanged
*/

#include<stdio.h>

unsigned setbits(unsigned, int, int, unsigned);

int main(void) {

	unsigned x, y, result;

	int p, n;

	result = setbits(x, p, n, y);

	printf("Result: %u\n", result);

	return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
	return 0;
}
