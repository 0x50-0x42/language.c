#include<string.h>

#define MAX 1000

unsigned _getline(char*, int);
void*alloc(unsigned);

unsigned readlines(char**lines, int maxlines) {
	char string[MAX];
	unsigned nlines = 0;
	unsigned len;

	while((len = _getline(string, MAX)) != 0 && nlines < maxlines) {
		lines[nlines] = (char*)alloc(len);
		strcpy(lines[nlines], string);
		nlines++;
	}

	return nlines;
}
