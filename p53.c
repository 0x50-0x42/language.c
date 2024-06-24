// Implementing binary search


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
