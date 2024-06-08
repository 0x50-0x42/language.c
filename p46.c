#include<stdio.h>

unsigned getBits(unsigned, int, int);

int main(void) {

	unsigned x, result;

	int p = 4, n = 3;

	x = 100;

	result = getBits(x, p, n); // returns right shifted n-bit field of x that begins at position p
	printf("%u\n", result);
	return 0;
}

unsigned getBits(unsigned x, int p, int n) {
	return (x >> (p + 1 - n)) & ~(~0 << n);
}

/*
	explaining for p = 4, n = 3 and x = 100

	before beginning, a very important note: we use bitwise AND for turning off bits

	we need the bits in the bit-positions 4, 3 and 2

	binary equivalent of 100 is: 00000000 00000000 00000000 01100100

	so, the bits in the bit positions 4, 3 and 2 are: 001, so we need to return these bits;
	so for that we need to right-shift 100 by 2 bits and for that we have the formula:
	
	p + 1 - n = 2, so after shifting 100 by 2 bits to the right, we have the following result:

	00000000 00000000 00000000 00011001

	we can see that 001 is now the last 3 bits of x;

	now, we will unset all the remaining bits of x except these last 3 bits, so for that
	we have:

	0  -> 00000000 00000000 00000000 00000000

	~0 -> 11111111 11111111 11111111 11111111

	~0 << n  -> 11111111 11111111 11111111 11111000

	~(~0 << n)  -> 00000000 00000000 00000000 00000111

	then we perform bitwise AND operation of this mask with right-shifted x
*/
