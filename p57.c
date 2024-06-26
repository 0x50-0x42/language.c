/*
	Shell Sort:

	basic idea:
		in early stages, far-apart elements are compared, rather than adjacent ones
		as in simpler interchange sorts;
		the interval between compared elements is gradually decreased to one, at which
		point the sort effectively becomes an adjacent interchange method;

	Note:
		for now, just write this program(as I have not yet studied DSA), don't bother much about it;
*/


#include<stdio.h>

void shellsort(int[], int);

int main(void) {
	
	int arr[] = {4, 1, 10, 7, 6, 3, 5, 2};

	shellsort(arr, 8);

	printf("sorted array is:\n");

	for(int i = 0; i < 8; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}

void shellsort(int v[], int n) {

	int gap;

	for(gap = n / 2; gap > 0; gap /= 2) {
		for(int i = gap; i < n; i++) {
			for(int j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
				int temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
			}
		}
	}
}
