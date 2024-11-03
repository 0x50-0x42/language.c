#include<stdio.h>
#include<string.h>

#define MAXLEN 1000

unsigned _getline(char*, int);
void *alloc(unsigned);

int readlines(char*(*line)[3], int maxlines, int maxfields) {

	char string[MAXLEN];

	unsigned len;

	int nlines = 0;

	for(; nlines < maxlines; nlines++) {
		printf("String %d:\n", nlines + 1);
		for(int j = 0; j < maxfields; j++) {
			printf("Field %d\n", j + 1);
			len = _getline(string, MAXLEN);

			if(len == EOF) { // if len is EOF then that means we are no longer going to provide inputs
				line[nlines][j] = (char*)alloc(1);
				strcpy(line[nlines][j], string);
				++nlines;
				return nlines;
			}

			if(!len) { // if string has a length of 0, then that means we need to get the the fields of the next string
				line[nlines][j] = (char*)alloc(1);
				strcpy(line[nlines][j], string);
				break;
			}

			line[nlines][j] = (char*)alloc(len);
			strcpy(line[nlines][j], string);
		}
	}

	return nlines;

}
