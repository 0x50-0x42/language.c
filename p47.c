/*

	write a function setbits(x, p, n, y) that returns x with the n bits that begin at position p set
	to the rightmost n bits of y, leaving the other bits unchanged;

Explanation:

Basically, we need to set the n bits of x to the rightmost n bits of y, that is, replace the n bits of x by the rightmost n bits of y;

BUT THE REST OF THE BITS OF x MUST REMAIN UNCHANGED!!

*/

#include<stdio.h>

unsigned setbits(unsigned, int, int, unsigned);

int main(void) {

	unsigned x, y, result;

	int p, n;

	x = 100, y = 110;

	n = 3, p = 4;

	result = setbits(x, p, n, y);

	printf("Result: %u\n", result);

	return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
	return (x & (~((~(~0 << n)) << (p + 1 - n)))) | ((y & (~(~0 << n))) << (p + 1 - n));
}

/*
	n = 3, p = 4
	~~~~~~~~~~~~
	
	x = 170                       v v
	00000000 00000000 00000000 10101010

	y = 204                         v v
	00000000 00000000 00000000 11001100

	Create the mask for AND-ing with y
	~0 << n
	11111111 11111111 11111111 11111000

	~(~0 << n)
	00000000 00000000 00000000 00000111

	y & ~(~0 << n)
	00000000 00000000 00000000 00000100

	Left-shift y by (p + 1 - n) bits for target bits of x
	(y & ~(~0 << n)) << (p + 1 - n)
	00000000 00000000 00000000 00010000
	                              ^ ^

	Left-shift mask by (p + 1 - n)
	(~(~0 << n)) << (p + 1 - n)
	00000000 00000000 00000000 00011100

	After left-shifting mask, invert its bits
	~((~(~0 << n)) << (p + 1 - n))
	11111111 11111111 11111111 11100011
	                              ^ ^

	AND x with inverted mask so that its target bits are unset
	x & ~((~(~0 << n)) << (p + 1 - n))
	00000000 00000000 00000000 10100010
	                              ^ ^

	OR x with y so that its unset target bits are replaced by the bits of y
	(x & ~((~(~0 << n)) << (p + 1 - n))) | ((y & ~(~0 << n)) << (p + 1 - n))
	00000000 00000000 00000000 10110010
	                              ^ ^
*/
