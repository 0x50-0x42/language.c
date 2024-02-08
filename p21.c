#include<stdio.h>

int main(void) {
	int c;

	int freq[95], idx = 0;

	for(int i = 0; i < 95; i++)
		freq[i] = 0;

	while((c = getchar()) != EOF) {
		++freq[c - 32];
	}

	int ch=32;

	puts("Histogram of frequencies of the characters:");

	for(int i = 0; i < 95; i++) {
		printf("%c|", ch++);
		for(int j=0; j<freq[i]; j++)
			putchar('-');
		printf("\n");
	}

	return 0;
}
