#include<stdio.h>
#include<string.h>

struct key {
	char*word;
	int count;
};

struct key* binsearch(char *string, struct key* vec, int nkeys) {
	struct key* low = vec + 0;
	struct key* high = vec + (nkeys - 1);
	struct key* mid = NULL;
	int cond;

	while(low <= high) {
		mid = low + ((high - low) / 2); // `low' will always point to the address of the first element
					      // in the array (whether it be the upper half or the
					      // lower half

		if((cond = strcmp(string, mid->word)) < 0)
			high = mid - 1;
		else if(cond > 0)
			low = mid + 1;
		else
			return mid;
	}

	return NULL;
}
