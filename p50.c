#include<stdio.h>

int bitcount(unsigned);

int main(void) {
	
	int setBits;
	unsigned x;

	x = 19;

	setBits = bitcount(x);
	printf("Number of set bits in %d: %d\n", x, setBits);

	return 0;
}

int bitcount(unsigned x) {

	int set;

	for(set = 0; x != 0; x >>= 1)
		if(x & 0x01)
			set++;
	return set;
}

/*
	x = 19
	~~~~~~
	00000000 00000000 00000000 00010011

	0x01
	~~~~
	00000000 00000000 00000000 00000001

	x & 0x01
	~~~~~~~~
	00000000 00000000 00000000 00000001

	x = x >> 1
	~~~~~~~~~~
	00000000 00000000 00000000 00001001

	x & 0x01
	~~~~~~~~
	00000000 00000000 00000000 00000001

	x = x >> 1
	~~~~~~~~~~
	00000000 00000000 00000000 00000100

	x & 0x01
	~~~~~~~~
	00000000 00000000 00000000 00000000

	x = x >> 1
	~~~~~~~~~~
	00000000 00000000 00000000 00000010

	x & 0x01
	~~~~~~~~
	00000000 00000000 00000000 00000000

	x = x >> 1
	~~~~~~~~~~
	00000000 00000000 00000000 00000001

	x & 0x01
	~~~~~~~~
	00000000 00000000 00000000 00000001

	x = x >> 1
	~~~~~~~~~~
	00000000 00000000 00000000 00000000

	STOP because x is 0
*/
