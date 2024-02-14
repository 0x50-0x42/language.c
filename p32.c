#include<stdio.h>

#define NEWLINE '\n'
#define COL 150

int main(void) {
	int chars = 0, c;

	while((c = getchar()) != EOF) {

		if(chars == COL) {
		}

		chars++;
	}

	printf("Characters entered: %d\n", chars);

	return 0;
}
