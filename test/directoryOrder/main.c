#include<stdio.h>
#include<string.h>

#include "def.h"

#define MAX 1000

int main(void) {

	char *lines[MAXLINES];

	int nlines = 0;

	puts("enter strings:");

	char string[1000];

	unsigned len;

	while((len = _getline(string, 1000)) != 0 && nlines < MAXLINES) {
		lines[nlines] = (char*)alloc(len);
		strcpy(lines[nlines], string);
		nlines++;
	}

	qsort(lines, 0, nlines - 1);

	puts("\nsorted lines:");
	for(int i = 0; i < nlines; i++)
		printf("%s\n", lines[i]);

	for(int i = 0; i < nlines; i++)
		freeMem((void**)lines + i);

	return 0;
}
