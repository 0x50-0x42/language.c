#include<stdio.h>

unsigned _getline(char*, int);

int readlines(char*string, int lim) {
	int len = _getline(string, lim);

	if(len == EOF)
		return EOF;
	return len;
}
