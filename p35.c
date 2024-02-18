#include<stdio.h>
#define LENGTH 1000

void getLine(char[]);
int strLen(char[]);

int main(void) {
	char line[LENGTH];

	int len;
	
	puts("Enter a string: ");

	getLine(line);

	len = strLen(line);

	printf("Length of the string is: %d\n", len);

	return 0;
}

void getLine(char line[]) {
	int c, idx = 0;

	while((c = getchar()) != '\n' && idx != LENGTH - 1)
		line[idx++] = c;

	line[idx] = '\0';
}

int strLen(char line[]) {
	int len = 0;
	for(int i = 0; line[i] != '\0'; i++)
		len++;
	return len;
}
