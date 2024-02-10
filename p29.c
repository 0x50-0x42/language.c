#include<stdio.h>

#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

int getLine(void);
void copy(void);

int main(void) {
	int len;
	extern int max;
	extern char longest[];

	max = 0;

	while((len = getLine()) > 0) {
		if(len > max) {
			max = len;
			copy();
		}
	}

	printf("Longest line: %s", longest);

	return 0;
}

int getLine(void) {
	int idx = 0, c;

	extern char line[];

	while((c = getchar()) != EOF && c != '\n' && idx != MAXLINE - 1)
		line[idx++] = c;

	if(idx == MAXLINE - 1) {
		line[idx] = '\0';
		line[idx - 1] = '\n';


		for(int i = idx - 2; i >= idx - 4; i--)
			line[i] = '.';

		while((c = getchar()) != '\n')
			idx++;

		return idx;
	}

	else if(c == '\n')
		line[idx++] = c;

	line[idx] = '\0';

	return idx;
}

void copy(void) {

	extern char line[], longest[];

	int idx;

	for(int i = 0; line[i] != '\0'; i++) {
		idx = i;
		longest[i] = line[i];
	}

	line[idx + 1] = '\n';
	line[idx + 2] = '\0';
}
