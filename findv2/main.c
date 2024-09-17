#include<stdio.h>

#define SIZE 1000

int main(int argc, char *argv[]) {

	if(argc == 1) {
		puts("Usage: grep [option] [pattern]");
		return 1;
	}

	char string[SIZE];

	int len = _getline(string, SIZE);
	return 0;
}
