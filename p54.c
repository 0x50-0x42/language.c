/*
	Write a version of binSearch() with only one test inside the loop and then measure the difference in the run-time and compare
	with p53.c
*/

#include<stdio.h>

int binSearch(int, int[], int);

int main(void) {

	int arr[] = {7, 9, 12, 15, 21, 35, 110};

	int el;

	printf("enter element to be searched: ");
	scanf("%d", &el);

	int idx = binSearch(el, arr, 7);

	if(idx != -1)
		printf("%d is at index %d\n", el, idx);
	else
		printf("%d is not in the array\n", el);

	return 0;
}

int binSearch(int x, int v[], int n) {

	int low = 0;
	int high = n - 1;

	int idx;

	int mid;

	while(low <= high) {

		mid = (low + high) / 2;

		if(x != v[mid])
			idx = x > v[mid] ? mid + 1 : mid - 1;
		else
			return mid;
	}

	return -1;
}
