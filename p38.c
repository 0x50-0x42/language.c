// a version of lower() -> converts uppercase to lowercase

#include<stdio.h>
#define LENGTH 1000

int getLine(char[]);
void Lower(char[], int);

int main(void) {
	char line[LENGTH];

	printf("Enter a string: ");

	int len = getLine(line);

	Lower(line, len);

	printf("String after converting it to lowercase: %s\n", line);

	return 0;
}

int getLine(char line[]) {
	int idx = 0, c;

	while((c = getchar()) != EOF && c != '\n' && idx != LENGTH - 1)
		line[idx++] = c;

	line[idx] = '\0';

	return idx;
}

void Lower(char line[], int len) {
	for(int i = 0; line[i] != '\0'; i++)
		if(line[i] >= 'A' && line[i] <= 'Z')
			line[i] = line[i] + 'a' - 'A';     // line[i] += 32; -> this is not platform independent
	
	/* but line[i] = line[i] + 'a' - 'A'; -> this is more platform independent */
}
