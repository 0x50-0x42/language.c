#include<stdio.h>

int main(void) {
	int c;

	while((c = getchar()) != EOF) {
		putchar(c);
	}

	printf("EOF = %d\n", c);

	return 0;
}
