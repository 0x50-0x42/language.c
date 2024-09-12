#include<stdio.h>

#define __MAIN__
#include "def.h"
#undef __MAIN__

int main(void) {

	char *lines[MAXLINES];

	puts("enter strings:");
	for(int i = 0; i < MAXLINES; i++) {
		lines[i] = alloc(SIZE); // allocate memory

		if(lines[i] == NULL) {
			puts("not enough memory, cannot proceed further!!");
			afree();
			return -1;
		}

		_getline(lines[i], SIZE); // take user input
		clearerr(stdin);
	}

	// sort the lines
	puts("\nSorted strings:");
	qsort(lines, 0, MAXLINES - 1);

	writelines(lines);

	afree();

	return 0;
}
