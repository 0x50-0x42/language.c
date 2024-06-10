/*
	write a function rightrot(x, n) that returns the value of the integer x rotated to the right by n bit positions;
*/

#include<stdio.h>
#include<limits.h>

unsigned rightrot(unsigned, int);

int main(void) {

	unsigned x, result;
	int n;

	x = 19;
	n = 2;

	result = rightrot(x, n);

	printf("Result: %u\n", result);

	return 0;
}

unsigned rightrot(unsigned x, int n) {

	int d = 8; // assuming x to be an 8-bit number

	return ((x & ~(~0 << n)) << (d-n)) | (x >> n);
}

/*
	n = 2, assuming things for 8-bit numbers, that is, d = 8
	~~~~~

	x = 19
	00000000 00000000 00000000 00010011

	~0 << n
	11111111 11111111 11111111 11111100

	~(~0 << n)
	00000000 00000000 00000000 00000011

	x & ~(~0 << n)
	00000000 00000000 00000000 00000011

	(x & ~(~0 << n)) << (d-n)
	00000000 00000000 00000000 11000000

	x >> n
	00000000 00000000 00000000 00000100

	(x >> n) | ((x & ~(~0 << n)) << (d-n))
	00000000 00000000 00000000 11000100

	CHECK OUT THIS VIDEO:
	https://youtu.be/m_08FbT0_WY?si=-ufDpjDOhPn6_6k0
*/
