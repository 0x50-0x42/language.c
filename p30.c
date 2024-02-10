#include<stdio.h>
#define TABSTOP 4  // tabstop occurs after every 4 spaces(one tab = 4 spaces)
#define MAXLINE 1000

int getLine(char[]);
void detab(char[], int);

int main(void) {

	int len;
	char line[MAXLINE];

	len = getLine(line);

	printf("Original string: %s", line);

	printf("Detabbed string: ");
	detab(line, len);


	return 0;
}

int getLine(char line[]) {
	int c, idx = 0;
	while((c = getchar()) != EOF && c != '\n' && idx != MAXLINE - 1) {
		line[idx++] = c;
	}

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

void detab(char line[], int len) {
	for(int i = 0; line[i] != '\0'; i++) {
		if(line[i] == '\t')
			for(int j = 0; j < TABSTOP; j++)
				putchar(' ');
		else
			putchar(line[i]);
	}
}
