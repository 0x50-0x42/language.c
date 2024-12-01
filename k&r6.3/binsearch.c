#include<stdio.h>
#include<string.h>

int binsearch(char*string, char (*list)[10], int listSize) {
	int low = 0;
	int high = listSize - 1;
	int mid;

	while(low <= high) {
		mid = (low + high) / 2;

		if(strcmp(string, list[mid]) < 0)
			high = mid - 1;
		else if(strcmp(string, list[mid]) > 0)
			low = mid + 1;
		else
			return mid;
	}

	return -1;
}
