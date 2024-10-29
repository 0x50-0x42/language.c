#include<stdio.h>

void qsort(int*, int, int);
void swqp(int*, int, int);

int main(void) {

	int arr[] = {7, 1, 10, 8, 2, 3, 12, 5};

	puts("Initial array:\n");

	for(int i = 0; i < 8; i++)
		printf("%d ", arr[i]);

	qort(arr, 0, 7);

	puts("Final array:\n");

	for(int i = 0; i < 8; i++)
		printf("%d ", arr[i]);

	return 0;
}

void qsort(int*v, int left, int right) {

	if(left >= right) // if array has less than two elements then
		return; // do not proceed further

	int pivotIdx = (left + right) / 2; // pickup the middle element as the pivot point

	swap(v, left, pivotIdx); // swap the pivot with the first element of the array

	int swappedIdx = left + 1; // swap with this index?

	for(int i = left + 1; i <= right; i++) { // start from the second element and compare each one with the pivot
		if(v[i] < v[left]) // if any element is found to be smaller than the pivot then
			swap(v, i, swappedIdx); // bring it to nearer to the pivot
		swappedIdx++;
	}

	swap(v, left, pivotIdx);
}
