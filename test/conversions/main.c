#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int x; // 4 bytes on my system
} sample;

int main(int argc, char **argv) {

	sample a;

	if(argc == 1)
		return 1;

	a.x = atoi(argv[1]);

	unsigned char *b = (char*) &a;

	printf("sizeof(sample): %ld\n", sizeof(a));
	printf("sizeof(char*): %ld\n", sizeof(b));

	for(int i = 0; i < sizeof(int); i++)
		printf("%d ", b[i]);

	printf("\n");
	return 0;
}
