/*

	write a function setbits(x, p, n, y) that returns x with the n bits that begin at position p set
	to the rightmost n bits of y, leaving the other bits unchanged;

Explanation:

Basically, we need to set the n bits of x to the rightmost n bits of y, that is, replace the n bits of x by the rightmost n bits of y;

*/

#include<stdio.h>

unsigned setbits(unsigned, int, int, unsigned);

int main(void) {

	unsigned x, y, result;

	int p, n;

	x = 100, y = 110;

	n = 4, p = 4;

	result = setbits(x, p, n, y);

	printf("Result: %u\n", result);

	return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {

	return (x >> (p + 1 - n)) | (y & ~(~0 << n));
}

/*
	x = 100
	00000000 00000000 00000000 01100100

	x >> (p + 1 - n)
	00000000 00000000 00000000 00110010

	y = 110
	00000000 00000000 00000000 01101110

	~(~0 << n)
	00000000 00000000 00000000 00001111

	y & ~(0 << n)
	00000000 00000000 00000000 00001110

	x >> (p + 1 - n) | (y & ~(~0 << n))
	00000000 00000000 00000000 00111110
*/
