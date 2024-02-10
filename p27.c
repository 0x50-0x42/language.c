#include<stdio.h>
#define MAXLINE 1000

int getLine(char[], int);
int deTrail(char[], int);

int main(void) {

	char line[MAXLINE];

	int len;

	while((len = getLine(line, MAXLINE)) > 0) {
		printf("\nString: %s\nLength: %d\n", line, len);

		len = deTrail(line, len);

		printf("String: %s\nLength: %d\n\n", line, len);
	}

	if(!len) {
		puts("\nNo lines entered!");
		return 0;
	}


	return 0;
}

int getLine(char line[], int maxline) {

	int idx = 0, c, prev;

	while((c = getchar()) != EOF && c != '\n' && idx != maxline - 1)
		line[idx++] = c;

	if(idx == maxline - 1) {
		line[idx] = '\0';
		line[idx - 1] = '\n';

		for(int i = idx - 2; i > idx - 3; i--)
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

int deTrail(char line[], int len) {
	int l = len;
	for(int i = len - 2; line[i] == ' ' || line[i] == '\t'; i--) {
		line[i] = '\n';
		line[i + 1] = '\0';
		l--;
	}

	len = l;

	return len;
}
