#include<stdio.h>
#include<string.h>

#define MAX 1000

unsigned _getline(char*, int);
char* alloc(unsigned);

unsigned readlines(char**lines, int maxlines) {

	char string[MAX];

	unsigned nlines = 0, len;

	while((len = _getline(string, MAX)) != 0) {
		lines[nlines] = alloc(len);
		strcpy(lines[nlines], string);
		nlines++;
	}

	return nlines;
}
