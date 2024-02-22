#include<stdio.h>

#define LENGTH 1000

int getLine(char[]);
int toDigit(char[], int);

int main(void) {
	int len = 0;
	char line[LENGTH];

	len = getLine(line);

	int num = toDigit(line, len);

	printf("The number is : %d\n", num);

	return 0;
}

int getLine(char line[]) {
	int idx = 0, c;

	while((c = getchar()) != EOF)
		line[idx++] = c;

	line[idx] = '\0';
}

int toDigit(char line[], int len) {

	int num = 0;

	for(int i = 0; line[i] != '\0'; i++)
		if(line[i] >= '0' && line[i] <= '9')
			num = num * 10 + (line[i] - '0');

	return num;
}
