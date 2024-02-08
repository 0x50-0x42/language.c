#include<stdio.h>


int main(void) {
	int c, len = 0, idx = 0;

	int length[10];  // let's assume that there are going to be 10 words or less than 10 words in a string

	while((c = getchar()) != EOF) {
		if((c == ' ' || c == '\t' || c == '\n') && len > 0) {
			length[idx++] = len;
			len = 0;
		}

		else if(c != ' ' && c != '\t' && c != '\n')
			++len;
	}

	puts("Histogram:");

	for(int i = 0; i < idx; i++) {
		printf("|");
		for(int j = 0; j < length[i]; j++)
			printf("-");
		printf("\n");
	}

	return 0;
}
