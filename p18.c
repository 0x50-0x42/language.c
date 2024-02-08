#include<stdio.h>

int main(void) {
	int c, spaces, others;

	int ndigits[10];

	for(int i = 0; i < 10; i++) {
		ndigits[i] = 0;
	}

	spaces = others = 0;

	while((c = getchar()) != EOF) {
		if(c == ' ' || c == '\t' || c == '\n') {
			++spaces;
		}

		else if(c >= '0' && c <= '9') {
			++ndigits[c - '0'];
		}

		else {
			++others;
		}
	}

	printf("Spaces: %d\n", spaces);

	for(int i = 0; i < 10; i++)
		printf("%d: %d\n", i, ndigits[i]);
	
	printf("Others: %d\n", others);

	return 0;
}
