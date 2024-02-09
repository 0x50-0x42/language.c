/* We need to print all the input lines that are longer than 80 characters.
 *
 * We will need a function that will return the length of the string entered. Let's name it getLine().
 * This function takes a character array and a maximum length as arguments.
*/


#include<stdio.h>

#define MAXLINE 1000

int getLine(char[], int);

void copy(char[], char[]);

int main(void) {
	char line[MAXLINE], longest[MAXLINE];

	int len;

	while((len = getLine(line, MAXLINE)) > 0) {
		if(len > 80) {
			copy(longest, line);
			printf("%s\n", longest);
		}
	}

	return 0;
}

int getLine(char line[], int maxline) {
	int c, idx = 0;

	while((c = getchar()) != EOF && c != '\n' && idx != maxline - 1) {
		line[idx++] = c;
	}

	if(idx == maxline - 1) {
		line[idx - 1] = '\0';
		line[idx - 2] = '\n';

		for(int i = idx - 3; i > idx - 3; i--)
			line[i] = '.';

		while((c = getchar()) != '\n')
			idx++;

		return idx;
	}

	else if(c == '\n') {
		line[idx++] = c;
	}
	
	line[idx] = '\0';

	return idx;
}

void copy(char to[], char from[]) {

	int idx = 0;
	for(int i = 0; from[i] != '\0'; i++) {
		idx = i;
		to[i] = from[i];
	}

	to[idx + 1] = '\0';
}
