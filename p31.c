#include<stdio.h>

#define TABSIZE 4         // one tab = 4 spaces
#define MAXLINE 1000

int getLine(char[]);
void entab(char[], int);

int main(void) {

	char line[MAXLINE];

	int len;

	len = getLine(line);

	entab(line, len);

	return 0;
}

int getLine(char line[]) {

	int c, idx = 0;

	while((c = getchar()) != EOF && c != '\n' && idx != MAXLINE - 1)
		line[idx++] = c;

	if(idx == MAXLINE - 1) {
		line[idx] = '\0';
		line[idx - 1] = '\n';

		while((c = getchar()) != '\n')
			idx++;

		return idx;
	}

	else if(c == '\n')
		line[idx++] = c;

	line[idx] = '\0';

	return idx;
}

void entab(char line[], int len) {
	int spaces = 0, idx = 0;

	for(int i = 0; line[i] != '\0'; i++) {
		if(line[i] == ' ') {
			for(int j = i; line[j] == ' '; j++) {
				idx = j;
				spaces++;
			}

			i = idx; // moving to the last index which contains a non-space character

			if(spaces % TABSIZE == 0) {   // if the number of spaces is divisible by 4
				for(int k = 0; k < (spaces / TABSIZE); k++)  // quotient times tabs will be displayed!
					putchar('\t');
			}

			else {   // if the number of spaces is not completely divisible by 4
				for(int k = 0; k < (spaces / TABSIZE); k++)  // quotient times tabs will be displayed!
					putchar('\t');
				for(int k = 0; k < (spaces % TABSIZE); k++)  // remainder times whitespaces will be displayed!
					putchar(' ');
			}

			spaces = 0;
		}

		else
			putchar(line[i]);
	}

}
