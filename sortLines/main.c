#include<stdio.h>
#include<string.h>

#include "def.h"

int main(void) {

	puts("enter some strings:");

	char *lines[MAXLINES], line[SIZE];

	unsigned len;

	int lineIdx = 0;

	while((len = _getline(line, SIZE)) != 0) {
		lines[lineIdx] = alloc(len);
		strcpy(lines[lineIdx], line);
		lineIdx++;
	}

	puts("Entered strings:");

	for(int i = 0; i < lineIdx; i++)
		printf("%s\n", lines[i]);

	puts("\nSorted strings:");

	qsort(lines, 0, lineIdx - 1);

	for(int i = 0; i < lineIdx; i++)
		printf("%s\n", lines[i]);

	return 0;
}
