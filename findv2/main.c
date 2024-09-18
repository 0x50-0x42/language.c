#include<stdio.h>
#include<string.h>

#define SIZE 1000

int _getline(char*, int);

int main(int argc, char *argv[]) {

	int xclude = 0, line = 0;

	if(argc == 1) {
		puts("Usage: grep [-nx] [pattern]");
		return 1;
	}

	char *found;

	char string[SIZE];

	int len = _getline(string, SIZE);

	// check the options
	int idx = 1;
	while(*argv[idx] == '-') {
		while(*(++argv[idx]) >= 97 && *(argv[idx]) <= 122) { // there could more than one character after the -
			switch(*argv[idx]) {
				case 'n':
					line = 1;
					break;

				case 'x':
					xclude = 1;
					break;
					
				default:
					puts("invalid option");
					return 1;
			}
		}
		idx++;
	}


	int i = 0, countLine = 0, nonId = -1;
	while(i != len) {
		if(strstr(string + i, argv[idx]) != NULL) {
			countLine++;
			if(line) // if the line option is set
				printf("%d ", countLine);
			found = string + i;

			if(!xclude) {
				while(*found != '\0')
					printf("%c", *found++);
				printf("\n");
			}

			i = found - string;
			nonId = ++i;
		}

		else {
			i++;
			if(string[i] == '\0') {
				countLine++; // increment the line once the string reaches NULL character
				if(xclude) {
					if(nonId >= 0) {
						printf("\n%d %s", countLine, string + nonId);
						nonId = -1;
					}
				}
			}
		}
	}

	return 0;
}
