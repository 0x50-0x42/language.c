#include<stdio.h>
#include<string.h>

#define MAXCHAR 1000

unsigned _getline(char*, int);
void *alloc(unsigned);

unsigned readlines(int maxfields, char*(*lines)[maxfields], int maxlines) {

	char string[MAXCHAR];

	unsigned len = 0;
	unsigned nlines = 0;

	for(; nlines < maxlines; nlines++) {
		printf("enter string %d\n", nlines + 1);
		for(int i = 0; i < maxfields; i++) {
			printf("enter field %d\n", i + 1);
			len = _getline(string, MAXCHAR);
			if(len == 0) { // move to the next string
				lines[nlines][i] = alloc(1);
				strcpy(lines[nlines][i], string);
				break;
			}

			if(len == EOF) { // we will not take anymore input
				lines[nlines][i] = alloc(1);
				strcpy(lines[nlines][i], string);
				if(i == 0)
					return nlines;
				else
					return ++nlines;
			}

			lines[nlines][i] = alloc(len);
			strcpy(lines[nlines][i], string);
		}
	}

	return nlines;
}
