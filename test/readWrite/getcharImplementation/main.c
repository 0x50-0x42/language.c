// Implementation completely taken from K&R2

#include<stdio.h>

int _getchar();

int main(void) {

	int c;

	while((c = _getchar()) != EOF)
		printf("%c", c);

	return 0;
}
