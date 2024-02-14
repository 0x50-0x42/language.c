/* Write a program to fold long input lines into two or more shorter lines after the last non-space character that occurs before the n-th column of input.
 * Make sure that your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.
 */

#include<stdio.h>

#define NEWLINE '\n'
#define COL 150    // maximum number of input columns allowed
#define LENGTH 1000

int getLine(char[]);
int fold(char[], int);

int main(void) {

	int chars = 0, c, lines = 0;

	char line[LENGTH];

	int len;

	while((len = getLine(line)) != -1) {
		if(fold(line, len)) {
			++lines;
		}
	}

	printf("\n%d line(s) folded\n", lines);

	return 0;
}

int getLine(char line[]) {

	int c, idx = 0, spaces = 0;

	while((c = getchar()) != EOF && idx != LENGTH - 1) {
		if(c == ' ' || c == '\t')
			spaces++;
		line[idx++] = c;
	}

	if(idx == LENGTH - 1 && spaces == idx)
		return (idx+100);

	if(idx == 0)
		return -1;

	if(c == EOF || idx == LENGTH - 1)
		line[idx] = '\0';

	return idx;
}

int fold(char line[], int len)  {
	for(int i = 0; line[i] != '\0'; i++) {
	}
}
