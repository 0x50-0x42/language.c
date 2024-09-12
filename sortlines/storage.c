#include<stdio.h>

#define SPACE 10000

static char mem[SPACE];
static char *memp = mem, *beg = mem;

char *alloc(int reqSpace) {

	if(reqSpace >= 0) { // check if requested space is a positive number

		if(memp - beg == SPACE - 1) {
			puts("free memory unavailable!");
			return NULL;
		}

		if(SPACE - reqSpace >= 0) {
			if(SPACE - (memp - beg) >= reqSpace) {
				if(reqSpace == SPACE) {
					memp += (SPACE - 1);
					return memp - (SPACE - 1);
				}

				else {
					memp += reqSpace;
					return (memp - reqSpace);
				}
			}

		}

		else if(SPACE - reqSpace < 0) {
			puts("Won't allocate, not enough memory!");
			return NULL;
		}
	}

	return NULL;
}

void afree() {
	memp = beg;
}
