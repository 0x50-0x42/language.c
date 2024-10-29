#include<stdio.h>

void qsort(int*, int, int);
void swap(int*, int, int);

int main(void) {

	int arr[] = {7, 1, 10, 8, 2, 3, 12, 5};

	puts("Initial array:\n");

	for(int i = 0; i < 8; i++)
		printf("%d ", arr[i]);

	printf("\n");

	qsort(arr, 0, 7);

	puts("Final array:\n");

	for(int i = 0; i < 8; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}

void qsort(int*v, int left, int right) {

	if(left >= right) // if array has less than two elements then
		return; // do not proceed further

	int pivotIdx = (left + right) / 2; // pick up the middle element as the pivot point

	swap(v, left, pivotIdx); // swap the pivot with the first element of the array

	int swappedIdx = left + 1; // swap with this index?

	for(int i = left + 1; i <= right; i++) { // start from the second element and compare each one with the pivot
		if(v[i] < v[left]) { // if any element is found to be smaller than the pivot then
			swap(v, i, swappedIdx); // bring it nearer to the pivot
			swappedIdx++;
		}
	}

	swap(v, left, swappedIdx - 1); // swap the pivot with the index whose value was last swapped

	// array has been divided to upper and lower half where lower-half is the sub-array which contains elements < pivot
	// while upper-half is the sub-array which contains elements >= pivot

	qsort(v, left, swappedIdx - 2); // perform the same operations with the lower-half
	qsort(v, swappedIdx, right); // again, perform the same operations with the upper-half
}

void swap(int *v, int i, int j) {
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
