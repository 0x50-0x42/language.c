/*
	in a 2's-complement number system, x &= (x - 1) deletes the rightmost 1-bit in x;
	explain why;
	use this observation to write a faster version of bitcount;
*/

#include<stdio.h>

int bitcount_fast(unsigned);

int main(void) {

	int x = 123;

	printf("%d has %d 1s\n", x, bitcount_fast(x));

	return 0;
}

int bitcount_fast(unsigned x) {
	int bits = 0;
	while(x != 0) {
		bits++;
		x &= (x - 1);
	}

	return bits;
}

/*
	x = 19
	~~~~~~
	00010011

	x - 1
	~~~~~
	00010010

	x & (x - 1)
	~~~~~~~~~~~
	00010010 -> 18

	x = 18
	~~~~~~
	00010010

	x - 1
	~~~~~
	00010001

	x & (x - 1)
	~~~~~~~~~~~
	00010000 -> 16

	x = 16
	~~~~~~
	00010000

	x - 1
	~~~~~
	00001111

	x & (x - 1)
	~~~~~~~~~~~
	00000000
*/
