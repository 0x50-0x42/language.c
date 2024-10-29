#include<string.h>
#include<stdio.h>

void swap(char**, int, int);

void qsort(char**line, int left, int right) {

	if(left >= right)
		return;

	int pivotIdx = (left + right) / 2;

	swap(line, left, pivotIdx);

	int swappedIdx = left + 1;

	for(int i = left + 1; i <= right; i++) {
		if(strcmp(line[i], line[left]) < 0) { // line[i] is less than line[left]
			swap(line, i, swappedIdx);
			swappedIdx++;
		}
	}

	swap(line, left, swappedIdx - 1);
	qsort(line, left, swappedIdx - 2);
	qsort(line, swappedIdx, right);
}
