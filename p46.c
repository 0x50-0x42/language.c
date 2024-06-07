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

	p + 1 - n is 4 + 1 - 3 which is 2, so x >> 2 basically shifts the last 2 bits of x to the right

	now, after shifting x, that is 100, to the right by 2 bits, extra 2 bits(unset bits i.e. 0s) will be added to the beginning
	of x, now we are focusing on the last 3 bits of x, so that means we need to turn off the remaining bits of x except the last 3 bits
	and for	that we need a mask that does the work

	so, ~0 basically is all ones in binary and shifting it left by 3 bits gives us 3 0s at the end and negating the whole process
	that is (~0 << n) gives us a mask that has the last 3 bits set(that is 1) and the remaining bits are 0

	now, performing a bitwise AND operation between right-shifted x and the mask, gives us only the last 3-bits of x with the
	remaining bits set to 0;
*/
