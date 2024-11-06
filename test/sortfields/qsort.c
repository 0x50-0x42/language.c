#include<stdio.h>
#include<string.h>

int swap(int, char*(*)[], char*(*)[]);

void qsort(int maxfields, char*(*line)[maxfields], int left, int right, int fieldNo) {

	if(left >= right)
		return;

	int pivotIdx = (left + right) / 2;

	if(swap(maxfields, line + left, line + pivotIdx) != 1)
		return;

	int swappedIdx = left + 1;

	for(int i = left + 1; i <= right; i++) {
		if(strcmp(line[i][fieldNo], line[left][fieldNo]) < 0) {
			swap(maxfields, line + i, line + swappedIdx);
			swappedIdx++;
		}
	}

	swap(maxfields, line + left, line + (swappedIdx - 1));

	qsort(maxfields, line, left, swappedIdx - 2, fieldNo);
	qsort(maxfields, line, swappedIdx, right, fieldNo);
}
