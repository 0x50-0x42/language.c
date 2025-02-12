#include<stdio.h>
#include<unistd.h>

int main(void) {

	char string[1000];

	// read input from stdin
	int n = read(0, string, 1000); // 0 means stdin

	printf("%d\n", n);

	// display output to stdout
	write(1, string, n); // 1 means stdout

	return 0;
}
