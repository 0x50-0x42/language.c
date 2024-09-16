#include<stdio.h>

#define SIZE 1000

int _getline(char*, int);

int main(int argc, char *argv[]) {

	if(argc == 1) {
		puts("Usage: find [pattern]");
		return 1;
	}


	char *pattern = *(argv + 1); // storing the address of the 1st pointer to char(that's the argument)

	char string[SIZE], *found;

	puts("enter some text:");

	int len = _getline(string, SIZE);

	int i = 0;


	// find the pattern in the given input and output the lines that contain that pattern
	while(string[i] != '\0') {
		if(i == 0 || string[i - 1] == '\n')
			found = string + i;
		while(string[i] == *pattern && *pattern != '\0' && string[i] != '\0')
			i++, pattern++;
		if(*pattern == '\0') {
			while(*found != '\0' && *found != '\n') {
				printf("%c", *found);
				found++;
			}
			printf("\n");
		}

		else
			i++;
		pattern = *(argv + 1);
	}

	return 0;
}
