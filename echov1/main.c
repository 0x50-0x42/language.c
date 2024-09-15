#include<stdio.h>

int main(int argc, char *argv[]) {

	if(argc == 1) {
		puts("usage: echo [text]");
		return 1;
	}

	char **base = argv;
	argv++;

	while(argv - base < argc) {
		printf("%s", *argv);
		argv++;
	}

	printf("\n");

	return 0;
}
