/*
	in a 2's-complement number system, x &= (x - 1) deletes the rightmost 1-bit in x;
	explain why;
	use this observation to write a faster version of bitcount;

int bitcount(unsigned x) {

	int set;

	for(set = 0; x != 0; x >>= 1)
		if(x & 0x01)
			set++;
	return set;
}
*/

#include<stdio.h>

int bitcount_fast(unsigned);

int main(void) {
	return 0;
}

int bitcount_fast(unsigned x) {
	return 0;
}

/*
	x = 19
	~~~~~~
	00010011

	x - 1 = 18
	~~~~~~~~~~
	00010010

	x &= (x - 1)
	~~~~~~~~~~~~
	00010010(rightmost-bit is deleted)

	x = -13
	~~~~~~~

	13 = 00001101

	invert bits
	11110010

	add 1

	-13 = 11110011

	x - 1 = -13 - 1 = -14
	~~~~~~~~~~~~~~~~~~~~~

	14 = 00001110

	invert bits
	11110001

	add 1

	-14 = 11110010

	x &= (x - 1)
	~~~~~~~~~~~~
	11110010

	x = 19
	~~~~~~
	00010011

	x & (x - 1)
	~~~~~~~~~~~
	00010010

	x = 18
	~~~~~~
	00010010

	x & (x - 1)
	~~~~~~~~~~~
	00010001

	x = 17
	~~~~~~
	00010001

	x & (x - 1)
	~~~~~~~~~~~
	00010000

	incomplete
*/
