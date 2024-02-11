#include<stdio.h>

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

int getLine(char[]) {

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
	int spaces = 0;

	for(int i = 0; line[i] != '\0'; i++) {
		if(line[i] == ' ')
			spaces++;

		if(spaces == 1) {        // if there is atleast one whitespace
			for(int j = i; line[j] != '\0'; j++) {        // this loop checks for consecutive whitespaces!
				if(line[j] == ' ')
					spaces++;
				else
					break;
			}
		}
	}

}
