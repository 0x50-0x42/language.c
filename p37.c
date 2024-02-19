// a sample atoi()

#include<stdio.h>
#define LENGTH 1000

int getLine(char[]);
int aToi(char[], int);

int main(void) {
	char line[LENGTH];

	puts("Enter a string: ");
	int len = getLine(line);

	int num = aToi(line, len);

	printf("The number is: %d\n", num);

	return 0;
}

int getLine(char line[]) {
	int idx = 0, c;

	while((c = getchar()) != EOF && c != '\n' && idx != LENGTH - 1)
		line[idx++] = c;

	line[idx] = '\0';

	return idx;
}

int aToi(char line[], int len) {

	int number = 0;

	for(int i = 0; line[i] != '\0'; i++) {
		if(line[i] >= '0' && line[i] <= '9')
			number = number * 10 + (line[i] - '0');
	}

	return number;
}
