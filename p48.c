/*
	write a function invert(x, p, n) that returns x with the n bits that begin at position p inverted, leaving others unchanged.
*/

#include<stdio.h>

unsigned invert(unsigned, int, int);

int main(void) {

	unsigned x, result;

	x = 170;

	int p, n;

	p = 4, n = 3;

	result = invert(x, p, n);

	printf("Result: %u\n", result);
	return 0;
}

unsigned invert(unsigned x, int p, int n) {
	return x ^ ((~(~0 << n)) << (p + 1 - n));
}

/*
	p = 4, n = 3

	x = 204                       v v
	00000000 00000000 00000000 11001100

	~0 << n
	11111111 11111111 11111111 11111000

	~(~0 << n)
	00000000 00000000 00000000 00000111

	~(~0 << n) << (p + 1 - n)     v v
	00000000 00000000 00000000 00011100

	x ^ (~(~0 << n) << (p + 1 - n))
	00000000 00000000 00000000 11010000
	                              ^ ^
*/
