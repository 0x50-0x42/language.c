#include<stdio.h>
#include<string.h>

#define SIZE 1000

int _getline(char*, int);

int main(int argc, char *argv[]) {

	if(argc == 1) {
		puts("Usage: grep [-nx] [pattern]");
		return 1;
	}

	char string[SIZE];
	
	int xclude = 0, line = 0;

	puts("enter some text:");

	// take text input from user


	int len = _getline(string, SIZE);


	// argument parsing!!
	// evaluate the options/arguments given with the command

	int idx = 1; // because argv + 0 will be the address of the pointer that stores the name of the program
	while(*argv[idx] == '-') {
		while(*(++argv[idx]) >= 97 && *argv[idx] <= 122) {
			switch(*argv[idx]) {
				case 'n':
					line = 1;
					break;

				case 'x':
					xclude = 1;
					break;

				default:
					puts("invalid option!");
					return 1; // stop processing
			}
		}

		idx++;
	}


	// parse the input text for the pattern

	int i = 0, countLine = 0, nonId = -1;

	while(i < len) {

		countLine++;

		if(strstr(string + i, argv[idx]) != NULL) {

			if(!xclude) { // if -x is not available

				if(line) // if -n is available
					printf("%d ", countLine);
				printf("%s\n", string + i);
			}
		}

		else {
			if(xclude) {
				if(line)
					printf("%d ", countLine);
				printf("%s\n", string + i);
			}
		}

		i += strlen(string + i); // always add to i the length of the current string
		++i;
	}

	return 0;
}
