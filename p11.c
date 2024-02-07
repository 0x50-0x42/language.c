#include<stdio.h>

int main(void) {
	long lineCount = 0;
	int c;

	while((c = getchar()) != EOF) {
		if(c == '\n')
			lineCount++;
	}

	printf("Number of lines: %ld\n", lineCount);

	return 0;
}
