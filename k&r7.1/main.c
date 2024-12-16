#include<stdio.h>
#include<string.h>

#include "def.h"

int main(int argc, char **argv) {

	if(strcmp(*argv, "./run") == 0) { // convert to lowercase
		if(argc > 1) {
			for(int i = 1; i < argc; i++)
				for(int j = 0; argv[i][j] != '\0'; j++)
					printf("%c", lower(argv[i][j]));
		}
	}

	else { // convert to uppercase
		if(argc > 1) {
			for(int i = 1; i < argc; i++)
				for(int j = 0; argv[i][j] != '\0'; j++)
					printf("%c", upper(argv[i][j]));
		}
	}

	printf("\n");

	return 0;
}
