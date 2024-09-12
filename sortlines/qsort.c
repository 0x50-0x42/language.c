#include<string.h>

#define __QSRT__
#include "def.h"
#undef __QSRT__

// copied from the book
void qsort(char **lines, int left, int right) {

	int i, last;

	if(left >= right)
		return;
	swap(lines, left, (left + right) / 2);
	last = left;

	for(i = left + 1; i <= right; i++)
		if(strcmp(lines[i], lines[left]) < 0)
			swap(lines, ++last, i);

	swap(lines, left, last);
	qsort(lines, left, last - 1);
	qsort(lines, last + 1, right);
}
