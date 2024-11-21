#include<stdio.h>

void swap(char**, char**);
char *getField(char*, int);

void _qsortR(char **lines, int field, int left, int right, int (*comp)(void*, void*)) {
	if(left >= right)
		return;

	int pivotIdx = (left + right) / 2;

	swap(lines + left, lines + pivotIdx);

	int swappedIdx = left + 1;

	char *fieldLeft = NULL, *fieldElm = NULL;

	fieldLeft = getField(lines[left], field);

	for(int i = left + 1; i <= right; i++) {
		fieldElm = getField(lines[i], field);
		if(comp(fieldElm, fieldLeft) > 0) {
			swap(lines + i, lines + swappedIdx);
			swappedIdx++;
		}
	}

	swap(lines + left, lines + (swappedIdx - 1));

	_qsortR(lines, field, left, swappedIdx - 2, comp);
	_qsortR(lines, field, swappedIdx, right, comp);
}
