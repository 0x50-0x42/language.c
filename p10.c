#include<stdio.h>

int main(void) {

	long nc = 0;

	int c;

	while((c = getchar()) != EOF) {
		++nc;
	}

	printf("Number of characters entered: %ld\n", nc);

	return 0;
}
