#include<stdio.h>
#include<string.h>

#define MAXMEM 10000

void *alloc(unsigned);

int main(void) {

	/*
	   if char *line[2] is an array of two pointers-to-char then

	   char *line[2][2] is an array containing two arrays each of which has two
	   pointers-to-char

	   Just like int a[2] is an array of 2 integers and int a[2][2] is an array of
	   two arrays each of which has 2 integers
	 */

	char *line[2][2];

	*(*(line + 0) + 0) = (char*)alloc(1000); // equivalent to line[0][0] = (char*)alloc(1000);
	*(*(line + 0) + 1) = (char*)alloc(1000); // equivalent to line[0][1] = (char*)alloc(1000);

	*(*(line + 1) + 0) = (char*)alloc(1000); // equivalent to line[1][0] = (char*)alloc(1000);
	*(*(line + 1) + 1) = (char*)alloc(1000); // equivalent to line[1][1] = (char*)alloc(1000);

	strcpy(*(*(line + 0) + 0), "hello");
	strcpy(*(*(line + 0) + 1), "world");

	strcpy(*(*(line + 1) + 0), "Good");
	strcpy(*(*(line + 1) + 1), "Bye");

	printf("%s\n", *(*(line + 0) + 0));
	printf("%s\n", *(*(line + 0) + 1));

	printf("%s\n", *(*(line + 1) + 0));
	printf("%s\n", *(*(line + 1) + 1));

	return 0;
}

void *alloc(unsigned reqMem) {


	static char mem[MAXMEM];

	static char*byte = mem;

	if(reqMem >= MAXMEM)
		return NULL;
	if(MAXMEM - (byte - mem) <= reqMem)
		return NULL;

	void* temp;
	byte += reqMem;

	temp = byte - reqMem;
	byte++;

	return temp;
}
