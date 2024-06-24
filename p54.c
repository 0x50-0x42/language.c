/*
	Write a version of binSearch() with only one test inside the loop and then measure the difference in the run-time and compare
	with p53.c
*/

#include<stdio.h>

int binSearch(int, int[], int);
int binSearch2(int, int[], int);

int main(void) {

	int arr[] = {7, 9, 12, 15, 21, 35, 110};

	int el;

	printf("enter element to be searched: ");
	scanf("%d", &el);

	int idx = binSearch(el, arr, 7);

	if(idx != -1)
		printf("binSearch()\n%d is at index %d\n", el, idx);
	else
		printf("binSearch()\n%d is not in the array\n", el);
	idx = binSearch2(el, arr, 7);

	if(idx != -1)
		printf("binSearch2()\n%d is at index %d\n", el, idx);
	else
		printf("binSearch2()\n%d is not in the array\n", el);

	return 0;
}

int binSearch(int x, int v[], int n) {
	int low = 0;
	int high = n - 1;

	int mid;

	while(low <= high) {
		mid = (low + high) / 2; // getting the middle element
		
		if(x < v[mid]) // if target is less than middle element of the array
			high = mid - 1; // concentrate on the lower-half of the array
		else if(x > v[mid]) // if target is greater than middle element of the array
			low = mid + 1; // concentrate on the upper-half of the array
		else
			return mid; // return the index
	}

	return -1; // if the element if not found
}

int binSearch2(int x, int v[], int n) {

	int low = 0;
	int high = n - 1;

	int mid = (low + high) / 2;

	while(x != v[mid] && low <= high) {

		if(x > v[mid])
			low = mid + 1;
		else
			high = mid - 1;

		mid = (low + high) / 2;

	}

	if(x == v[mid])
		return mid;

	return -1;
}
