#include<stdio.h>

#define ALLOCSZ 10000 // available memory space

static int allocbuf[ALLOCSZ]; // memory: private to this source file
static int *allocp = allocbuf; // int *allocp = &allocbuf[0]; also private to this source file

int* alloc(int n) { // allocate storage of n-consecutive spaces

	int *p = allocbuf;

	// size-validity-check!
	if(ALLOCSZ - n > 0) {

		// space-availability-check
		if(allocp - p >= ALLOCSZ - 1) {
			// cannot allocate memory
			puts("not enought memory!!");
			return 0;
		}

		p = allocp;
		allocp += n; // allocp points to memory location after n bytes

		return p;
	}

	puts("requested memory size is too big!");
	return 0;
}

void afree(int *p) {
	allocp = p; // bringing allocp back to the initial address where it was before alloc() was called
}
