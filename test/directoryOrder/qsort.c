#include<stdio.h>

void swap(char**, char**);
int strdircmp(char*, char*);

void qsort(char**lines, int left, int right) {
	if(left >= right)
		return;

	int pivotIdx = (left + right) / 2;

	swap(lines + left, lines + pivotIdx);

	int swappedIdx = left + 1;

	for(int i = left + 1; i <= right; i++) {
		if(strdircmp(lines[i], lines[left]) < 0) {
			swap(lines + i, lines + swappedIdx);
			swappedIdx++;
		}
	}

	swap(lines + left, lines + (swappedIdx - 1));

	qsort(lines, left, swappedIdx - 2);
	qsort(lines, swappedIdx, right);
}
