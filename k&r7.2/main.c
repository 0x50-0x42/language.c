#include<stdio.h>

inline int _iscntrl(int);

int main(void) {

	puts("your input: ");

	int c;

	while((c = getchar()) != EOF) {
		if(_iscntrl(c))
			printf("%o", c);
		else
			printf("%c", c);
	}

	printf("\n");

	return 0;
}

int _iscntrl(int val) { return val < 32 || val == 127 ? 1 : 0; }
