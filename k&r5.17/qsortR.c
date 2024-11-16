#include<stdio.h>
#include<string.h>

void swap(char**, char**, int);

void QsortR(int maxfields, int field, char* (*lines)[maxfields], int left, int right, int (*comp)(void*, void*)) {

	if(left >= right)
		return;

	int pivotIdx = (left + right) / 2;

	swap(lines[left], lines[pivotIdx], maxfields);
	
	int swappedIdx = left + 1;

	for(int i = left + 1; i <= right; i++) {
		if(comp(lines[i][field], lines[left][field]) > 0) {
			swap(lines[i], lines[swappedIdx], maxfields);
			swappedIdx++;
		}
	}

	swap(lines[left], lines[swappedIdx - 1], maxfields);

	QsortR(maxfields, field, lines, left, swappedIdx - 2, comp);
	QsortR(maxfields, field, lines, swappedIdx, right, comp);
}
