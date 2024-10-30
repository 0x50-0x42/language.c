#include<stdio.h>

void swap(char**, char**);

void qsortR(char**lines, int left, int right, int (*comp)(void*, void*)) {
	if(left >= right)
		return;

	int pivotIdx = (left + right) / 2;

	swap(lines + left, lines + pivotIdx);

	int swappedIdx = left + 1;

	for(int i = left + 1; i <= right; i++) {
		if(comp(lines[i], lines[left]) > 0) {
			swap(lines + i, lines + swappedIdx);
			swappedIdx++;
		}
	}

	swap(lines + left, lines + (swappedIdx - 1));

	qsortR(lines, left, swappedIdx - 2, comp);
	qsortR(lines, swappedIdx, right, comp);
}
