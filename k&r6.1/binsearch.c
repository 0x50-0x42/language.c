#include<stdio.h>
#include<string.h>

struct key {
	char*word;
	int count;
};

int binsearch(char *string, struct key* vec, int nkeys) {
	int low = 0;
	int high = nkeys - 1;
	int mid = 0;
	int cond;

	while(low <= high) {
		mid = (low + high) / 2;

		if((cond = strcmp(string, vec[mid].word)) < 0)
			high = mid - 1;
		else if(cond > 0)
			low = mid + 1;
		else
			return mid;
	}

	return -1;
}
