/* Write a program to fold long input lines into two or more shorter lines after the last non-space character that occurs before the n-th column of input.
 * Make sure that your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.
 */

#include<stdio.h>

#define NEWLINE '\n'
#define COL 150    // maximum number of input columns allowed
#define LENGTH 1000

int getLine(char[]);
int length(char[]);
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

	int c, idx = 0, chars = 0;

	while((c = getchar()) != EOF && idx != LENGTH - 1) {
		if(c != ' ' && c != '\t' && c != '\n')
			chars++;
		line[idx++] = c;
	}

	if(idx == 0)
		return -1;

	if(!chars)
		return -1;

	if(c == EOF || idx == LENGTH - 1)
		line[idx] = '\0';


	return idx;
}

int length(char word[]) {
	int len = 0;
	for(int i = 0; word[i] != ' ' && word[i] != '\t' && word[i] != '\0'; i++)
		len++;

	return len;
}

int fold(char line[], int len)  {
	if(len == -1)
		return 0;

	int counter = 0, prev = '\0', idx = 0, strLen = 0;

	for(int i = 0; line[i] != '\0'; i++) {
		if(prev == '\0' || prev == ' ' || prev == '\t') {
			strLen = length(line + i);  // get the length of the word

			// if the sum of counter and length of the string gives us the maximum number of input columns then we will fold
			if(counter + strLen >= COL) {
				putchar(NEWLINE);
				for(int j = i; line[j] != ' ' && line[j] != '\t' && line[j] != '\0'; j++) {
					idx = j;
					putchar(line[j]);
				}
				i = idx;
				counter = 0; // reset the counter
			}

			// if the sum doesn't result in a value greater than or equal to the maximum number of input columns, then simply print
			else {
				putchar(line[i]);
			}
		}

		else {
			putchar(line[i]);
		}

		prev = line[i];

		counter++;
	}

	return 1;
}
