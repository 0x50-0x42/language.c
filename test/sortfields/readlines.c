#include<stdio.h>
#include<string.h>

#define MAXLEN 1000

unsigned _getline(char*, int);
void *alloc(unsigned);

unsigned readlines(int maxfields, char* (*line)[maxfields], int maxlines) {

	char string[MAXLEN];

	int nlines = 0;

	unsigned len;

	for(; nlines < maxlines; nlines++) {
		printf("String %d:\n", nlines + 1);
		for(int j = 0; j < maxfields; j++) {
			printf("Field %d:\n", j + 1);
			len = _getline(string, MAXLEN);

			if(len == EOF) {
				line[nlines][j] = (char*)alloc(1);
				strcpy(line[nlines][j], string);
				return ++nlines; // stop taking string input
			}

			if(!len) {
				line[nlines][j] = (char*)alloc(1);
				strcpy(line[nlines][j], string);
				break; // stop taking field input for a particular string and move on to the next string
			}

			line[nlines][j] = (char*)alloc(len);
			strcpy(line[nlines][j], string);
		}
	}

	return nlines;
}
