#include<stdio.h>
#include<string.h>

#define MAX 1000

char *alloc(unsigned);

unsigned _getline(char*, int);

unsigned readlines(char **line, int maxlines) {

	int lineNum = 0; // number of lines
	char string[MAX];
	unsigned len;

	while((len = _getline(string, MAX)) != 0 && lineNum < maxlines) {
		line[lineNum] = alloc(len);
		strcpy(line[lineNum], string);
		lineNum++;
	}

	return lineNum;
}
