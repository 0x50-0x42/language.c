#include<stdio.h>
#include<string.h>

#define MAXMEM 10000

void *alloc(unsigned);

int main(void) {

	char *line[2][2];

	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
			line[i][j] = (char*)alloc(1000);

	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++)
			printf("%s ", line[i][j]);
		printf("\n");
	}

	strcpy(line[0][0], "hello");
	strcpy(line[0][1], "world");
	strcpy(line[1][0], "world");
	strcpy(line[1][1], "hello");

	char **temp;

	char *(*temp1)[2] = (line + 0);
	char *(*temp2)[2] = (line + 1);

	// can't do that: static arrays in C are unmodifiable!
	temp = *temp1;
	*temp1 = *temp2;
	*temp2 = temp;

	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++)
			printf("%s ", line[i][j]);
		printf("\n");
	}

	return 0;
}

void *alloc(unsigned reqMem) {

	static char mem[MAXMEM];
	
	static char *byte = mem;

	if(reqMem >= MAXMEM)
		return NULL;

	if(MAXMEM - (byte - mem) <= reqMem)
		return NULL;

	void *temp;

	byte += reqMem;

	temp = byte - reqMem;

	byte++;

	return temp;
}
